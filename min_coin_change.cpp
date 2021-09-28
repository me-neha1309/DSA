#include<bits/stdc++.h>
using namespace std;

int knapsack(int coin[], int sum, int n)
{
    int i,j,t[n+1][sum+1];
    for(i=0;i<=sum;i++)
    t[0][i] = INT_MAX-1;

    for(j=1;j<=n;j++)
    t[j][0] = 0;

    for(i=1, j=1; j<=sum; j++)
    if(j%coin[i-1]==0)
    t[i][j] = j/coin[i-1];
    else 
    t[i][j] = INT_MAX - 1;

    for(i=2; i<=n; i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(coin[i-1]<=j)
            {
                t[i][j] = min(1+t[i][j-coin[i-1]],  t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
            
        }
    }
    
    return t[n][sum];

}

int main()
{
    int n, sum;
    cout<<"no. of coins and sum\n";
    cin>>n>>sum;
    int coin[n],i;
    cout<<"Enter the coins: ";
    for(i=0; i<n; i++)
    cin>>coin[i];
    cout<<"the minm no. of subsets for the given sum is "<<knapsack(coin, sum, n);
    return 0;
}