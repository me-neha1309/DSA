#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    ll n,a,b,c,k=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>c;
        if(a==n && b==n && c!=n)
        cout<<"case #"<<k<<": "<<"IMPOSSIBLE";
        
        else if((a+b>2*n) || c>n || c>a || c>b)
        cout<<"case #"<<k<<": "<<"IMPOSSIBLE";
        
        else{
            ll build[n]={0},h=1;
            ll top = 0, i;
            h = 1;
            for(i=c; i<a&&top<n; i++)
            {
                build[top++] = n-1;
            }
            top = a-c;
            for(i=0; i<c&&top<n; i++)
            {
                build[top++]=n;
            }
            top=a;
            h= n-1;
            for(i=c; i<b&&top<n; i++)
            {
                build[top++]=n-1;
            }
            
            for(i=1; i<n; i++)
            {
                if(build[i]==0)
                {
                    ll prev = build[i-1];
                    build[i-1]=1;
                    build[i] = prev;
                }
            }
            if(build[0]==0)
            {
                i=1;
                while(i<n && build[i]==1)
                i++;
                
                if(i<n)
                {
                    ll prev = build[i];
                    build[i] = 1;
                    build[0] = prev;
                }
            }
            ll asee = 0, bsee = 0, bothsee = 0;
            ll prev = 1;
            for(i=0; i<n; i++)
            {
                if(build[i]>=prev){
                asee++;
                prev = build[i];
                }
            }
            prev = 1;
            for(i=n-1; i>=0; i--)
            {
                if(build[i]>=prev){
                bsee++;
                prev = build[i];
                }
            }
            prev = n;
            for(i=0; i<n; i++)
            {
                if(build[i]==prev)
                bothsee++;
            }
            //cout<<asee<<" "<<bsee<<" "<<bothsee<<endl;
            if(asee!=a || bsee!=b || bothsee!=c)
            {
                cout<<"case #"<<k<<": "<<"IMPOSSIBLE";
            }
            else{
            cout<<"case #"<<k<<": ";
            for(i=0; i<n; i++)
            cout<<build[i]<<" ";
            }
            
        }
        cout<<endl;
        k++;
    }
}