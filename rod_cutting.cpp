#include <bits/stdc++.h>
using namespace std;

// In 0/1 knapsack we had choice whether to take that element or not and in either case it will be considered processed.

//In unbounded when an element is not chosen/rejected is considered as processed and won't be chosen again but if it has been chosen then it is unprocessed and can be chosen again.

int knapsack(int length[], int price[], int len, int n)
{
    int t[n+1][len+1],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=len;j++)
        t[i][j]=0;
    }
    for(i=1; i<=n; i++){
        for(j=1;j<=len;j++){
            if(length[i-1]<=j){
                t[i][j]=max(price[i-1]+t[i][j-length[i-1]], t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
            
        }
    }
    return t[n][len];

}

int main()
{
    int i,n,len;
    cout<<"No. of rod pieces and length of the rod"<<endl;
    cin>>n>>len;
    int price[n],length[n];
    cout<<"prices of different pieces"<<endl;
    for(i=0;i<n;i++)
    cin>>price[i];
    cout<<"length corresponding to those prices"<<endl;
    for(i=0;i<n;i++)
    cin>>length[i];
    cout<<"maximum profit earned is "<<knapsack(length, price, len, n)<<endl;
    return 0;
}