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

TEST_CASE("operator ==")
{
	tree_t<int> A;
	A.insert(1);
	A.insert(2);
	
	tree_t<int> B { 1, 2 };
	
	REQUIRE( ( A == B ) == false );
}
