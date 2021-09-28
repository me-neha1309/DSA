#include <bits/stdc++.h>
using namespace std;

int nextg(int arr[], int n, int ele)
{
    int start = 0, end = n-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid]==ele)
        return mid;

        else if(arr[mid]<ele)
        start = mid + 1;

        else 
        end = mid - 1;
    }

    return start;
}

int nextl(int arr[], int n, int ele)
{
    int start = 0, end = n-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid]==ele)
        return mid;

        else if(arr[mid]<ele)
        start = mid + 1;

        else 
        end = mid - 1;
    }
    return end;
}

int main()
{
    int a[100], n, ng, nl, ele, i;
    cout<<"numbers: ";
    cin>>n;
    cout<<"elements: ";
    for(i=0; i<n ; i++)
    cin>>a[i];
    cout<<"element: ";
    cin>>ele;
    ng = nextg(a, n, ele);
    nl = nextl(a, n, ele);
    if(ng==nl)
    cout<<"element found at "<<ng<<endl;

    else 
    cout<<"element preceding and succeeding are found at "<<nl<<" "<<ng<<endl;
}

