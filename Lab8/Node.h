//
// Created by Gregory Knapp on 5/24/20.
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
        height = 0;
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

            /*
        * Returns the height of this node. The height is the number of nodes
        * along the longest path from this node to a leaf.  While a conventional
        * interface only gives information on the functionality of a class and does
        * not comment on how a class should be implemented, this function has been
        * provided to point you in the right direction for your solution.  For an
        * example on height, see page 448 of the text book.
        *
        * @return the height of this tree with this node as the local root.
        */
    int getHeight() {
        return height;
    }

private:
    int data;
    int height;
    Node* left;
    Node* right;
    friend class AVL;
};


