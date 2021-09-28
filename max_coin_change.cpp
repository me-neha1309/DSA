#include<bits/stdc++.h>
using namespace std;

int unbound(int coin[], int sum, int n)
{
    int i,j,t[n+1][sum+1];
    for(i=0;i<=sum;i++)
    t[0][i] = 0;
    for(j=0;j<=n;j++)
    t[j][0]=1;
    for(i=1; i<=n; i++)
    {
        for(j=1;j<=sum; j++)
        {
            if(coin[i-1]<=j)
            {
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];
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
    cout<<"the maxm no. of subsets for the given sum is "<<unbound(coin, sum, n);
    return 0;
}