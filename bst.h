#ifndef bst_H_INCLUDED
#define bst_H_INCLUDED
#include<iostream>

struct TreeNode{
    int info;
    TreeNode* leftC;
    TreeNode* rightC;
    TreeNode* parent;
};

class bst{

    public:
    bst();
    ~bst();
    void InsertItem(int item);
    void DeleteItem(int item);
    void Print();
    TreeNode* TreeSearch(TreeNode*, int);
    int TreeMin(TreeNode*);
    int TreeMax(TreeNode*);
    void Ptreemin();
    void ptreemax();
    void Transplant(bst*, TreeNode*, TreeNode*);
    void TreeDelete(bst*, int);
    void deleteItem(int item);
    int depth(TreeNode*);
    void pdepth();
    

    private:
    TreeNode* root;
     void destroyTree(TreeNode* node);
    /*node* rootnode;
    void newNode(int);
    void insert(node, int);
    void deleteNode(node,int);
    void search(node,int);
    void minTree(node);
    void maxTree(node);*/
};

#endif