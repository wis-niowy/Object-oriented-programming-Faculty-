#include <iomanip>
#include "hist.h"
using namespace std;

// implementacje
hist::hist(const obraz& im):hist_im(im) {}
bool hist::czy_wykonano_hist() { return wykonano; }
void hist::wykonaj_hist()
{
	for (int i = 0; i < MAX; i++)
	{
		hist_tab[i] = 0;
	}
	int row, col, grey;
	hist_im.getObrazInfo(row, col, grey);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			hist_tab[hist_im(i, j)] += 1;
		}
	wykonano = true;
}
ostream& operator<<(ostream& out, const hist& h)
{
	int row, col, grey;
	h.hist_im.getObrazInfo(row, col, grey);
	for (int i = 0; i < grey; i++)
	{
		out << i << "  " << h.hist_tab[i] << endl;
	}
	return out;
}
obraz hist::wyrownaj_hist()
{
	if (!wykonano) wykonaj_hist();


}

