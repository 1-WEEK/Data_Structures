#include <iostream>
#include <cstdio>
using namespace std;

typedef struct treeNode* Tree;
struct treeNode{
    int value;
    Tree left, right;
    bool flag;
};

void resetT(Tree T);
Tree newNode(int v);
Tree CreatTree(int n);
bool judge(Tree T, int n);
bool check(Tree T, int v);
Tree insert(Tree T, int v);

int main()
{
    int n, l, i;
    cin >> n;
    while (n) {
        scanf("%d", &l);
        Tree T = CreatTree(n);
        for (i=0; i<l; ++i) {
            if (judge(T, n)) printf("Yes\n");
            else printf("No\n");
            resetT(T);
        }
        scanf("%d", &n);
    }
    return 0;
}
Tree CreatTree(int n) {
    int i, v;
    Tree T;
    scanf("%d", &v);
    T = newNode(v);
    for (i=1; i<n; ++i) {
        scanf("%d", &v);
        T = insert(T, v);
    }
    return T;
}
Tree insert(Tree T, int v)
{
    if (!T) T = newNode(v);
    else {
        if (v> T->value)
            T->right = insert(T->right, v);
        else
            T->left  = insert(T->left, v);
    }
    return T;
}
Tree newNode(int v)
{
    Tree T = new treeNode;
    T->value = v;
    T->flag = false;
    T->left = T->right = NULL;
    return T;
}
void resetT(Tree T)
{
    if (T->left)  resetT(T->left);
    if (T->right) resetT(T->right);
    T->flag = false;
}
bool check(Tree T, int v)
{
    if (T->flag) {
        if ( v < T->value )
            return check(T->left, v);
        else if ( v > T->value )
            return check(T->right, v);
        else
            return false;
    }
    else {
        if ( v==T->value ) {
            T->flag = true;
            return true;
        }
        else
            return false;
    }
}
bool judge(Tree T, int n)
{
    int i, v;
    bool flag = false;
    scanf("%d", &v);
    if (v!=T->value)
        flag = true;
    else
        T->flag = true;
    for (i=1; i<n; ++i) {
        scanf("%d", &v);
        if (!flag && !check(T, v))
            flag = true;
    }
    if (flag)
        return false;
    else
        return true;
}
