#ifndef RBT_H
#define RBT_H

#include <cstdlib>
#include <cstddef>

enum Color {
    RED,
    BLACK,
    DOUBLE_BLACK
};

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    explicit Node(int data) : data(data), color(RED), left(NULL), right(NULL), parent(NULL) {}
};

class RedBlackTree {
private:
    Node *root;
    Node *TNULL;

    void initializeNULLNode(Node* node, Node* parent);
    void preOrderHelper(Node* node) const;
    void inOrderHelper(Node* node) const;
    void postOrderHelper(Node* node) const;
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insertFixUp(Node* k);
    void transplant(Node* u, Node* v);
    Node* minimum(Node* node) const;
    void removeFixUp(Node* x);
    void deleteNodeHelper(Node* node, int key);
    void destroyTree(Node* node);
    int calculateDepth(Node* node) const;
    

public:
    RedBlackTree();
    ~RedBlackTree();

    void insert(int key);
    void remove(int key);
    Node* search(int key) const;
    void clear();
    void printInOrderTraversal() const; // Add this line
    int depth() const;
};

#endif // RBT_H