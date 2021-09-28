#include <bits/stdc++.h>
using namespace std;

int first_bin(int a[], int n, int ele)
{
    int start = 0, end = n-1, mid , res = -1;
    while(start<=end)
    {
        int mid = start + ((end - start)/2);
        if(a[mid]==ele)
        res = mid;

        if(a[mid]>ele)
        end = mid-1;

        if(a[mid]<=ele)
        start = mid+1;
    }

    return res;
}

int main()
{
    int n;
    cout<<"Number of elements: "<<endl;
    cin>>n;
    int a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];
    cout<<"Number: "<<endl;
    int num;
    cin>>num;
    int res = first_bin(a, n, num);
    if(res!=-1)
    cout<<"The last occurrence is at the index "<<res<<endl;
    else 
    cout<<"Element not found"<<endl;
    return 0;
    
}