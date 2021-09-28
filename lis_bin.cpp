#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> a){
    if(a.size()==0)
        return 0;

    vector<int>t;
    t.push_back(a[0]);

    int len=1;

    for(int i=1; i<a.size(); i++){
        if(a[i]<t[0]){
            t[0]=a[i];
        } else if(a[i]>t[len-1]){
            len++; t.push_back(a[i]);
        } else {
            int s=0, e=len-1;
            int mid; int k;
            while(s<=e){
                mid=(s+e)/2;
                if(t[mid]<a[i]){
                    s=mid+1;
                } else {
                    k=mid;
                    e=mid-1;
                }
            }
            t[k]=a[i];
        }
    }

    return len;
}

int main(){
    int n; cin>>n;
    vector<int>a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<lis(a)<<endl;
}