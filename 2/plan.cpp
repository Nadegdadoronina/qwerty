#include <iostream>
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
	}
	fseek(in, pos, SEEK_SET);
	fread(Buffer, 1, 512, in);
	fwrite(Buffer, 1, 512, out);
	if(ferror(out))
	{
		cerr<<"Error fwrite."<<endl;
	}
	
	if(fclose(out))
	{
		cerr<<"Error fclose."<<endl;
	}
}
int main ()
{
	vector <long> Offset; 
	FILE *in = fopen("plan9", "rb");
	if(in == NULL)
	{
		cerr<<"Error fopen."<<endl;
	}
	//0x55 0xaa
	char s, p, byte;
	int i = 1, begin;
	
	p = fgetc(in);
	while (!feof(in))
	{
		s = fgetc(in);
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
	vector <long> :: iterator it;  
	for(it = Offset.begin(); it < Offset.end(); ++it)
	{

		BootSector(*it, in);
	}
	//fclose(in);
	if(fclose(in))
	{
		cerr<<"Error fclose."<<endl;
	}
	return 0;
}