#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>a){
    vector<int>lis(a.size());
    int n=a.size();
    lis[0]=1;
    for(int i=1; i<n; i++){
        lis[i]=1;

        for(int j=0; j<i; j++){
            if(a[i]>a[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }

    return *max_element(lis.begin(), lis.end());
}

int main(){
    int n;
    cin>>n;

    vector<int>a(n);

    for(int i=0; i<n; i++)
    cin>>a[i];

    cout<<"LIS "<<lis(a)<<endl;
}