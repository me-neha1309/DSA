#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t,s,d, count=0;
    cin>>t;
    while(t--)
    {
        count=0;
        cin>>s>>d;
        while((s>=1 && d>=2) || (s>=2 && d>=1)){
            if(s>d)
            {
                s-=2;
                d-=1;
                count++;
            }
            else
            {
                s-=1;
                d-=2;
                count++;
            }
            
        }
         cout<<count<<endl;

    }
   
}