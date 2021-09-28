#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define ll long long 

//function to get the middle inex from the corner indices
ll getMid(ll s, ll e){ return s+(e-s)/2; }

ll build(vector<ll>v, ll start, ll end, vector<ll>&st, ll ind){
    if(start==end){
        st[ind]=v[start];
        return v[start];
    }

    ll mid=getMid(start, end);
    st[ind]=build(v, start, mid, st, 2*ind+1) + build(v, mid+1, end, st, 2*ind+2);

    return st[ind];
}

ll getsum(vector<ll>st, ll start, ll end, ll qstart, ll qend, ll ind){
    if(qstart<=start && qend>=end)
        return st[ind];

    //if segment of this node is outside the range
    if(end<qstart || start>qend)
        return 0;

    ll mid=getMid(start, end);
    return getsum(st, start, mid, qstart, qend, 2*ind+1) + getsum(st, mid+1, end, qstart, qend, 2*ind+2);
}

void update(vector<ll>&st, ll start, ll end, ll i, ll diff, ll ind){
    if(i<start || i>end)
        return;

    st[ind]=st[ind]+diff;

    if(start!=end){
        ll mid=getMid(start, end);
        update(st, start, mid, i, diff, 2*ind+1);
        update(st, mid+1, end, i, diff, 2*ind+2);
    }
}

int main(){
    ll n;
    cin>>n;
    vector<ll>v(n);

    for(ll i=0; i<n; i++)
        cin>>v[i];

    //building segment tree from the given array elements
    ll height = (int)(ceil(log2(n)));

    ll maxsize = 2*(int)pow(2,height)-1;
    vector<ll>st(maxsize);

    ll sum = build(v, 0, n-1, st, 0);

    //printing the segment tree
    for(ll i=0; i<maxsize; i++)
    cout<<st[i]<<" ";

    cout<<endl;
    cout<<sum<<endl;
    ll qstart, qend;
    // for querying about the sum
    cout<<"query start"<<": "<<endl;
    cin>>qstart;

    cout<<"query end"<<": "<<endl;
    cin>>qend;

    if(qstart<0 || qend>n-1 || qstart>qend){
        cout<<"Invalid queries"<<endl;
    } else {
        cout<<"Thge sum in the given range is "<<getsum(st, 0, n-1, qstart, qend, 0)<<endl;
    }

    //for updating 
    ll upind, nval;
    cout<<"Enter the index to update "<<": "<<endl;
    cin>>upind;
    cout<<"Enter the updated value : "<<endl;
    cin>>nval;
    if(upind<0 || upind>n-1){
        cout<<"Invalid input"<<endl;
    } else {
        ll diff=nval-v[upind];
        v[upind]=nval;

        update(st, 0, n-1, upind, diff, 0);
        //printing the segment tree
    for(ll i=0; i<maxsize; i++)
    cout<<st[i]<<" ";

    cout<<endl;
        cout<<"updated sum in given range is "<<getsum(st, 0, n-1, qstart, qend, 0)<<endl;
    }
}