#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1001;
const int MINH = -10001;

int H[MAXN], size;

void Create()
{
    size = 0;
    H[0] = MINH;
}
void Insert(int x)
{
    int i;
    for (i=++size; H[i/2]>x; i/=2)
        H[i]=H[i/2];
    H[i]=x;
}
int main()
{
    int n, m, i, j, x;
    cin >> n >> m;
    Create();
    for (i=0; i<n; ++i) {
        scanf("%d", &x);
        Insert(x);
    }
    for (i=0; i<m; ++i) {
        scanf("%d", &j);
        printf("%d", H[j]);
        while (j>1) {
            j /= 2;
            printf(" %d", H[j]);
        }
        printf("\n");
    }
    return 0;
}
