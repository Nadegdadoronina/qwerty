#include <cstdlib>
//using namespace std;
const int size = 1024;
int A[size][size];
int B[size][size];
int R[size][size];
int main()
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}
	}
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			for(int k = 0; k < size; ++k)
				R[i][j] += A[i][k]*B[k][j];
		}
	}
	return 0;
}