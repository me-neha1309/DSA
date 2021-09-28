#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPrime(ll n)
{
    if(n<=1)
    return false;

    if(n<=3)
    return true;

    if(n%2==0 || n%3==0)
    return false; 

    for(ll i=5; i*i<=n; i=i+6)
    if(n%i==0 || n%(i+2)==0)
    return false;

    return true;
}

vector<ll> sieve(ll n)
{
    bool prime[n+1];
    for(ll i=0; i<=n; i++)
    prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for(ll i=2; i<=sqrt(n); i++)
    {
        if(prime[i]==1)
        {
            for(ll j=2; i*j<=n; j++)
            prime[i*j] = false;
        }
    }

    vector<ll> v;

    for(ll i=0; i<=n; i++)
    {
        if(prime[i])
        v.push_back(i);
    }
    return v;
}

int LSCPUtil(ll limit, vector<ll>&prime, ll sum_prime[])
{
    ll max_len = -1;
    ll prime_num = -1;
    for(ll i = 0; prime[i]<=limit; i++)
    {
        for(ll j =0; j<i; j++)
        {
            if(sum_prime[i]-sum_prime[j]>limit)
            break;

            ll consec_sum = sum_prime[i];

            if(binary_search(prime.begin(), prime.end(), consec_sum))
            {
                if(max_len < i-j+1)
                {
                    max_len = i-j+1;
                    prime_num = consec_sum;
                }
            }
        }
    }
    return prime_num;
}

void lscp(ll arr[], ll n)
{
    vector<ll> primes;
    primes = sieve(1000000);
    ll sum_prime[primes.size()+1];
    sum_prime[0] = 0;
    for(ll i =1; i<=primes.size(); i++)
    sum_prime[i] = primes[i-1] + sum_prime[i-1];

    for(ll i =0; i<n; i++)
    cout<<LSCPUtil(arr[i], primes, sum_prime)<<" ";
}

int main()
{
    ll n;
    cin>>n;
    ll a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];

    lscp(a, n);
    return 0;
}