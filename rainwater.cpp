#include <bits/stdc++.h>
using namespace std;

int calculate_rain(int a[], int n)
{
    int lmax[n],rmax[n],rain[n],i,sum=0;
    lmax[0]=a[0];
    rmax[n-1]=a[n-1];
    for(i=1; i<n; i++)
    {
        lmax[i] = max(lmax[i-1], a[i]);
    }

    for(i=n-2; i>=0; i--)
    {
       rmax[i] = max(rmax[i+1], a[i]);
    }

    for(i=0;i<n;i++)
    {
        rain[i]= min(lmax[i],rmax[i]) - a[i];
        sum+=rain[i];
        cout<<rain[i]<<" ";
    }

    return sum;
}

int main()
{
    int n;
    cout<<"Enter the number of buildings: ";
    cin>>n;
    int a[n],i;
    cout<<"Enter the height of each building: ";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"the total amount of rainwater harvested "<<calculate_rain(a, n);
}