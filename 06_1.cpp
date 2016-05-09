#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MaxNode 10

typedef struct
{
    int value[MaxNode][MaxNode];
    int n;
    int m;
}Graph;
void DFS(vector<int> &flag, Graph &G, int node)
{
    flag[node] = 1;
    cout << " " << node;
    for (int i=0; i<G.n; ++i) {
        if (G.value[node][i] == 1 && flag[i] == 0)
            DFS(flag, G, i);
    }
}
void BFS(vector<int> &flag, queue<int> &Q, Graph &G, int node)
{
    flag[node] = 1;
    Q.push(node);
    int temp = 0;
    while (!Q.empty()) {
        temp = Q.front();
        cout << " " << temp;
        Q.pop();
        for (int i=0; i<G.n; ++i) {
            if (G.value[temp][i] == 1 && flag[i] == 0) {
                Q.push(i);
                flag[i] = 1;
            }
        }
    }
}
int main()
{
    int N = 0,
        M = 0;
    cin >> N >> M;
    Graph G;
    G.m = M;
    G.n = N;
    int x = 0,
        y = 0;
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j) {
            G.value[i][j] = 0;
        }
    for (int i=0; i<M; ++i) {
        cin >> x >> y;
        G.value[x][y] = 1;
        G.value[y][x] = 1;
    }
    vector<int> flag(N, 0);
    for (int i=0; i<N; ++i)
        if (flag[i] == 0) {
            cout << "{";
            DFS(flag, G, i);
            cout << " }" << endl;
        }
    vector<int> flag1(N, 0);
    queue<int> Q;
    for (int i=0; i<N; ++i)
        if (flag1[i] == 0) {
            cout << "{";
            BFS(flag1, Q, G, i);
            cout << " }" << endl;
        }
    return 0;
}
