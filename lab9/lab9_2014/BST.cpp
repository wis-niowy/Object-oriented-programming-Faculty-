#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BST.h"

using namespace std;

// Tu mozesz dopisac skladowe z klas wyjatkow

BST::BST() : root(NULL) {};

BST::~BST() { free(root); }

void BST::Insert(int v) { insert(&root,v); }

void BST::Show() { show(root,"!"); }

void BST::Remove(int v)
    {
		if(!(Browse(this->root, v) == true))
			throw value_not_found_exception(v);
		
    }

int BST::Find(char *path)
    {
		Node* jumper = root;
		int dlugosc = strlen(path);
		for (int i = 1; i < dlugosc; i++)
		{
			switch (path[i])
			{
			case 'l':
				if (!jumper->left) throw node_not_found_exception(path);
				else jumper = jumper->left;
				break;
			case 'r':
				if (!jumper->right) throw node_not_found_exception(path);
				else jumper = jumper->right;
				break;
			default:
				throw bad_path_exception(path);
			}
		}
    return jumper->val; // zmien
    }

void BST::insert(Node **ptr, int v)
    {
    // dodaj obsluge wyjatku duplicate_value_exception

	
    Node *p;
    p=*ptr;
    if ( !p )
        {
        p= new Node(v);
        *ptr = p;
        return;
        }
    if ( p->val == v && p->deleted )
        {
        p->deleted=false;
        return;
        }
	else if (p->val == v && !(p->deleted)) 
		throw duplicate_value_exception(v);

    if ( p->val > v )
        insert(&(p->left),v);
    else
        insert(&(p->right),v);
    }

void BST::show(Node *ptr, char *path)
    {
		Node* jumper = ptr;
		if (jumper->left)
		{
			char* new_path = new char[strlen(path) + 2];
			strcpy(new_path, path);
			new_path[strlen(path)] = 'l'; new_path[strlen(path) + 1] = '\0';
			show(jumper->left, new_path);
		}

		cout << jumper->val << " : " << path; (jumper->deleted) ? (cout << " - deleted" << endl) : (cout << endl);

		if (jumper->right)
		{
			char* new_path = new char[strlen(path) + 2];
			strcpy(new_path, path);
			new_path[strlen(path)] = 'r'; new_path[strlen(path) + 1] = '\0';
			show(jumper->right, new_path);
		}

    }

void BST::free(Node *ptr)
    {
    if ( ptr==NULL )
        return;
    free(ptr->left);
    free(ptr->right);
    delete ptr;
    }

bool BST::Browse(Node* _root, int _val)
{
	Node *jumper = _root;
	if (jumper->left) // idz jak najbardziej w lewo
	{
		Browse(jumper->left, _val);
	}
	if (jumper->val == _val && !(jumper->deleted))
	{
		jumper->deleted = true;
		return true;
	}
	if (jumper->right) // idz jak najbardziej w prawo
	{
		Browse(jumper->right, _val);
	}
}