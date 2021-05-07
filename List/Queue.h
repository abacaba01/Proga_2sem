#ifndef QUEUE_LIST_CPP_QUEUE_H
#define QUEUE_LIST_CPP_QUEUE_H

#include <iostream>
#include "list.h"

template<typename T>
class Queue{
private:

    List<T> que;
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    std::size_t size_{0};

public:
    Queue() {}
    Queue(const Queue& other) : size_{other.size_} {
        if (this == &other) {
            return;
        }
        Node<T> *other_help = other.head;
        Node<T> *help = new Node<T>;
        help->prev = nullptr;
        head = help;
        if (size_ == 1) {
            head->next = nullptr;
            head->data = other_help->data;
            tail = head;
            return;
        }
        for (int i = 0; i < other.size_; ++i, other_help = other_help->next) {
            Node<T> *new_node = new Node<T>;
            help->next = new_node;
            new_node->prev = help;
            help->data = other_help->data;
            if (i != other.size_ - 1) help = new_node;
        }
        delete help->next;
        help->next = nullptr;
        tail = help;
    }

    Queue(Queue&& other) {
        size_ = std::move(other.size_);
        Node<T> *other_help = other.head;
        Node<T> *help = new Node<T>;
        help->prev = nullptr;
        head = help;
        if (size_ == 1) {
            head->next = nullptr;
            head->data = std::move(other_help->data);
            tail = head;
            return;
        }
        for (int i = 0; i < other.size_; ++i, other_help = other_help->next) {
            Node<T> *new_node = new Node<T>;
            help->next = new_node;
            new_node->prev = help;
            help->data = std::move(other_help->data);
            if (i != other.size_ - 1) help = new_node;
        }
        delete help->next;
        help->next = nullptr;
        tail = help;
    }

    void Push(const int& elem) {
        Node<T> *nod = new Node<T>;
        nod->data = elem;
        que.plus_end(nod);
        if (head == nullptr) {
            head = nod;
            tail = nod;
        } else {
            tail = nod;
        }
        ++size_;
    }

    T& Back() {
        Node<T> *help = head;
        while (help != tail) help = help->next;
        return help->data;
    }

    T& Front() {
        return head->data;
    }

    bool Empty() const {
        return head == nullptr;
    }

    void Pop() {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            delete head->prev;
        }
        --size_;
    }

    Queue& operator= (const Queue& other) {
        if (this == &other) {
            return *this;
        }
        size_ = other.size_;
        if (head != nullptr) {
            while (head != tail) {
                head = head->next;
                delete head->prev;
            }
            delete tail;
        }
        Node<T> *other_help = other.head;
        Node<T> *help = new Node<T>;
        help->prev = nullptr;
        head = help;
        if (size_ == 1) {
            head->next = nullptr;
            head->data = other_help->data;
            tail = head;
            return *this;
        }
        for (int i = 0; i < other.size_; ++i, other_help = other_help->next) {
            Node<T> *new_node = new Node<T>;
            help->next = new_node;
            new_node->prev = help;
            help->data = other_help->data;
            if (i != other.size_ - 1) help = new_node;
        }
        delete help->next;
        help->next = nullptr;
        tail = help;
        return *this;
    }

    Queue& operator= (const Queue&& other) {
        if (this == &other) {
            return *this;
        }
        size_ = std::move(other.size_);
        if (head != nullptr) {
            while (head != tail) {
                head = head->next;
                delete head->prev;
            }
            delete tail;
        }
        Node<T> *other_help = other.head;
        Node<T> *help = new Node<T>;
        help->prev = nullptr;
        head = help;
        if (size_ == 1) {
            head->next = nullptr;
            head->data = std::move(other_help->data);
            tail = head;
            return *this;
        }
        for (int i = 0; i < other.size_; ++i, other_help = other_help->next) {
            Node<T> *new_node = new Node<T>;
            help->next = new_node;
            new_node->prev = help;
            help->data = std::move(other_help->data);
            if (i != other.size_ - 1) help = new_node;
        }
        delete help->next;
        help->next = nullptr;
        tail = help;
        return *this;
    }

    std::size_t Size() const {
        return size_;
    }
};



#endif //QUEUE_LIST_CPP_QUEUE_H
