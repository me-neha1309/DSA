#include<bits/stdc++.h>
using namespace std;
//to count the consecutive numbers which are less than or equal to  the given number in the left hand side.
int main(){
    int a[10],count,i;
    vector <int> v;
    stack <int> s;
    cout<<"\nEnter the numbers:";
    for(i=0;i<10;i++)
    cin>>a[i];
    for(i=0;i<10;i++){
        if(s.size()==0)
        v.push_back(i-1);
        else if(s.size()>0 && a[s.top()]>a[i])
        v.push_back(s.top());
        else if(s.size()>0 && s.top()<=a[i]){
            while(s.size()>0 && a[s.top()]<=a[i])
                 s.pop();
            if(s.size()==0)
            v.push_back(i-1);
            else
            v.push_back(s.top());
        }
        s.push(i);
    }

    cout<<"\n So the required stock is ";
    for(i=0;i<10;i++){
        cout<<a[i]<<" "<<i-v[i]<<endl;
    }


}