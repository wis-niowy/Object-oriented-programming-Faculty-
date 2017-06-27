#include "graph.h"
#include <iostream>

class check_name
{
	std::string nazwa;
public:
	check_name(const std::string& n) {nazwa = n; }
	bool operator()(const node& s1) const
	{
		return s1.name == nazwa;
	}
	bool operator()(const node* s1) const
	{
		return s1->name == nazwa;
	}
};

/////////////////////////////////////////////////

graph::graph()
{
}

graph::~graph()
{
	for (std::vector<node>::iterator it = wezly.begin(); it != wezly.end(); ++it)
	{
		it->wskazniki.clear();
	}
	wezly.clear();
}

graph::graph(const graph &g)
{
	for (std::vector<node>::const_iterator /*it_wez_this = wezly.begin(), */it_wez_g = g.wezly.begin(); it_wez_g != g.wezly.end(); ++it_wez_g)
	{
		node nowy_el;
		nowy_el.name = it_wez_g->name;
		nowy_el.color = it_wez_g->color;
		this->wezly.push_back(nowy_el);
	
		for (std::list<node*>::const_iterator it_wsk_g = it_wez_g->wskazniki.begin(); it_wsk_g != it_wez_g->wskazniki.end(); ++it_wsk_g)
		{
			nowy_el.wskazniki.push_back(*it_wsk_g);
		}
	}
}

graph &graph::operator=(const graph &g)
{
	*this = graph(g);
    return *this;
}

std::ostream &operator<<(std::ostream &s, const graph &g)
{
	for (std::vector<node>::const_iterator it = g.wezly.begin(); it != g.wezly.end(); ++it)
	{
		s << "[" << it->name << ": ";
		if(!it->wskazniki.empty())
		for (std::list<node*>::const_iterator it_w = it->wskazniki.begin(); it_w != it->wskazniki.end(); ++it_w)
		{
			s << (*it_w)->name << " "; // it_w to iterator do wskaznika na node
		}
		s << "]";
	}
	s << std::endl;
	return s;
}

void graph::add_node(const std::string &name)
{
	node nowy_wezel;
	nowy_wezel.name = name;
	nowy_wezel.color = not_visited;
	wezly.push_back(nowy_wezel);
}

void graph::add_link(const std::string &from, const std::string &to)
{   
	std::vector<node>::iterator it_wez = std::find_if(wezly.begin(), wezly.end(), check_name(from)); // znajdz wezel do ktorego dodajesz
	if (!(it_wez == wezly.end()))
	{
		std::list<node*>::iterator it_wsk = std::find_if(it_wez->wskazniki.begin(), it_wez->wskazniki.end(), check_name(to)); // znajdz polaczenie, jesli istnieje
		if (it_wsk == it_wez->wskazniki.end()) // nie znalazlo podobnego powiazania
		{
			std::vector<node>::iterator it_wez_2 = std::find_if(wezly.begin(), wezly.end(), check_name(to)); // znajdz wezel do ktorego prowdzisz polaczenie
			it_wez->wskazniki.push_back(&(*it_wez_2)); // stworz polaczenie z from do to
														// zajebista kombinacja &* !!!!!!!!!!!!
		}
	}
}

void graph::visit(const std::string &name) const
{   
}

void graph::del_node(const std::string &name)
{   
}

std::ostream &operator<<(std::ostream &s, const node &n)
{   
    return s;
}
