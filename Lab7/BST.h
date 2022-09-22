//
// Created by Gregory Knapp on 5/20/20.
//

#pragma once

#include "Node.h"
#include "BSTInterface.h"

using namespace std;

class BST : public BSTInterface {
public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        clear();
    }

    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface


    NodeInterface *getRootNode() const {
        return root;
    }

    bool add(int data) {
        bool addedValue = insertValue(root, data);
        if (addedValue) {
            return true;
        }
        else {
            return false;
        }
    }

    bool insertValue(Node*& root, int value) {
        if (root == nullptr) {
            root = new Node(value);
            return true;
        }
        else {
            if (value < root->data) {
                return insertValue(root->left, value);
            }
            else if (value > root->data) {
                return insertValue(root->right, value);
            }
            else {
                return false;
            }
        }
    }


    bool remove(int data) {
        bool eraseSuccess = eraseValue(root, data);
        if (eraseSuccess) {
            return true;
        }
        else {
            return false;
        }
    }

    bool eraseValue(Node*& root, int value) {
        if (root == nullptr) {
            return false;
        }
        else if (value < root->data) {
            bool erased = eraseValue(root->left, value);
            return erased;
        }
        else if (value > root->data) {
            bool erased = eraseValue(root->right, value);
            return erased;
        }
        else {
            if (root->left == nullptr) {
                Node *temp = root;
                root = root->right;
                delete temp;
                return true;
            }
            else if (root->right == nullptr) {
                Node *temp = root;
                root = root->left;
                delete temp;
                return true;
            }
            else {
                bool erased = replace_parent(root, root->left);
                return erased;
            }
        }
    }

    bool replace_parent(Node*& prevRoot, Node*& currRoot) {
        if (currRoot->right != nullptr) {
            replace_parent(prevRoot, currRoot->right);
        }
        else {
            cout << prevRoot->data << " " << currRoot->data << endl;
            prevRoot->data = currRoot->data;
            eraseValue(prevRoot->left, currRoot->data);
            return true;
        }
        return true;
    }


    void clear() {
        cout << "In clear" << endl;
        clearTree(root);

    }

    void clearTree(Node*& root) {
        if (root == nullptr) {
            return;
        }
        clearTree(root->left);
        clearTree(root->right);
        eraseValue(root, root->data);
    }


private:
    Node* root;
};