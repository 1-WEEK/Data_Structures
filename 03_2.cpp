#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

struct TreeNode{
    int r, l, add;
};
vector<TreeNode> tree, list;

int findRoot(vector<TreeNode> &v, int a[]);
void travelLevel(int root);

int main()
{
    int n, i(0), root;
    char tr, tl;
    TreeNode temp;
    cin >> n;
    int a[n];
    while (n--) {
        temp.add = i;
        a[i++] = 1;
        cin >> tl >> tr;
        if (isdigit(tr))
            temp.r = tr-'0';
        else
            temp.r = -1;
        if (isdigit(tl))
            temp.l = tl-'0';
        else
            temp.l = -1;
        tree.push_back(temp);
    }
    root = findRoot(tree, a);
    travelLevel(root);
    return 0;
}
int findRoot(vector<TreeNode> &v, int a[]) {
    vector<TreeNode>::iterator itr;
    int i;
    for (itr=v.begin(); itr!=v.end(); ++itr) {
        if (a[itr->r])
            a[itr->r] = 0;
        if (a[itr->l])
            a[itr->l] = 0;
    }
    for (i=0; i<v.size(); ++i)
        if(a[i]) return i;
    return -1;
}
void travelLevel(int root) {
    list.push_back( tree[root] );
    TreeNode t;
    int flag = 0;
    while ( !list.empty() ) {
        t = list[0];
        list.erase(list.begin());
        if (t.r<0 && t.l<0) {
            if (flag) cout << " ";
            else flag = 1;
            cout << t.add;
        }
        else {
            if (t.l>-1)
                list.push_back(tree[t.l]);
            if (t.r>-1)
                list.push_back(tree[t.r]);
        }
    }
}
