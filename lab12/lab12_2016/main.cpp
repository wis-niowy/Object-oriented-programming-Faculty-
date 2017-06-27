// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "Etapy.h"
#include "KeyEventsManager.h"
using namespace std;

const static char * originalFile = "original.txt";
const static char * textFile = "output.txt";
const static char * binaryFile = "binary.txt";

int main()
{
#if ETAP1 != 1
	cout << "Zacznij prace ustawiajac w pliku Etapy.h wartosc 1 dla kolejnych etapow." << endl;
	return 0;
#else
	cout << "ETAP 1: wczytywanie z pliku original.txt" << endl;
	KeyEventsManager manager;
	manager.readTextFile(originalFile);
	if (!manager.isValid()) {
		cout << "Bledne dane!" << endl;
		return 1;
	}
	cout << "Wczytywanie danych prawdopodobnie OK.\n" << endl;
#endif

#if ETAP2 == 1
	cout << "ETAP 2: wypisywanie zawartosci wczytanego pliku:" << endl;
	if (!manager.isValid()) {
		cout << "ETAP 2: dane niepoprawne!" << endl;
		return 2;
	}
	cout << manager << endl;
#endif

#if ETAP3 == 1
	cout << "ETAP 3: sortowanie wedlug kryterium" << endl;
	manager.sort(KeyEvent::timewiseAscOrder);
	cout << manager;
	cout << "\nNalezy porownac wynik\n";
#endif

#if ETAP4 == 1
	cout << "\nETAP 4: zapis i odczyt z pliku binarnego:" << endl;
	manager.saveBinaryFile(binaryFile);
	KeyEventsManager manager2;
	manager2.loadBinaryFile(binaryFile);
	if (!manager2.isValid() || !manager.equals(manager2)) {
		cout << "Blad ladowania pliku binarnego!" << endl;
		return 3;
	}
	cout << manager2;
	cout << "\n\nNalezy porownac wynik\n" << endl;
#endif

#if ETAP5 == 1
	cout << "ETAP 5: zapis zawartosci do pliku tekstowego" << endl;
	manager2.writeTextFile(textFile);
	manager.readTextFile(textFile);
	if (!manager.isValid() || !manager.equals(manager2)) {
		cout << "ETAP 5: blad!\n" << endl;
		return 5;
	}
	cout << manager2;
	cout << "\nETAP 5: OK, nalezy tez sprawdzic plik " << textFile << endl;
	system("PAUSE");
#endif
}


