//
// Created by Gregory Knapp on 5/24/20.
//


#pragma once

#include "Node.h"
#include "AVLInterface.h"
#include <algorithm>

using namespace std;

class AVL : public AVLInterface {
public:
    AVL() {
        root = nullptr;
    }

    ~AVL() {
        clearTree(root);
    }

    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface


    NodeInterface *getRootNode() const {
        return root;
    }

    bool add(int data) {
        cout << "In add: " << data << endl;
        bool addedValue = insertValue(root, data);
        if (addedValue) {
            printTree(root);
            cout << endl;
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
                bool isAdded = insertValue(root->left, value);
                if (isAdded) {
                    rebalance(root);
                }
                return isAdded;
            }
            else if (value > root->data) {
                bool isAdded = insertValue(root->right, value);
                if (isAdded) {
                    rebalance(root);
                }
                return isAdded;
            }
            else if (root->data == value) {
                return false;
            }
        }
        return false;
    }


    bool remove(int data) {
        cout << "In Remove: " << data << endl;
        bool eraseSuccess = eraseValue(root, data);
        if (eraseSuccess) {
            printTree(root);
            cout << endl;
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
            if (erased) {
                rebalance(root);
            }
            return erased;
        }
        else if (value > root->data) {
            bool erased = eraseValue(root->right, value);
            if (erased) {
                rebalance(root);
            }
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
                if (erased) {
                    rebalance(root);
                }
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

    void rotateLeft(Node*& n) { //Parent = parent node of n, n = out of balance node
        Node* temp = n;
        n = n->right; // Set pointer to n to point to k
        temp->right = n->left; // Set n's right to point to k's left
        n->left = temp; // Set k's left to point to n
    }
    void rotateRight(Node*& n) {
        Node* temp = n; //Set temp = k (the left child of n)
        n = n->left;
        temp->left = n->right;
        n->right = temp;
    }
    void rebalance(Node*& n) {

        int balance = getBalance(n);

        cout << "Value: " << n->data << " - Balance: " << balance << endl;

        if (balance == 2) {
            int rightBalance = getBalance(n->right);
            if (rightBalance == -1) {
                cout << "Found an RL Tree" << endl;
                rotateRight(n->right);
                rotateLeft(n);
            }
            else {
                cout << "Found an RR Tree" << endl;
                rotateLeft(n);
            }
        }
        else if (balance == -2) {
            int leftBalance = getBalance(n->left);
            if (leftBalance == 1) {
                cout << "Found an LR Tree" << endl;
                rotateLeft(n->left);
                rotateRight(n);
            }
            else {
                cout << "Found an LL Tree" << endl;
                rotateRight(n);
            }
        }
        else {
            cout << "No tree to rebalance" << endl;
        }
    }

    int height (Node* u) {
        int h = 0;
        if (u != nullptr) {
            int leftHeight = height(u->left);
            int rightHeight = height(u->right);
            int maxHeight = max(leftHeight, rightHeight);
            h = maxHeight + 1;
        }
        return h;
    }

    int getBalance(Node* u) {
        int leftHeight = height(u->left);
        int rightHeight = height(u->right);
        return rightHeight - leftHeight;
    }


    void printTree(Node* u) {
        if (u == nullptr) {
            return;
        }
        cout << u->data << ","; //output node value
        printTree(u->left);
        printTree(u->right);
    }


private:
    Node* root;
};
