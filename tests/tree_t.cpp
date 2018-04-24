#include <catch.hpp>
#include <sstream>
#include <cassert>
#include "tree_t.hpp"

SCENARIO ("init", "[init]")
{
	tree_t<int> tree{ 1, 2, 3, 4, 5 };
	tree_t<int> tree_{ 1, 2, 3, 4, 5 };
  
  REQUIRE(tree == tree_);
}
