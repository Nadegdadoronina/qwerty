#include <iostream>
using namespace std;
char Sect [(1<<30)+100];
int main ()
{
	FILE *in = fopen("D:\\Надя\\ОС\\plan9", "rb");
	//0x55 0xaa
	char s, p, byte;
	int i = 1, begin;
	
	fscanf(in, "%c", &p);
	Sect[0] = p;
	while (!feof(in))
	{
		fscanf(in,"%c", &s);
		Sect[i] = s;
		++i;
		if(s == char(0xAA) && p == char(0x55))
		{
			if(i >= 512)
			{
				begin = i - 512;
				char filename[50];
				sprintf(filename, "D:\\Надя\\ОС\\file%d", i);
				FILE *out = fopen(filename, "wb");

				for(int j = begin; j < i; ++j)
				{
					byte = Sect[j];
					fprintf(out, "%c", byte);
				}
				 fclose(out);
			}
			
		}
		p = s;
	}
	return 0;
}