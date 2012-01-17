#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Nums;
void files(char*file_name)
{
	FILE *in = fopen(file_name, "r");
	if (in == NULL) 
	{
		cerr<<"Bad file "<<file_name<<endl;
		return;
	}
	int r, num;

	try
	{
		while ((r = fscanf(in, "%d", &num)) > 0)
		{
			Nums.push_back(num);
		}
	}
	catch(exeption e)
	{
		cerr<<"Error. not enough memory."<<file_name<<endl;
		return;
	}

	if (r!=EOF)
	{
		cerr<<"Bad file "<<file_name<<endl;
		return;
	}
	if (fclose(in))
	{
		cerr<<"Bad file "<<file_name<<endl;
	}
}
int main(int args, char*argv [])
{
	for (int i = 1; i < args; ++i)
	{
		files(argv[i]);
	}
	try
	{
		sort(Nums.begin(), Nums.end());
	}
	catch(exeption e)
	{
		cerr<<"Error! "<<file_name<<endl;
	}
	
	for(vector<int>::iterator it = Nums.begin(); it != Nums.end(); ++it)
	{
		cout << *it<<' ';
	}
	
	return 0;
}
