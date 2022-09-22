//
// Created by Gregory Knapp on 5/20/20.
//

#pragma once

#include <iostream>
#include "NodeInterface.h"

using namespace std;

class Node : public NodeInterface {

public:
    Node(int value) {
        left = nullptr;
        right = nullptr;
        data = value;
    }
    ~Node() {}

    /*
    * Returns the data that is stored in this node
    *
    * @return the data that is stored in this node.
    */
    int getData() const {
        return data;
    }

    /*
    * Returns the left child of this node or null if it doesn't have one.
    *
    * @return the left child of this node or null if it doesn't have one.
    */
    NodeInterface* getLeftChild() const {
        if (left == nullptr) {
            return nullptr;
        }

        return left;
    }

    /*
    * Returns the right child of this node or null if it doesn't have one.
    *
    * @return the right child of this node or null if it doesn't have one.
    */
    NodeInterface * getRightChild() const {
        if (right == nullptr) {
            return nullptr;
        }

        return right;
    }

private:
    int data;
    Node* left;
    Node* right;
    friend class BST;
};