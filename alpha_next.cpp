#include <bits/stdc++.h>
using namespace std;

char floor_val(char arr[], int start, int end, char ele)
{
    int mid;
    char res = '{';
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(arr[mid]>ele && arr[mid]<res)
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
    int n;
    cin>>n;
    int i;
    char arr[n], ele;
    for(i=0; i<n; i++)
    cin>>arr[i];
    cout<<"element: ";
    cin>>ele;
    char pos = floor_val(arr, 0, n-1, ele);
    //cout<<pos<<endl;
    if(pos>'a' && pos<='z')
    cout<<"Floor value is "<<pos<<endl;
    else 
    cout<<"no less than that"<<endl;
}