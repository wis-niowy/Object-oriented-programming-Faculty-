
#include "hist.h"

using namespace std;

int main()
{
	int image_data[] = { 1,2,3,4,5,6, 1,2,3,4,5,6, 1,2,3,4,5,6, 1,2,3,4,5,6, 1,2,3,4,5,6, 1,2,3,4,5,6 };

	obraz im(6, 6, 16, image_data); //nowy obrazek
	cout << "Obrazek (im): " << endl;
	cout<<im; //wypisz na ekran

	int numRows, numCols, grayVal;
	im.getObrazInfo(numRows, numCols, grayVal);
	cout << "Liczba wierszy: " << numRows << ", kolumn: " << numCols << ", odcieni szarosci: " << grayVal << endl << endl;

	im(1,1)=8;
	cout << "piksel  (1,1) to: " << im(1,1) << endl << endl;

	obraz im_copy(im); // kopia
	cout << "Obrazek kopia(im_copy): " << endl; 
	cout<<im_copy;

	im_copy>>=1; // przesuniecie bitowe w prawo
	cout << "Przesuniecie bitowe (im_copy) w prawo o 1:" << endl;
	cout<<im_copy;

	im_copy.negacjaObrazu(); // negacja
	cout << "Negacja obrazu (im_copy):" << endl;
	cout<<im_copy;

	obraz im1(numRows, numCols, grayVal);
	im1 = im.odbiciePionoweObrazu(); // odbij pionowo
	cout << "Odbicie pionowe (im):" << endl;
	cout<<im1;

	cout << "Obrazek (im): " << endl;
	cout<<im; //wypisz na ekran
	hist h_im(im); // utworzenie obiektu histogramu dla obrazka im
	h_im.wykonaj_hist(); // policzenie histogramu
	cout << "Histogram obrazka (im):" << endl;
	cout << h_im; // wypisanie histogramu

	//obraz im_eq(numRows, numCols, grayVal);
	//im_eq = h_im.wyrownaj_hist(); // wyrownanie histogramu - zwraca obrazek z wyrownanym histogramem
	//cout << "Obrazek (im) po wyrownaniu:" << endl;
	//cout<<im_eq;

	//hist h_im_eq(im_eq); // utworzenie obiektu histogramu dla obrazka im_eq (im po wyrownaniu histogramu)
	//h_im_eq.wykonaj_hist(); // policzenie histogramu
	//cout << "Histogram obrazka (im_eq):" << endl;
	//cout << h_im_eq; // // wypisanie histogramu (wyrownanego)
	system("PAUSE");
}
