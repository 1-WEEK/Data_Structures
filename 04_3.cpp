#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int array[1000];

int power(int n)
{
    int i, num(1);
    if (!n) return 1;
    for (i=1; i<=n; ++i) num *= 2;
    return num;
}
int levelSum(int n) {
    int sum;
    n--;
    if (n==0) sum = 1;
    else sum = power(n+1)-1;
    return sum;
}
void solve(int ARight, int ALeft, int TRoot)
{
    
}
int main()
{
    int n;
    cin >> n;
    int i, array[n];
    for (i=0; i<n; ++i)
        cin >> array[i];
    sort(array, array+n);
    solve(n, 0, array);
    cout << "root = " << list[0];
    return 0;
}
