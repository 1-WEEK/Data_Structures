#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cctype>
using namespace std;
struct TreeNode {
    char ch;
    int r, l;
    bool isRoot;
};

vector<TreeNode> trA, trB;

void input(vector<TreeNode> &t);
bool Cmp(TreeNode a, TreeNode b);
int findRoot(vector<TreeNode> &t);

int main() {
    int rootA, rootB;
    int n, i;
    cin >> n;
    for (i=0; i<n; ++i)
        input(trA);
    cin >> n;
    for (i=0; i<n; ++i)
        input(trB);
    rootA = findRoot(trA);
    rootB = findRoot(trB);
    if (trB.size()==trA.size()) {
        if (trB.size() == 0) cout << "Yes" << endl;
        else if ( !Cmp(trA[rootA], trB[rootB]) )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}
void input(vector<TreeNode> &t) {
    TreeNode temp;
    char rt, lt;
    temp.isRoot = true;
    cin >> temp.ch >> rt >> lt;
    if ( isdigit(rt) )
        temp.r = rt-'0';
    else
        temp.r = -1;
    if ( isdigit(lt) )
        temp.l = lt-'0';
    else
        temp.l = -1;
    t.push_back(temp);
}
bool Cmp(TreeNode a, TreeNode b) {
    if (trA[a.l].ch == trB[b.l].ch && trA[a.r].ch == trB[b.r].ch) {
        Cmp(trA[a.l], trB[b.l]);
        Cmp(trA[a.r], trB[b.r]);
    }
    else if (trA[a.l].ch == trB[b.r].ch && trA[a.r].ch == trB[a.l].ch) {
        Cmp(trA[a.l], trB[b.r]);
        Cmp(trA[a.r], trB[b.l]);
    }
    else
        return false;
    return true;
}
int findRoot(vector<TreeNode> &t) {
    vector<TreeNode>::iterator itr;
    int i=0;
    for (itr=t.begin(); itr!=t.end(); ++itr) {
        if (itr->l >=0 && t[itr->l].isRoot)
            t[itr->l].isRoot = false;
        if (itr->r >=0 && t[itr->r].isRoot)
            t[itr->r].isRoot = false;
    }
    for (itr=t.begin(); itr!=t.end(); ++itr, ++i)
        if (itr->isRoot) return i;
    return -1;
}
