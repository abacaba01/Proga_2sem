#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <memory>
#include <type_traits>
#include "List.h"


TEST_CASE("Tests all functions of list"){
List<int> a;
Node<int> b,c,d;
b.data = 10;
a.PushFront(&b);
REQUIRE(a.head->data == 10);
c.data = 15;
a.PushBack(&c);
REQUIRE(a.tail->data == 15);
d.data = 17;
REQUIRE(b.next->data == 15);
a.PushMiddle(&d, &b);
REQUIRE(b.next->data == 17);
REQUIRE(c.prev->data == 17);
a.PopMiddle(&d);
REQUIRE(b.next->data == 15);
REQUIRE(c.prev->data == 10);
a.PopFront();
REQUIRE(a.head->data == 15);
a.PushBack(&b);
a.PopBack();
REQUIRE(a.head->data == 15 );

}