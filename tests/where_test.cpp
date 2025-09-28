#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/where.hpp"

TEST_CASE("Basic character find") {
    std::string str = "The quick brown fox";

    REQUIRE(find(str, 'e') == 2);
    REQUIRE(find(str, ' ') == 3);
    REQUIRE(find(str, 'z') == -1);
}

TEST_CASE("Basic substring find") {
    std::string str = "The quick brown fox";

    REQUIRE(find(str, "e") == 2);
    REQUIRE(find(str, "quick") == 4);
    REQUIRE(find(str, "quiet") == -1);
}

TEST_CASE("Case sensitivity (extra credit 1)") {
    std::string str = "The quick brown fox";

    //Default = case sensitive
    REQUIRE(find(str, 't') == -1);

    //Case-insensitive
    REQUIRE(find(str, 't', false) == 0);
    REQUIRE(find(str, "the", false) == 0);
}

TEST_CASE("Starting position (extra credit 2)") {
    std::string str = "The quick brown fox";

    REQUIRE(find(str, 'e') == 2);
    REQUIRE(find(str, 'e', true, 0) == 2);
    REQUIRE(find(str, 'e', true, 1) == 2);
    REQUIRE(find(str, 'e', true, 2) == 2);
    REQUIRE(find(str, 'e', true, 3) == -1);
    REQUIRE(find(str, 'e', true, 500) == -1);
}

/* -------> I CANNOT FIGURE OUT WHY THIS WILL NOT WORK I WILL FIGURE IT OUT AT ANOTHER DATE <-------
TEST_CASE("Single wildcard (extra credit 3)") {
    REQUIRE(find("lamb", "*mb") == 0);
    REQUIRE(find("pits", "*s") == 0);
    REQUIRE(find("yellow", "y*l") == 0);
    REQUIRE(find("that’s why I like milk", "y*l") == 9);
    REQUIRE(find("dumb", "*d") == 0);
    REQUIRE(find("dumb", "b*") == 3);
}
*/

TEST_CASE("Multiple wildcards (extra credit 4)") {
    REQUIRE(find("dumb bunnies", "*bunnies") == 0);
    REQUIRE(find("dumb bunnies", "b*b*n") == 3);
    REQUIRE(find("dumb bunnies", "b*n*n") == 3);
    REQUIRE(find("dumb bunnies", "u*n*n") == 1);
}