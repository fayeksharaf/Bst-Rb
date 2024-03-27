#include"bst.h"
#include<iostream>

using namespace std;

bst::bst()
{
    root = NULL;
}

bst::~bst() {
    // Call a recursive function to deallocate all nodes
    destroyTree(root);
}

// Recursive function to deallocate all nodes in the tree
void bst::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->leftC);
        destroyTree(node->rightC);
        delete node;
    }
}


void Insert(TreeNode* &root, int item)
{
    TreeNode* y = NULL;
    TreeNode* x = root;

    // Create a new TreeNode with the given item
    TreeNode* newNode = new TreeNode;
    newNode->info = item;
    newNode->leftC = newNode->rightC = newNode->parent = NULL;

    while (x != NULL)
    {
        y = x;
        if (item < x->info)
        {
            x = x->leftC;
        }
        else
        {
            x = x->rightC;
        }
    }

    newNode->parent = y;

    if (y == NULL)
    {
        root = newNode;
    }
    else if (item < y->info)
    {
        y->leftC = newNode;
    }
    else
    {
        y->rightC = newNode;
    }
}

void bst::InsertItem(int number)
{
    Insert(root, number);
}

int bst::TreeMin(TreeNode* tree)
{
    while(tree->leftC!=NULL)
    {
        tree = tree->leftC;
    }
    return tree->info;
}

int bst::TreeMax(TreeNode* tree)
{
    while(tree->rightC!=NULL)
    {
        tree = tree->rightC;
    }
    return tree->info;
}


void PrintTree(TreeNode* tree)
{
    if (tree != NULL)
    {
        PrintTree(tree->leftC);
        cout << tree->info << ", ";
        PrintTree(tree->rightC);
    }
}

void bst::Print()
{
    PrintTree(root);
}

void bst::Ptreemin()
{
    cout << TreeMin(root)<<endl;
}
void bst::ptreemax()
{
    cout << TreeMax(root) << endl;
}

TreeNode* bst::TreeSearch(TreeNode* tree,int key)
{
    if(tree == NULL || key == tree->info)
    {
        return tree;
    }
    if(key<tree->info)
    {
        return TreeSearch(tree->leftC,key);
    }
    else
    {
        return TreeSearch(tree->rightC,key);
    }
}

void bst::Transplant(bst* tree, TreeNode* u, TreeNode* v)
{
    if(u->parent== NULL)
    {
        tree->root = v;
    }
    else if(u == u->parent->leftC)
    {
        u->parent->leftC = v;
    }
    else
    {
        u->parent->rightC = v;
    }

    if(v!=NULL)
    {
        v->parent = u->parent;
    }
}

void bst::TreeDelete(bst* tree, int a)
{
    TreeNode* z = TreeSearch(tree->root,a);

    if(z->leftC== NULL)
    {
        Transplant(tree,z,z->rightC);
    }
    else if(z->rightC == NULL)
    {
        Transplant(tree,z,z->leftC);
    }
    else
    {
        int y_value = TreeMin(z->rightC);
        TreeNode* y = TreeSearch(z->rightC, y_value);
        if(y->parent!=z)
        {
            Transplant(tree,y,y->rightC);
            y->rightC = z->rightC;
            y->rightC->parent = y;
            Transplant(tree,z,y);
            y->leftC = z->leftC;
            y->leftC->parent = y;
        }
    }
}

void bst::DeleteItem(int item)
{
    TreeDelete(this,item);
}

int bst::depth(TreeNode* tree)
{
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        int ldepth = depth(tree->leftC);
        int rdepth = depth (tree->rightC);

        if(ldepth>rdepth)
        {
            return (ldepth+1);
        }
        else
        {
            return (rdepth+1);
        }
    }
}

void bst::pdepth()
{
    cout << depth(root)<<endl;
}

