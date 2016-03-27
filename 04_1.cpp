#include <iostream>
#include <cstdio>
using namespace std;

struct treeNode{
    int value;
    treeNode *left, *right;
    bool flag;
};

treeNode CreatTree(int n);

int main()
{
    int n, l, i;
    cin >> n;
    while (n) {
        scanf("%d", &l);
        treeNode T = CreatTree(n);
        for (i=0; i<l; ++i)
//            check(T);
//        reset(T);
        scanf("%d", &n);
    }
    return 0;
}
treeNode CreatTree(int n) {
    int i;
    for (i=0; i<n; ++i) {
        
    }
    treeNode T;
    return T;
}
