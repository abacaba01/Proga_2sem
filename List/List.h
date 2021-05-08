#ifndef LIST_LIST_H
#define LIST_LIST_H

template<typename T>
struct Node {
    T data = 0;
    Node *prev = nullptr;
    Node *next = nullptr;
};
template<typename T>
struct List {
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    void PushBack(Node<T> *x){
        x->prev = tail;
        if (tail != nullptr) {
            tail->next = x;
        }
        else{
            head = x;
        }
        tail = x;
    }
    void PushFront(Node<T> *x){
        x->next = head;
        if (head != nullptr){
            head->prev = x;}
        else{
            tail = x;
        }
        head = x;
    }
    void PushMiddle(Node<T> *x, Node<T> *y){
        x->prev = y;
        x->next = y->next;
        y->next->prev = x;
        y->next = x;
    }
    void PopMiddle(Node<T> *x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }
    void PopBack(){
        if (tail->prev != nullptr) {
            tail->prev->next = nullptr;
        }
        tail = tail->prev;
    }
    void PopFront(){
        if (head->next != nullptr) {
            head->next->prev = nullptr;
        }
        head = head->next;
    }


};



#endif //LIST_LIST_H
