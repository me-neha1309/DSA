#include <bits/stdc++.h>
using namespace std;

string print_lcs(string a, string b){
    int n=a.length(), m=b.length();

    int t[n+1][m+1];

    memset(t, 0, sizeof(t));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            } else {
                t[i][j]=max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    int ind=t[n][m];
    int i=n, j=m;
    string s;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(a[i-1]);
            i--; j--;
        } else {
            if(t[i-1][j]>t[i][j-1]){
                i--;
            } else {
                j--;
            }
        }
    }

    reverse(s.begin(), s.end());

    return s;
}

int lcs(string a, string b){
    int n=a.length(), m=b.length();

    int t[n+1][m+1];

    memset(t, 0, sizeof(t));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            } else {
                t[i][j]=max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[n][m];
}
int main(){
    string a, b;
    cin>>a;
    b=a;
    reverse(b.begin(), b.end());

    cout<<"Minimum number of deletion to make the sequence palindrome is "<<a.length()-lcs(a, b)<<endl;

    cout<<"The sequence is "<<print_lcs(a, b)<<endl;
}

//it's bruteforce would have taken 2^n tc
//this took only n^2