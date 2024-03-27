#include "rb.h"
#include <iostream>

// Public methods
RedBlackTree::RedBlackTree() {
    TNULL = new Node(0);
    TNULL->color = BLACK;
    root = TNULL;
}

RedBlackTree::~RedBlackTree() {
    destroyTree(root);
}
void RedBlackTree::insert(int key) {
    Node *node = new Node(key);
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = RED; // new node must be red

    Node *y = nullptr;
    Node *x = this->root;

    // Find the insertion point
    while (x != TNULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // y is parent of x
    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    // If new node is a root node, simply return
    if (node->parent == nullptr) {
        node->color = BLACK;
        return;
    }

    // If the grandparent is null, simply return
    if (node->parent->parent == nullptr) {
        return;
    }

    // Fix the tree
    insertFixUp(node);
}
Node* RedBlackTree::search(int key) const {
    Node* node = this->root;
    while (node != TNULL) {
        if (node->data == key) {
            return node;
        }
        if (key < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return nullptr; // Not found
}

void RedBlackTree::remove(int key) {
    Node *node_to_remove = search(key);
    if (!node_to_remove || node_to_remove == TNULL) {
        return;  // Node not found or tree is empty.
    }

    Node *x, *y;
    y = node_to_remove;
    Color original_color = y->color;
    if (node_to_remove->left == TNULL) {
        x = node_to_remove->right;
        transplant(node_to_remove, node_to_remove->right);
    } else if (node_to_remove->right == TNULL) {
        x = node_to_remove->left;
        transplant(node_to_remove, node_to_remove->left);
    } else {
        y = minimum(node_to_remove->right);
        original_color = y->color;
        x = y->right;
        if (y->parent == node_to_remove) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = node_to_remove->right;
            y->right->parent = y;
        }
        transplant(node_to_remove, y);
        y->left = node_to_remove->left;
        y->left->parent = y;
        y->color = node_to_remove->color;
    }

    delete node_to_remove;

    if (original_color == BLACK) {
        removeFixUp(x);
    }
}

void RedBlackTree::clear() {
    destroyTree(root);
    root = TNULL;
}

// Private methods
void RedBlackTree::initializeNULLNode(Node* node, Node* parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = BLACK;
}

void RedBlackTree::leftRotate(Node *x) {
    Node *y = x->right; // Set y.
    x->right = y->left; // Turn y's left subtree into x's right subtree.

    if (y->left != TNULL) {
        y->left->parent = x; // If y's left subtree is not null, set its parent to x.
    }

    y->parent = x->parent; // Link x's parent to y.

    if (x->parent == nullptr) {
        this->root = y; // If x is the root, set y as the new root.
    } else if (x == x->parent->left) {
        x->parent->left = y; // If x is a left child, set y as the left child of x's parent.
    } else {
        x->parent->right = y; // If x is a right child, set y as the right child of x's parent.
    }

    y->left = x; // Put x on y's left.
    x->parent = y; // Set y as x's parent.
}

void RedBlackTree::rightRotate(Node *y) {
    Node *x = y->left; // Set x.
    y->left = x->right; // Turn x's right subtree into y's left subtree.

    if (x->right != TNULL) {
        x->right->parent = y; // If x's right subtree is not null, set its parent to y.
    }

    x->parent = y->parent; // Link y's parent to x.

    if (y->parent == nullptr) {
        this->root = x; // If y is the root, set x as the new root.
    } else if (y == y->parent->right) {
        y->parent->right = x; // If y is a right child, set x as the right child of y's parent.
    } else {
        y->parent->left = x; // If y is a left child, set x as the left child of y's parent.
    }

    x->right = y; // Put y on x's right.
    y->parent = x; // Set x as y's parent.
}

void RedBlackTree::insertFixUp(Node* k) {
    Node *uncle;
    while (k->parent->color == RED) {
        if (k->parent == k->parent->parent->right) {
            uncle = k->parent->parent->left; // uncle
            if (uncle->color == RED) {
                // case 3.1
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    // case 3.2.2
                    k = k->parent;
                    rightRotate(k);
                }
                // case 3.2.1
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        } else {
            uncle = k->parent->parent->right; // mirror case

            if (uncle->color == RED) {
                // mirror case 3.1
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    // mirror case 3.2.2
                    k = k->parent;
                    leftRotate(k);
                }
                // mirror case 3.2.1
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->color = BLACK;
}

void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

Node* RedBlackTree::minimum(Node* node) const {
    while (node->left != TNULL) {
        node = node->left;
    }
    return node;
}

void RedBlackTree::removeFixUp(Node* x) {
    Node *s;
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == RED) {
                s->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                s = x->parent->right;
            }

            if (s->left->color == BLACK && s->right->color == BLACK) {
                s->color = RED;
                x = x->parent;
            } else {
                if (s->right->color == BLACK) {
                    s->left->color = BLACK;
                    s->color = RED;
                    rightRotate(s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            s = x->parent->left;
            if (s->color == RED) {
                s->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                s = x->parent->left;
            }

            if (s->right->color == BLACK && s->left->color == BLACK) {
                s->color = RED;
                x = x->parent;
            } else {
                if (s->left->color == BLACK) {
                    s->right->color = BLACK;
                    s->color = RED;
                    leftRotate(s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RedBlackTree::deleteNodeHelper(Node* node, int key) {
    Node *z = TNULL;
    Node *x, *y;
    while (node != TNULL) {
        if (node->data == key) {
            z = node;
        }

        if (node->data <= key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (z == TNULL) {
        std::cout << "Key not found in the tree" << std::endl;
        return;
    }

    y = z;
    Color y_original_color = y->color;
    if (z->left == TNULL) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == TNULL) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK) {
        removeFixUp(x);
    }
}

void RedBlackTree::destroyTree(Node* node) {
    if (node == TNULL) {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
void RedBlackTree::printInOrderTraversal() const {
    inOrderHelper(this->root);
    std::cout << std::endl;
}

void RedBlackTree::inOrderHelper(Node* node) const {
    if (node != TNULL) {
        inOrderHelper(node->left);
        std::cout << node->data << " ";
        inOrderHelper(node->right);
    }
}

int RedBlackTree::depth() const {
    return calculateDepth(this->root);
}

int RedBlackTree::calculateDepth(Node* node) const {
    if (node == TNULL) {
        return 0;
    } else {
        int leftDepth = calculateDepth(node->left);
        int rightDepth = calculateDepth(node->right);

        if (leftDepth > rightDepth) {
            return(leftDepth + 1);
        } else {
            return(rightDepth + 1);
        }
    }
}