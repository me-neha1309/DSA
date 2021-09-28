#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

int ispalindrome(string s, int i, int j)
{
    string s1, s2;
    for(int k=i; k<=j; k++)
    s1.push_back(s[k]);

    for(int k=j; k>=i; k--)
    s2.push_back(s[k]);

    if(s1.compare(s2)==0)
    return 1;

    else 
    return 0;
}

int solve(string a, int i , int j)
{
    if(i>=j)
    return 0;

    if(ispalindrome(a,i,j)==1)
    return 0;

    if(t[i][j]!=-1)
    return t[i][j];

    int mn =INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp = 1+ solve(a,i,k) +solve(a, k+1, j);

        mn = min(mn, temp);
    }

    return (t[i][j] = mn);
}

int main()
{
    string x;
    cin>>x;
    memset(t, -1, sizeof(t));
    cout<<"minimum no. of partition required is "<<solve(x, 0, x.length()-1);
    
}