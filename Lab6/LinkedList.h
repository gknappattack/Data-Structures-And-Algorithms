//
// Created by Gregory Knapp on 5/17/20.
//

#pragma once
#include <string>
#include "LinkedListInterface.h"
#include <sstream>
#include <exception>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{

public:
    LinkedList() {
        head = nullptr;
        num_items = 0;
    };
    ~LinkedList() {
        while(head != nullptr) {
            Node *current = head;
            head = head->next;
            delete current;
        }
    };

    void insertHead(T value){
        bool dupValue = checkDuplicate(value);

        if (dupValue == false) {
            Node *ptr = head;

            if (head == nullptr) {
                head = new Node(value, nullptr);
                num_items += 1;
            } else {
                head = new Node(value, ptr);
                num_items += 1;
            }
        }
    }

    void insertTail(T value) {
        Node *ptr = head;
        bool dupValue = checkDuplicate(value);


        if (dupValue == false) {
            if (head == nullptr) {
                head = new Node(value, nullptr);
                num_items += 1;
            }
            else {
                while (ptr != nullptr) {
                    if (ptr->next == nullptjr) {
                        ptr->next = new Node(value, nullptr);
                        num_items += 1;
                        break;
                    }
                    else {
                        ptr = ptr->next;
                    }
                }
            }
        }
    }

    void insertAfter(T value, T insertionNode) {
        bool dupValue = checkDuplicate(value);

        if (dupValue == false) {
            for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
                if (ptr->data == insertionNode) {
                    Node *temp = new Node(value, ptr->next);
                    ptr->next = temp;
                    num_items += 1;
                    break;
                } else {
                }
            }
        }
    }

    void remove(T value) {
        bool dupValue = checkDuplicate(value);

        if (dupValue == true) {
            for(Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
                if (head->data == value) {
                    head = ptr->next;
                    delete ptr;
                    num_items = num_items - 1;
                    break;
                }
                else if (ptr->next->data == value) {
                    Node *current = ptr->next;
                    ptr->next = ptr->next->next;
                    delete current;
                    num_items = num_items - 1;
                    break;
                }
            }
        }

    }

    void clear() {
        while(head != nullptr) {
            Node *current = head;
            head = head->next;
            delete current;
            num_items--;
        }
    }

    T at(int index) {
        if (index >= num_items || index < 0) {
                throw std::out_of_range("At Error");
        }

        if (index < num_items) {
            Node* ptr = head;
            for (int i = 0; i <= index; i++) {
                if (i == index) {
                    return (ptr->data);
                }
                else {
                    ptr = ptr->next;
                }
            }
        }
    }

    int size() {
        return num_items;
    }

    string toString() {
        stringstream ss;
        for(Node *ptr = head; ptr != nullptr; ptr = ptr->next){
            if (ptr->next == nullptr) {
                ss << ptr->data;
            }
            else {
                ss << ptr->data << " ";
            }
        }
        return ss.str();
    }

    bool checkDuplicate (T value) {
        bool dupValue = false;
        for(Node *ptr = head; ptr != nullptr; ptr = ptr->next){
            if (ptr->data == value) {
                dupValue = true;
            }
        }
        return dupValue;
    }

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& the_data, Node* next_val = nullptr) :
                data(the_data) {next = next_val;}
    };
    Node *head;
    int num_items;
};