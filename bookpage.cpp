#include <bits/stdc++.h>
using namespace std;

int valid(int a[], int n, int k, int mx)
{
    int i,st=1, ans=0;
    for(i=0; i<n; i++)
    {
        ans+=a[i];
        if(ans>mx)
        {
           st++;
           ans = a[i];
        }
    }

    if(st==k)
    return 1;

    else 
    return 0;
}

int b_search(int a[], int start, int end, int k, int n)
{
    if(k>n)
    return -1;

    int res=-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(valid(a,n,k,mid))
        {
            res = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return res;
}

int main()
{
    int n,i,a[100],start = INT_MIN,end = 0, k;
    cout<<"Number: ";
    cin>>n;
    cout<<"Max students: ";
    cin>>k;
    cout<<"Inputs: ";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(i=0; i<n; i++)
    {
        end+=a[i];
        start = max(start, a[i]);
    }

    int opt = b_search(a, start, end, k, n);
    if(opt==-1)
    cout<<"No";

    else 
    cout<<"optimize: "<<opt;
}