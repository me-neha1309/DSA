#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j)
{
    if(i==j)
    return 0;

    int minm = INT_MAX;
    int temp, k;

    for( k=i; k<j; k++){
       temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];

       if(minm>temp)
       minm = temp;
    }

    return minm;
}

int main()
{
    int n;
    cin>>n;
    int arr[n],i;
    for(i=0; i<n; i++)
    cin>>arr[i];
    cout<<"Minimum cost for the matrix chain multiplication "<<solve(arr, 1, n-1);
}