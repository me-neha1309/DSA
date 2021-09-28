#include <bits/stdc++.h>
using namespace std;

//nearly sorted means element was expected at ith position but found at i-1th and i+1th position.

int find(int arr[], int start, int end, int ele)
{
    
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(mid-1>=start && arr[mid-1]==ele)
        return mid-1;

        else if(mid+1<=end && arr[mid+1]==ele)
        return mid+1;

        else if(arr[mid]==ele)
        return mid;

        else if(arr[mid]>ele)
        end = mid-2;

        else 
        start = mid+2;
    }

    return -1;
}

int main()
{
    int n, ele;
    cin>>n;
    int arr[n],i;
    for(i=0; i<n; i++)
    cin>>arr[i];
    cin>>ele;
    int pos = find(arr, 0, n-1, ele);
    if(pos==-1)
    cout<<"elements not found "<<endl;
    else 
    cout<<"element found at "<<pos<<endl;
}