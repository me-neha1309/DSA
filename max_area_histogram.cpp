#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define modd 1000000007

vector<ll> build_nsl(ll a[], ll n){
     vector <ll> left;
     stack<pair<ll, ll> > s;
     ll i, pseudoindex = -1;
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

vector<ll> build_nsr(ll a[], ll n){
     vector <ll> right;
     stack<pair<ll, ll> >s;
     ll i, pseudoindex = n;
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

int main(){
   ll n,b,h;
   //cout<<"\n Enter the size  of the array:";
   cin>>n;
   cin>>b>>h;
   ll a[n],i,width[n],vol2=0;
   for(i=0;i<n;i++){
   cin>>a[i];
   vol2 = (vol2 + a[i]%modd)%modd;
   }

   vector <ll> left, right;
   left=build_nsl(a, n);
   right=build_nsr(a,n);
   reverse(right.begin(), right.end());
   ll maxi = 0;
   for(i=0;i<n;i++){

       width[i]=abs((right[i]-left[i]-1));
       width[i] = (width[i]*a[i]);
       maxi = max(width[i], maxi);
   }

   ll vol1 = (maxi*b*h)%modd;
   vol2 = (vol2*b*h)%modd;
   cout<<(abs(vol2-vol1))%modd<<endl;

}
