#include "Etapy.h"
#include "Kontener.h"
#include "KryteriaSortowania.h"
#include <iostream>
#include <ctime>

using namespace std;

#if ETAP_1 == 1
bool test1() {
#if ETAP_2 == 1
	Kontener<double> k;
#else
	Kontener k;
#endif
	k.push_back(5);
	if (k.size() != 1) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	if (k.get(0) != 5) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	k.push_back(6.0);
	k.push_back(8.3);
	if (k.get(2) != 8.3) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	if (k.size() != 3) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	k.pop_front();
	if (k.get(1) != 8.3) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	if (k.size() != 2) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	k.push_back(2);
	k.wyczysc();
	if (k.size() > 0) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	if (k.size() > 0) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	for (double i = 0; i < 12; ++i) {
		k.push_back(i);
	}
	if (k.size() != 12) {
		cout << "niepoprawna wartosc" << endl;
		return false;
	}
	for (double i = 0; i < 12; ++i) {
		if (k.get((int)i) != i) {
			cout << "niepoprawna wartosc: " << i << endl;
			return false;
		}
	}
	return true;
}
#endif

#if ETAP_2 == 1
bool test2() {
	int i = 0;
	double d = 6.0;
	float f = (float)7.3;
	bool b = true;
	
	Kontener<int> kInt;
	kInt.push_back(i);
	kInt.push_back((int)d);
	kInt.push_back((int)f);
	kInt.push_back(b);

	Kontener<double, 3> kDouble;
	kDouble.push_back(i);
	kDouble.push_back(d);
	kDouble.push_back(f);
	kDouble.push_back(b);

	Kontener<float> kFloat;
	kFloat.push_back((float)i);
	kFloat.push_back((float)d);
	kFloat.push_back(f);
	kFloat.push_back(b);

	Kontener<bool, 2> kBool;
	kBool.push_back(!i);
	kBool.push_back(true);
	kBool.push_back(false);
	kBool.push_back(b);

	Kontener<char, 8> kChar;
	kChar.push_back(i);
	kChar.push_back((char)d);
	kChar.push_back((char)f);
	kChar.push_back(b);

	return true;
}
#endif

#if ETAP_3 == 1
bool test3() {
	Kontener<int> k;
	try {
		k.get(0);
	}
	catch (const KontenerUninitializedException &e) {
		cout << e.info() << endl;
		cout << "Wyjatek KontenerUninitializedException wywolany poprawnie \n" << endl;
	}
	catch (const KontenerEmptyException &e) {
		cout << e.info() << endl;
		cout << "KontenerUninitializedException exception was expected" << endl;
		return false;
	}
	catch (const KontenerException &e) {
		cout << e.info() << endl;
		return false;
	}
	k.push_back(1);
	try {
		k.pop_front();
	}
	catch (const KontenerException &e) {
		cout << e.info() << endl;
		cout << "niepoprawny wyjatek" << endl;
		return false;
	}
	try {
		k.pop_front();
	}
	catch (const KontenerEmptyException &e) {
		cout << e.info() << endl;
		cout << "Wyjatek KontenerEmptyException wywolany poprawnie \n" << endl;
	}
	catch (const KontenerException &e) {
		cout << e.info() << endl;
		cout << "Powinien wystapic wyjatek: KontenerEmptyException" << endl;
		return false;
	}
	try {
		k.get(0);
	}
	catch (const KontenerIndexOutOfBoundsException &e) {
		cout << e.info() << endl;
		cout << "Poprawnie wywolany wyjatek KontenerIndexOutOfBoundsException\n" << endl;
		return true;
	}
	catch (const KontenerException &e) {
		cout << e.info() << endl;
		cout << "Niepoprawny typ wyj¹tku" << endl;
		return false;
	}
	cout << "niepoprawne zachowanie" << endl;
	return false;
}
#endif

#if ETAP_4 == 1
void test4() {
	Kontener<int> k;
	for (int i = 1; i <= 10; ++i) {
		k.push_back(i);
	}
	cout << "Tablica int od 1 do 10" << endl << k;
}
#endif

#if ETAP_5 == 1
bool test5() {
	srand(0);
	Kontener<int> kMalejaco;
	Kontener<int> kRosnaco;
	int tabSize = 28;
	for (int i = 0; i < tabSize; ++i) {
		kMalejaco.push_back(rand() % tabSize + 1);
		kRosnaco.push_back(rand() % tabSize + 1);
	}
	cout << "Zawartosc tablicy 1: " << endl << kMalejaco << flush;
	cout << "Zawartosc tablicy 2: " << endl << kRosnaco << flush;
	kMalejaco.sortuj(malejaco);
	kRosnaco.sortuj(rosnaco);
	cout << "Tablica po sortowaniu malejaco: " << endl << kMalejaco;
	cout << "Tablica po sortowaniu rosnaco: " << endl << kRosnaco;
	int lastDesc = 0;
	int lastAsc = 0;
	for (int i = 0; i < tabSize; ++i) {
		if (i == 0) {
			lastDesc = kMalejaco.get(i);
			lastAsc = kRosnaco.get(i);
			continue;
		}
		if (lastDesc > kMalejaco.get(i)) {
			lastDesc = kMalejaco.get(i);
		} else if (lastDesc < kMalejaco.get(i)) {
			cout << "BLAD! Tablica nie jest posortowana malej¹co:" << endl;
			return false;
		}
		if (lastAsc < kRosnaco.get(i)) {
			lastAsc = kRosnaco.get(i);
		} else if (lastAsc > kRosnaco.get(i)) {
			cout << "BLAD! Tablica nie jest posortowana rosn¹co:" << endl;
			return false;
		}
		
	}
	return true;
}
#endif

void main()
{
#if ETAP_1 == 1
	cout << "ETAP 1 start" << endl;
	if (!test1()) {
		cout << "Test 1 niepoprawny"  << endl;
		return;
	}
	cout << "Test 1 OK\n\n";
#else
	cout << "\nUstaw wartosc ETAP_1 = 1 w Etapy.h, aby rozpoczac...\n\n";
#endif

#if ETAP_2 == 1
	cout << "ETAP 2 start" << endl;
	if (!test2()) {
		cout << "Test 2 niepoprawny" << endl;
		return;
	}
	cout << "Test 2 OK\n\n";
#endif

#if ETAP_3 == 1
	cout << "ETAP 3 start" << endl;
	if (!test3()) {
		cout << "Test 3 niepoprawny" << endl;
		return;
	}
	cout << "Test 3 OK\n\n";
#endif

#if ETAP_4 == 1
	cout << "ETAP 4 start" << endl;
	test4();
	cout << "Jesli tablica sie wypisuje poprawnie (od 1 do 10), jest OK.\n\n";
#endif

#if ETAP_5 == 1
	cout << "ETAP 5 start" << endl;
	if (!test5()) {
		cout << endl << "Test 5 niepoprawny" << endl;
		return;
	}
	cout << "Test 5 OK\n\n";
#endif

	system("PAUSE");
}