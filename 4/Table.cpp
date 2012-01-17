#include <cstdlib>
//using namespace std;

const int size_pl = 32;
const int cnt_pl = 32;
const int size = size_pl*cnt_pl;
int A[cnt_pl][cnt_pl][size_pl][size_pl];
int B[cnt_pl][cnt_pl][size_pl][size_pl];
int R[cnt_pl][cnt_pl][size_pl][size_pl];
int main()
{

	for (int i = 0; i < cnt_pl; ++i)
	{
		for (int j = 0; j < cnt_pl; ++j)
		{
			for (int x = 0; x < size_pl; ++x)
			{
				for (int y = 0; y < size_pl; ++y)
				{
					A[i][j][x][y] = rand();
					B[i][j][x][y] = rand();
				}
			}
		}
	}

	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			for(int k = 0; k < size; ++k)
				R[i/size_pl][j/size_pl][i%size_pl][j%size_pl] += A[i/size_pl][k/size_pl][i%size_pl][k%size_pl]*B[k/size_pl][j/cnt_pl][k%cnt_pl][j%size_pl];
		}
	}
return 0;
}