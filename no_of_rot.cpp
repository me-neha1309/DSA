#include <bits/stdc++.h>
using namespace std;

int bin_search(int arr[], int n)
{
    int start = 0, mid, end = n-1;
    while(start<=end)
    {
        mid = start + (end-start)/2; 
        int next = (mid+1)%n;
        int prev = (mid + n -1)%n;
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

int main()
{
    int n;
    cout<<"Numbers: ";
    cin>>n;
    int a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];
    cout<<"input taken\n";
    int rou = bin_search(a, n);
    if(n-rou<n)
    cout<<"No. of rotations is "<<n-rou<<endl;
    else 
    cout<<"No. of rotations is "<<rou<<endl;

    // or use the formula 
    cout<<"No. of rotations is "<<abs(n-rou)%n<<endl;
    return 0;
}