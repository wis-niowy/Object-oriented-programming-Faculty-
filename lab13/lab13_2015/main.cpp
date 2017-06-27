#include <iostream>
#include "graph.h"

int main()
{
    // ========== 1
    graph g;
    g.add_node("one");
    g.add_node("two");
    g.add_node("three");
    g.add_node("four");
    g.add_node("five");
    // ========== 2
    std::cout << "2: " << g << std::endl;

    // ========== 3
    g.add_link("one", "two");
    g.add_link("two", "three");
    g.add_link("two", "five");
    g.add_link("one", "four");
    g.add_link("four", "three");
    g.add_link("three", "two");
    g.add_link("none", "three");

    std::cout << "3: " << g << std::endl;

    // ========== 4
	graph h(g);
    std::cout << "4: " << h << std::endl;

    //// ========== 5
    //std::cout << "5 visit: ";
    //h.visit("one");
    //h.visit("missing");

    //// ========== 6
    //h.del_node("two");
    //h.del_node("none");
    //std::cout << "6: " << h << std::endl;

	system("PAUSE");
    return 0;
}
