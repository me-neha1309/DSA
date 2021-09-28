#include<bits/stdc++.h>
using namespace std;

int first_search(int arr[], int n, int ele)
{
    int start = 0, end = n-1, mid, res=-1;
    while(start<=end)
    {
        mid = start + (end - start)/2;
        if(arr[mid]==ele)
        res = mid;

        if(arr[mid]>=ele)
        end = mid-1;

        if(arr[mid]<ele)
        start = mid+1;
    } 
    return res;
}

int last_search(int arr[], int n, int ele)
{
    int start = 0, end = n-1, mid, res=-1;
    while(start<=end)
    {
        mid = start + (end - start)/2;
        if(arr[mid]==ele)
        res = mid;

        if(arr[mid]>ele)
        end = mid-1;

        if(arr[mid]<=ele)
        start = mid+1;
    } 
    return res;
}

int main()
{
    int n;
    cout<<"Number : ";
    cin>>n;
    int arr[n], i;
    for(i=0; i<n; i++)
    cin>>arr[i];
    int ele;
    cout<<"Element: ";
    cin>>ele;

    int first = first_search(arr, n, ele);
    int last = last_search(arr, n, ele);

    if(first==-1 && last ==-1)
    cout<<"Element not found"<<endl;

    else 
    cout<<"the count is "<<last-first+1<<endl;

    return 0;
}