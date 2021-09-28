#include <bits/stdc++.h>
using namespace std;

//2 4 3 5 1 6 7

#define ll int

vector<int> build_nsl(vector <int> a, int n){
     vector <int> left;
     stack<pair<int, int> > s;
     int i, pseudoindex = -1;
     for(i=0; i<n; i++){
         if(s.size()==0)
             left.push_back(pseudoindex);
         else if(s.size()>0 && s.top().first<a[i])
             left.push_back(s.top().second);
         else if(s.size()>0 && s.top().first>=a[i]){
             while(s.size()>0 && s.top().first>=a[i])
                  s.pop();
             if(s.size()==0)
                left.push_back(pseudoindex);
             else 
                left.push_back(s.top().second);
         }
         s.push({a[i],i});
     }
     return left;
}

vector<int> build_nsr(vector <int> a, int n){
     vector <int> right;
     stack<pair<int, int> >s;
     int i, pseudoindex = n;
     for(i=n-1.; i>=0; i--){
         if(s.size()==0)
             right.push_back(pseudoindex);
         else if(s.size()>0 && s.top().first<a[i])
             right.push_back(s.top().second);
         else if(s.size()>0 && s.top().first>=a[i]){
             while(s.size()>0 && s.top().first>=a[i])
                  s.pop();
             if(s.size()==0)
                right.push_back(pseudoindex);
             else 
                right.push_back(s.top().second);
         }
         s.push({a[i], i});
     }
     return right;
}

ll MAH(vector <int> v, int n)
{
    vector <int> left,right;
    left=build_nsl(v, n);
    right=build_nsr(v,n);
    reverse(right.begin(), right.end());
    ll mx=0, i;
    for(i=0;i<n;i++){
        mx=max((right[i]-left[i]-1)*v[i], mx);
    }
    return mx;
}


int main()
{
    ll n,i,j,m;
    cin>>n>>m;
    ll a[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        cin>>a[i][j];
    }
    vector <int> v;
    for(j=0;j<m;j++)
        v.push_back(a[0][m]);

    ll mx = MAH(v,n);
    for(i=1;i<n;i++){
        for(j=0;j<m;j++){
        if(a[i][j]==0)
            v[j]=0; 
        else 
            v[j]=v[j]+a[i][j];
        }
        mx = max(mx, MAH(v,m));

    }
    cout<<mx<<endl;
    
}