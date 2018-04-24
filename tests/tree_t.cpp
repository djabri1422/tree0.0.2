#include <catch.hpp>
#include <sstream>
#include <cassert>
#include "tree_t.hpp"

TEST_CASE("remove"){
	tree_t<int> tree;
	tree.insert(1);
	tree.remove(1);
    
    REQUIRE( tree.return_root() == nullptr );

}
