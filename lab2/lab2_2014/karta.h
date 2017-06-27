
enum KOLOR {
	KIER=3, KARO=4, TREFL=5, PIK=6
};

enum FIGURA {
	B2, B3, B4, B5, B6, B7, B8, B9, B10, J, Q, K, A
};

class karta {
	KOLOR kolor; 
	FIGURA figura;
public:
	
	karta(KOLOR =PIK, FIGURA =A);
	KOLOR getkolor() const { return kolor; };
	FIGURA getfigura() const { return figura; };
	void wypisz() const;

	// jeœli figura, to 10pkt; a za blotkê tylko 1pkt
	int punkty() const;

	// dowolna karta w kolorze czerwonym (kier,karo) jest silniejsza od dowolnej "czarnej" karty
	friend bool operator<(const karta&, const karta&);
	friend bool operator>(const karta&, const karta&);

	// s¹ równe, gdy obie karty s¹ "czarne" lub obie s¹ "czerwone"
	friend bool operator==(const karta&, const karta&);
	
};

