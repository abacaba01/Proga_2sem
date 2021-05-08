#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <memory>
#include <type_traits>
#include "Vector.h"

TEST_CASE() {
    Vector<int> tested;

    for (int i = 0; i < 5; i++) {
        tested.PushBack(i);
    }

    Vector<int> one_more_tested;
    one_more_tested = tested;

    REQUIRE(one_more_tested[0] == 0);
    REQUIRE(one_more_tested[1] == 1);
    REQUIRE(one_more_tested[2] == 2);
    REQUIRE(one_more_tested[3] == 3);
    REQUIRE(one_more_tested[4] == 4);
    REQUIRE(one_more_tested.Size() == 5);

    tested.PopBack();

    REQUIRE(tested[0] == 0);
    REQUIRE(tested[1] == 1);
    REQUIRE(tested[2] == 2);
    REQUIRE(tested[3] == 3);
    REQUIRE(tested.Size() == 4);
}


 TEST_CASE() {
    Vector<int> tested;
    for (int i = 0; i < 5; i++) {
        tested.PushBack(i);
    }

    Vector<int> moved_tested(std::move(tested));
    REQUIRE(moved_tested[0] == 0);
    REQUIRE(moved_tested[1] == 1);
    REQUIRE(moved_tested[2] == 2);
    REQUIRE(moved_tested[3] == 3);
    REQUIRE(moved_tested[4] == 4);
    REQUIRE(moved_tested.Size() == 5);

    Vector<int> asgn_mv_tested;
    asgn_mv_tested = std::move(moved_tested);
    REQUIRE(asgn_mv_tested[0] == 0);
    REQUIRE(asgn_mv_tested[1] == 1);
    REQUIRE(asgn_mv_tested[2] == 2);
    REQUIRE(asgn_mv_tested[3] == 3);
    REQUIRE(asgn_mv_tested[4] == 4);
    REQUIRE(asgn_mv_tested.Size() == 5);
}
