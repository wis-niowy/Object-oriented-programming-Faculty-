#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <ostream>

enum color_name
{
	visited,
	not_visited
};

struct node
{
    std::string name;
    color_name color;
	std::list<node*> wskazniki;
};

std::ostream &operator<<(std::ostream &s, const node &n);

class graph
{
	std::vector<node> wezly;
public:
    graph();
    ~graph();

    graph(const graph &g);
    graph &operator=(const graph &g);

    friend std::ostream &operator<<(std::ostream &s, const graph &g);

    void add_node(const std::string &name);
    void add_link(const std::string &from, const std::string &to);
    void visit(const std::string &name) const;
    void del_node(const std::string &name);
};

#endif // GRAPH_H
