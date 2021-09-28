#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b)
{
    if(a.length()!=b.length())
    return 0;

    if(a.empty() && b.empty())
    return 1;

    if(a.compare(b)==0)
    return 1;

    if(a.length()<b.length())
    return 0;

    int n = a.length();

    for(int i=1; i<a.length(); i++)
    {
        if((solve(a.substr(0,i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i)))  ||  (solve(a.substr(0,i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i))))
        return 1;
    }


}

int main()
{
    string a,b;
    cin>>a>>b;
    if(solve(a,b))
    cout<<"Scrambled"<<endl;
    else 
    cout<<"Non scrambled"<<endl;
}