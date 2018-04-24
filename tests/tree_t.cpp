#include <catch.hpp>
#include <sstream>
#include <cassert>
#include "tree_t.hpp"

SCENARIO ("init", "[init]")
{
  BinaryTree<int> obj;
  REQUIRE(obj.root_() == nullptr);
}
