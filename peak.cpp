#include<bits/stdc++.h>
using namespace std;

//maximum element in bitonic array can also use peak in that case the there only one peak present..0

int peak(int arr[], int n)
{
    int start = 0, end = n-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(mid==0 && arr[mid]>arr[mid+1])
        return mid;

        else if(mid==n-1 && arr[mid]>arr[mid-1])
        return mid;

        else if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
        return mid;

        else if(arr[mid-1]>arr[mid])
        end = mid - 1;

        else 
        start = mid + 1;
    }
}

int main()
{
    int a[100], n, i, pos;
    cout<<"numbers: ";
    cin>>n;
    cout<<"numbers: ";
    for(i=0; i<n; i++)
    cin>>a[i];

    pos = peak(a,n);
    cout<<"peak element is present at "<<pos<<endl;

    return 0;
}