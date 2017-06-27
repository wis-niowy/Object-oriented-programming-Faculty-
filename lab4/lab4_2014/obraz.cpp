#include <iostream>
#include <iomanip>
#include "obraz.h"
using namespace std;

// implementacje
obraz::obraz(int row, int col, int grey, int* data): N(row),M(col),Q(grey)
{
	if (data != nullptr)
	for (int i = 0; i < row*col; i++)
	{
		pixelVal[i] = data[i];
	}
}
void obraz::getObrazInfo(int& row, int& col, int& grey) const
{
	row = N;
	col = M;
	grey = Q;
}
int& obraz::operator()(const int x, const int y)
{
	return pixelVal[x * M + y];
}
int obraz::operator()(const int x, const int y) const
{
	return pixelVal[x * M + y];
}

ostream& operator<<(ostream& out, const obraz& im) // czemu nie ma dostepu do M, N, Q ???
{
	//int row, col, grey;
	//im.getObrazInfo(row, col, grey);
	for (int i = 0; i < im.N; i++)
	{

		for (int j = 0; j < im.M; j++)
		{
			out << im(i,j) << " ";
		}
		out << endl;
	}
	return out;
}
obraz::obraz(const obraz& im): N(im.N), M(im.M), Q(im.Q)
{
	for (int i = 0; i < N*M; i++)
	{
		pixelVal[i] = im.pixelVal[i];
	}
}
void obraz::negacjaObrazu()
{
	for (int i = 0; i < M*N; i++)
	{
		pixelVal[i] = (Q - 1) - pixelVal[i];
	}
}
void operator>>=(obraz& im, int i)
{
	for (int j = 0; j < im.M*im.N; j++)
	{
		im.pixelVal[j] >>= i;
	}
}
int* obraz::odbiciePionoweObrazu()
{
	int zwroc[Max_M * Max_N];
	int temp[Max_M][Max_N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			temp[i][j] = pixelVal[i * N + j];
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			zwroc[i * N + j] = temp[i][(M - 1) - j];
		}
	return zwroc;
}
obraz& obraz::operator=(const int* tab)
{
	for (int i = 0; i < M*N; i++)
	{
		pixelVal[i] = tab[i];
	}
	return *this;
}