#include <bits/stdc++.h>
using namespace std;

int start;
int last;

int filter(int arr[], int n)
{
    int s = 0, e = n-1;
    while(e<n && s<n)
    {
        if(arr[e]==0)
        {
            s = e+1;
            e = 2*e;
        }
        else
        break;
    }
    start = s;
    last = e;
}

int first_occurrence(int arr[], int n)
{
    int mid, res=-1;
    while(start<=last && start<n && last<n)
    {
        mid = start + (last - start)/2;
        if(arr[mid]==0)
        start = mid + 1;

        else {
            last = mid - 1;
            res = mid;
        }
    }
    return res;
}

int main()
{
    int a[1000],n,pos;
    cout<<"number: ";
    cin>>n;
    cout<<"Binary inputs: ";
    for(int i=0; i<n; i++)
    cin>>a[i];

    filter(a,n);
    pos = first_occurrence(a,n);
    if(pos==-1)
    cout<<"No occurrence of 1 is present"<<endl;

    else 
    cout<<"found at "<<pos<<endl;

    return 0; 
}