#include <bits/stdc++.h>
using namespace std;

int first_element_index(int arr[], int n)
{
    int start = 0, mid, end = n-1;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(arr[prev]>arr[mid] && arr[next]>arr[mid])
        return mid; 

        if(arr[start]>arr[mid] && arr[end]>arr[mid])
        end = mid;

        else if(arr[start]<arr[mid] && arr[mid]>arr[end])
        start = mid;

        else 
        end = mid;
    }
}

int bin_search(int arr[], int start, int end, int ele)
{
    int  mid;
    
    while(start<=end)
    {
        mid = start + (end - start)/2;
        if(arr[mid]==ele)
        return mid;

        else if(arr[mid]>ele)
        end = mid - 1;

        else if(arr[mid]<ele)
        start = mid + 1;
    }
    return -1;
}

int main()
{
    int n, ele;
    cin>>n;
    cout<<"elements : ";
    int i, ind, locate1, locate2, a[n];
    for(i=0; i<n; i++)
    cin>>a[i];
    cout<<"Element: ";
    cin>>ele;

    ind = first_element_index(a, n);
    cout<<"index of 1st element is "<<ind<<endl;
    locate1 = bin_search(a, 0, ind-1, ele);
    if(locate1==-1)
    {
        locate2 = bin_search(a,ind,n-1,ele);
        if(locate2==-1)
        cout<<"Element is not found"<<endl;
        else 
        cout<<"find at position "<<locate2<<endl;
    }
    else{
        cout<<"found at position "<<locate1<<endl;
    }
}