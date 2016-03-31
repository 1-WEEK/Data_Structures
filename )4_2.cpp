#include <iostream>
#include <cstdio>
using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode {
    int val, height;
    Tree right, left;
};

Tree Insert(Tree root, int v);
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

Tree Insert(Tree root, int v)
{
    if (!root) {
        root = new TreeNode;
        root->height = 0;
        root->val = v;
        root->left = root->right = NULL;
    }
    else if (v < root->val) {
        root = insert(root->left,  v);
        
    }
    else if (v > root->val) {
        root = insert(root->right, v);

    }
    root->height = Max(root->left->height, root->right->height) + 1;
    return root;
}
int Max(int a, int b)
{
    return a > b ? a : b;
}
