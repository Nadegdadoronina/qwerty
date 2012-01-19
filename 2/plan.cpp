#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void BootSector (long pos, FILE* in)
{
	char Buffer[512];
	char filename[50];
	sprintf(filename, "file%ld", pos);

	FILE *out = fopen(filename, "wb");
	if (out == NULL)
	{
		cerr<<"Error fopen."<<endl;
		return;
	}
	
	if (fseek(in, pos, SEEK_SET))
	{
		cerr<<"Error fseek."<<endl;
		return;
	}
		
	if (fread(Buffer, 1, 512, in) != 512)
	{
		cerr<<"Error fread."<<endl;
		return;
	}
	if (fwrite(Buffer, 1, 512, out) != 512)
	{
		cerr<<"Error fwrite."<<endl;
		return;
	}
	if(ferror(out))
	{
		cerr<<"Error fwrite."<<endl;
		return;
	}

	if(fclose(out))
	{
		cerr<<"Error fclose."<<endl;
		return;
	}
}
int main ()
{
	vector <long> Offset; 
	FILE *in = fopen("plan9", "rb");
	if(in == NULL)
	{
		cerr<<"Error fopen."<<endl;
		return 0;
	}
	//0x55 0xaa
	char s, p, byte;
	int i = 1, begin;

	p = fgetc(in);
	if(ferror(in))
	{
		cerr<<"Error fgetc."<<endl;
		return 0;
	}
	try
	{
		while (!feof(in))
		{
			s = fgetc(in);
			if(ferror(in))
			{
				cerr<<"Error fgetc."<<endl;
				return 0;
			}
			++i;
			if(s == char(0xAA) && p == char(0x55))
			{
				if(i >= 512)
				{
					begin = i - 512;
						Offset.push_back(begin);
				}

			}
			p = s;
		}
	}
	catch(exception e)
	{
		cerr<<"Not enougth."<<endl;
		return 0;	
	}
	vector <long> :: iterator it;  
	for(it = Offset.begin(); it < Offset.end(); ++it)
	{
		BootSector(*it, in);
	}
	if(fclose(in))
	{
		cerr<<"Error fclose."<<endl;
	}
	return 0;
}