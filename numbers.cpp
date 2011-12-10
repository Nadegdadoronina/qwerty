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
	
	while ((r = fscanf(in, "%d", &num)) > 0)
	{
		Nums.push_back(num);
	}
	if (r!=EOF)
	{
		cerr<<"Bad file"<<file_name<<endl;
	}
	
}
int main(int args, char*argv [])
{
	for (int i = 1; i < args; ++i)
	{
		files(argv[i]);
	}
	sort(Nums.begin(), Nums.end());
	
	
	for(vector<int>::iterator it = Nums.begin(); it != Nums.end(); ++it)
	{
		cout << *it<<' ';
	}
	return 0;
}
