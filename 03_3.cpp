#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<int> Tree[30];
vector<int> reslut;

/*遍历*/
void postOrderTraversal(int fNode)
{
    if (Tree[fNode].size() == 1) {
        postOrderTraversal(Tree[fNode][0]); //后序遍历的特点
        reslut.push_back(fNode);
    }
    else if (Tree[fNode].size() == 2) {
        postOrderTraversal(Tree[fNode][0]);
        postOrderTraversal(Tree[fNode][1]);
        reslut.push_back(fNode);
    }
    else {
        reslut.push_back(fNode);
    }
}

int main()
{
    int n, i, val,
        root   =  0,
        popVal = -1;
    stack<int> stk;
    cin >> n;
    string action;
    cin >> action;
    cin >> root;
    stk.push(root);
    for (i = 1; i < 2 * n; ++i) {
        cin >> action;
        if (action == "Push") {
            scanf("%d", &val);
            if (popVal == -1) {
                Tree[stk.top()].push_back(val);
            }
            else {
                Tree[popVal].push_back(val);
            }
            stk.push(val);
            popVal = -1;
        }
        else if (action == "Pop") {
            popVal = stk.top();
            stk.pop();
        }
    }
    postOrderTraversal(root);
    for (i = 0; i < reslut.size(); ++i) {
        cout << reslut[i] << ((i == reslut.size()-1) ? '\n' : ' ');
    }
    return 0;
}
