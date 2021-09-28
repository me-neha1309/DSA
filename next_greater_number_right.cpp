#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int arr[10],i,n=10;
    cout<<"Enter the numbers:";
    for(i=0;i<10;i++)
    cin>>arr[i];

    vector<int>v;
    stack<int>s;
    for(i=n-1;i>=0;i--){  //in case of left greatest element// for(i=0;i<n;i++)
        if(s.size()==0)
        v.push_back(-1);
        else if(s.size()>0 && s.top()>arr[i])
        v.push_back(s.top());
        else if(s.size()>0 && s.top()<arr[i])
        {
            while(s.size()>0 && s.top()<=arr[i])
            s.pop();

            if(s.size()==0)
            v.push_back(-1);
            else
            v.push_back(s.top());
        }
       s.push(arr[i]);
    }
    for(i=0;i<10;i++){
        cout<<arr[i]<<" "<<v[n-i-1]<<endl;//for lest greater no need to reverse the numbers in reverse order.
    }

}