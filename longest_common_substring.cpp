//longest common substring - Here we need to maintain the max length in the result variable
//As this could be changing as the pattern breaks in between

#include <bits/stdc++.h>
using namespace std;
int endi=0, endj=0;
string print_lcs(string a, string b){
    int n=a.length(), m=b.length();
    string s;
    
    while(endi>0 && endj>0 && a[endi-1]==b[endj-1]){
        s.push_back(a[endi-1]);
        endi--;
        endj--;
    }

    reverse(s.begin(), s.end());
    return s;
}

int lcs(string a, string b){
    int n=a.length(), m=b.length();

    int t[n+1][m+1];

    memset(t, 0, sizeof(t));

    int result=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                t[i][j]=t[i-1][j-1]+1;
                if(t[i][j]>result){
                    result=t[i][j];
                    endi=i; endj=j;
                }
            } else {
                t[i][j]=0;
            }
        }
    }

    return result;
}
int main(){
    string a, b;
    cin>>a;
    cin>>b;
    endi=0; endj=0;
    cout<<"The longest common substring length is "<<lcs(a, b)<<endl;

    cout<<"The substring is "<<print_lcs(a, b)<<endl;
}

//it's bruteforce would have taken n^4 tc
//this took only n^2