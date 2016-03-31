#include <iostream>
#include <cstdio>
using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode {
    int val, height;
    Tree right, left;
};

Tree DoubleRightLeftRotation(Tree A);
Tree DoubleLeftRightRotation(Tree A);
Tree SingleRightRotation(Tree A);
Tree SingleLeftRotation(Tree A);
Tree Insert(Tree root, int v);
int getHeight(Tree r);
int Max(int a, int b);

int main()
{
    int n, temp;
    cin >> n;
    Tree root = NULL;
    while (n--) {
        scanf("%d", &temp);
        root = Insert(root, temp);
    }
    if (root) cout << root->val;
    cout << endl;
    return 0;
}
int Max(int a, int b)
{
    return a > b ? a : b;
}
int getHeight(Tree t)
{
    if (t) return t->height;
    else return 0;
}
Tree SingleRightRotation(Tree A)
{
    Tree B = A->right;
    A->right = B->left;
    B->left = A;
    B->height = Max(getHeight(B->right), getHeight(B->left)) + 1;
    A->height = Max(getHeight(A->right), getHeight(A->left)) + 1;
    return B;
}
Tree SingleLeftRotation(Tree A)
{
    Tree B = A->left;
    A->left = B->right;
    B->right = A;
    B->height = Max(getHeight(B->right), getHeight(B->left)) + 1;
    A->height = Max(getHeight(A->right), getHeight(A->left)) + 1;
    return B;
}
Tree DoubleLeftRightRotation(Tree A)
{
    A->left = SingleRightRotation(A->left);
    return SingleLeftRotation(A);
}
Tree DoubleRightLeftRotation(Tree A)
{
    A->right = SingleLeftRotation(A->right);
    return SingleRightRotation(A);
}
Tree Insert(Tree root, int v)
{
    if (!root) {
        root = new TreeNode;
        root->height = 0;
        root->val = v;
        root->left = root->right = NULL;
    }
   else if (v < root->val) {
       root->left = Insert(root->left,  v);
       if ( getHeight(root->left) - getHeight(root->right) == 2) {
           if ( v < root->left->val )
               root = SingleLeftRotation(root);
           else
               root = DoubleLeftRightRotation(root);
       }
   }
   else if (v > root->val) {
       root->right = Insert(root->right, v);
       if ( getHeight(root->right) - getHeight(root->left) == 2) {
           if ( v > root->right->val )
               root = SingleRightRotation(root);
           else
               root = DoubleRightLeftRotation(root);
       }
   }
    root->height = Max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

