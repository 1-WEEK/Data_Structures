#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MaxNode = 100;
const int INF     = 101;

struct Graph {
    int M;
    int N;
    int value[MaxNode][MaxNode];
};
void floyd(Graph &G, int D[][MaxNode])
{
    for (int i=0; i<G.N; ++i)
        for (int j=0; j<G.N; ++j) {
            if (i==j) D[i][j] = 0;
            else D[i][j] = G.value[i][j];
        }
    for (int k=0; k<G.N; ++k)
        for (int i=0; i<G.N; ++i)
            for (int j=0; j<G.N; ++j)
                if ( D[i][j] > D[i][k] + D[k][j] )
                    D[i][j] = D[i][k] + D[k][j];
}
int findLong( int array[], int n )
{
    int max(0),i;
    if ( array[max] == INF ) return INF;
    for (i=1; i<n; ++i) {
        if ( array[i] == INF ) return INF;
        if ( array[max] < array[i] )
            max = i;
    }
    return array[max];
}
int findShort( int array[], int n)
{
    int min(0), i;
    for (i=1; i<n; ++i) {
        if ( array[min] > array[i] )
            min = i;
    }
    if ( array[min] == INF ) cout << 0;
    else cout << min+1 << " " << array[min];
}
int main()
{
    int D[MaxNode][MaxNode], i, j;
    Graph G;
    cin >> G.N >> G.M;
    for (i=0; i<G.N; ++i)
        for (int j=0; j<G.N; ++j)
            G.value[i][j] = INF;
    int x, y;
    for (i=0; i<G.M; ++i) {
        cin >> x >> y;
        --x, --y;
        cin >> G.value[x][y];
        G.value[y][x] = G.value[x][y];
    }
    floyd(G, D);

    int longlength[G.N];
    for (i=0; i<G.N; ++i) {
        longlength[i] = findLong( D[i], G.N );
    }

    findShort( longlength, G.N);
    return 0;
}
