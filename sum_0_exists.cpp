#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

//An array of positive and negative numbers, find if there is a subarray of size atleast 1 with the sum 0

bool subarray_exists(ll a[], ll n)
{
    // if a sum of 0 or two equal sums in prefix subarray exists return true otherwise false.
    unordered_set <ll> sumset;
    ll sum = 0;
    for(ll i=0; i<n; i++)
    {
        sum+=a[i];
        if(sum==0 || sumset.find(sum)!=sumset.end())
        return true;

        sumset.insert(sum);
    }
    return false;

}

int main()
{
    ll n;
    cin>>n;
    ll a[n],i;
    for(i=0; i<n; i++)
    cin>>a[i];

    if(subarray_exists(a,n))
    cout<<"true"<<endl;

    else 
    cout<<"false"<<endl;
}