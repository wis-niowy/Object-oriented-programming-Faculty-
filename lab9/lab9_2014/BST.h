
#include <exception>

using namespace std;

struct Node
    {
    int val;
    bool deleted;
    Node *left;
    Node *right;
    Node(int v) : val(v), deleted(false), left(NULL), right(NULL) {}
    };

class BST
    {
     private:
        Node *root;
        static void insert(Node **ptr, int v);
        static void show(Node *ptr,char *p);
        static void free(Node *ptr);
	public:
        BST();
        ~BST();
        void Insert(int v);
        void Remove(int v);
        int Find(char *path);
        void Show();
   
		bool Browse(Node* , int); // szuka leementu o daej wart. i usuwa go
    };

// tu dopisz definicje klas wyjatkow
// value_exception, duplicate_value_exception, value_not_found_exception,
// path_exception, node_not_found_exception i bad_path_exception

class value_exception : public exception
{
		int except_value;
	public:
		value_exception(int v) : except_value(v) {};		// konstruktor
		int get_except_value() const { return except_value; }
		virtual void komunikat() const = 0;
		virtual ~value_exception() {};
};

class duplicate_value_exception : public value_exception
{
	public:
		duplicate_value_exception(int exc): value_exception(exc) {};

		virtual void komunikat() const {
			cout << "Blad! Podana wartosc juz jest w drzewie! Wart: " << this->get_except_value() << endl;
			};
};

class value_not_found_exception : public value_exception
{
	public:
		value_not_found_exception(int exc): value_exception(exc) {};

		virtual void komunikat() const {
			cout << "Blad! Szukana wartosc nie znajduje sie w drzewie! Wart: " << this->get_except_value() << endl;
		};
};

/////////////////////////////////////////////////////////////

class  path_exception : public exception
{
		char* except_path;
	public:
		path_exception(const char* _path) {			//konstruktor
			except_path = new char[strlen(_path) + 1];
			strcpy(except_path, _path);
			};
		char* get_except_path() const { return except_path; };
		virtual void komunikat() const = 0;
		virtual ~path_exception() {};
};

class node_not_found_exception : public path_exception
{
	public:
		node_not_found_exception(const char* _path): path_exception(_path) {};
		virtual void komunikat() const {
			cout << "Blad! Nie znalezniono wezla! Sciezka: " << this->get_except_path() << endl;
			};
};

class bad_path_exception : public path_exception
{
	public:
		bad_path_exception(const char* _path): path_exception(_path) {};
		virtual void komunikat() const {
			cout << "Blad! Nieprawidlowa sciezka! Sciezka: " << this->get_except_path() << endl;
			};
};
