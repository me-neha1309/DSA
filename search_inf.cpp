#include <bits/stdc++.h>
using namespace std;

int start;
int last;
int filter(int arr[], int n, int ele)
{
    int st = 0, en = 1, flag=0;
    while(en<n && st<n)
    {
        if(arr[en]>=ele)
        {
             flag = 1;
             break;
        }
        else 
        {
            st = en+1;
            en = en*2;
        }
    }
    start = st;
    last = en;
    return flag;
}

int bin_search(int arr[], int ele, int n)
{
    int mid;
    while(start<=last && start<n && last<n)
    {
        mid = start + (last - start)/2;
        if(arr[mid]==ele)
        return mid;

        else if(arr[mid]>ele)
        last = mid - 1;

        else 
        start = mid + 1;

    }

    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n], i, ele;
    for(i=0; i<n; i++)
    cin>>arr[i];
    cin>>ele;
    filter(arr, n, ele);
    cout<<start<<" "<<last<<endl;
    int pos = bin_search(arr, ele, n);
    if(pos ==-1)
    cout<<"Element not found"<<endl;
    else 
    cout<<"Element found at pos "<<pos<<endl;
}