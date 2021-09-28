#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
//maximum subarray size such that the sum that all subarrays of that size has sum less than k

ll bin_search(ll pref[], ll n, ll k)
{
    ll res = -1;
    ll start = 1, end = n, mid;
    
    while(start<=end)
    {
        //cout<<"enter"<<endl;
        mid = start + (end - start)/2;
        ll i;
        for(i = mid; i<=n; i++)
        {
            if(pref[i]-pref[i-mid]>k){
                  //cout<<"broke because "<<pref[i]-pref[i-mid]<<endl;
                  break;
            }
            //cout<<"at "<<i<<" pref = "<<pref[i] - pref[i-mid]<<endl;
        }
        //cout<<"returned at i "<<i<<endl;
        if(i>n)
        {
            start = mid + 1;
            res = mid;
        }
        else
        end = mid - 1;
    }

    return res;
}

ll pref_sum(ll a[], ll n, ll k)
{
    ll pref[n+1] = {0};
    for(ll i=0; i<n; i++)
    {
        pref[i+1] = pref[i] + a[i];
    }

    return bin_search(pref, n, k);
}

int main()
{
    ll n;
    cout<<"n: ";
    cin>>n;
    ll a[n],i;
    cout<<"elements: ";
    for(ll i=0; i<n; i++)
    cin>>a[i];
    ll k;
    cout<<"k: ";
    cin>>k;
    cout<<"max_size: "<<pref_sum(a,n,k);

}