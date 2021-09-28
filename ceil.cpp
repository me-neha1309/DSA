 #include <bits/stdc++.h>
using namespace std;

int floor_val(int arr[], int start, int end, int ele)
{
    int mid, res=INT_MAX;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(arr[mid]>ele and arr[mid]<res)
        {
            res =  arr[mid];
            end = mid - 1;
        }

        else
        start = mid+1;
    }

    return res;
}

int main()
{
    int n,ele;
    cin>>n;
    int arr[n], i;
    for(i=0; i<n; i++)
    cin>>arr[i];
    cout<<"element: ";
    cin>>ele;
    int pos = floor_val(arr, 0, n-1, ele);
    if(pos!=INT_MAX)
    cout<<"Floor value is "<<pos<<endl;
    else 
    cout<<"no less than that"<<endl;
}