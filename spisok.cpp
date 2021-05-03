#define CATCH_CONFIG_MAIN
#include "catch.hpp"


struct Node {
    int data = 0;
    Node *prev = nullptr;
    Node *next = nullptr;
};
struct List {
    Node *head = nullptr;
    Node *tail = nullptr;
    void Plus_end(Node *x){
        x->prev = tail;
        if (tail != nullptr) {
            tail->next = x;
        }
        else{
            head = x;
        }
        tail = x;
    }
    void Plus_begin(Node *x){
        x->next = head;
        if (head != nullptr){
            head->prev = x;}
        else{
            tail = x;
        }
        head = x;

    }
    void Plus_middle(Node *x, Node *y){
        x->prev = y;
        x->next = y->next;
        y->next->prev = x;
        y->next = x;
    }
    void Minus_middle(Node *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    void Minus_end(){
        if (tail->prev != nullptr) {
            tail->prev->next = nullptr;
        }
        tail = tail->prev;
    }
    void Minus_begin(){
        if (head->next != nullptr) {
            head->next->prev = nullptr;
        }
        head = head->next;
    }


};

TEST_CASE("ahayo"){
    List a;
    Node b,c,d;
    b.data = 10;
    a.Plus_begin(&b);
    REQUIRE(a.head->data == 10);
    c.data = 15;
    a.Plus_end(&c);
    REQUIRE(a.tail->data == 15);
    d.data = 17;
    REQUIRE(b.next->data == 15);
    a.Plus_middle(&d, &b);
    REQUIRE(b.next->data == 17);
    REQUIRE(c.prev->data == 17);
    a.Minus_middle(&d);
    REQUIRE(b.next->data == 15);
    REQUIRE(c.prev->data == 10);
    a.Minus_begin();
    REQUIRE(a.head->data == 15);
    a.Plus_end(&b);
    a.Minus_end();
    REQUIRE(a.head->data == 15 );

}