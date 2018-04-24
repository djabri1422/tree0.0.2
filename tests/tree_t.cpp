#include <catch.hpp>
#include <sstream>
#include <cassert>
#include "tree_t.hpp"

SCENARIO ("init", "[init]")
{
	tree_t<int> tree;
	tree.insert(2);
	
	REQUIRE(tree.print(std::cout));
}
