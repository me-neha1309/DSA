#include<bits/stdc++.h>
using namespace std;

int static t[1001][1001];
int solve(int a[], int i, int j)
{
    if(i==j)
     return 0;

    if(t[i][j]!=-1)
    return t[i][j];

    int temp,k,minm = INT_MAX;
    for(k=i; k<j; k++)
    {
        temp = solve(a,i, k) + solve(a, k+1, j) + a[i-1] * a[k] * a[j];

        if(minm >temp)
        minm = temp;
    }

    return (t[i][j] = minm);

}

int main()
{
    int n;
    cin>>n;
    int a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];
    memset(t, -1, sizeof(t));
    cout<<"minimum cost is "<<solve(a, 1, n-1);
}