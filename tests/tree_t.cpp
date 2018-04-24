#include <catch.hpp>
#include <sstream>
#include <cassert>
#include "tree_t.hpp"

TEST_CASE("compare"){
    std::ostringstream ostream;
    tree_t<int> tree{10,4,16,2,13,18,3,17};
    tree_t<int> tree1{10,4,16,2,13,18,3,17};
    ostream<<(tree==tree1?"equal\n":"not equal\n");
    tree1.insert(8);
    tree1.insert(9);
    tree1.insert(15);
    ostream<<(tree==tree1?"equal\n":"not equal\n");
    ostream<<(tree.find(13)? "found succesfully\n":"not found\n");
    REQUIRE("equal\nnot equal\nfound succesfully\n"==ostream.str());

}
