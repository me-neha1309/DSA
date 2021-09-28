//to get the length of shortest common supersequence
//a.length()+b.length()-lcs(a,b)
#include <bits/stdc++.h>
using namespace std;

string print_shortest_common_supersequence(string a, string b){
    int m=a.length();
    int n=b.length();

    vector<vector<int>>t(m+1, vector<int>(n+1));

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0){
                t[i][j]=j;
            } else if(j==0){
                t[i][j]=i;
            } else if(a[i-1]==b[j-1]){
                t[i][j]=1+t[i-1][j-1];
            } else {
                t[i][j]=1+min(t[i-1][j], t[i][j-1]);
            }
        }
    }

    int ind=t[m][n];

    string s;

    int i=m, j=n;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(a[i-1]);
            i--; j--; ind--;
        } else if(t[i-1][j]>t[i][j-1]){
            s.push_back(b[j-1]);
            j--; ind--;
        } else {
            s.push_back(a[i-1]);
            i--; ind--;
        }
    }

    while(i>0){
        s.push_back(a[i-1]);
        i--; ind--;
    }

    while(j>0){
        s.push_back(b[j-1]);
        j--;
        ind--;
    }

    reverse(s.begin(), s.end());
    return s;
}
int main(){
    string a, b;
    cin>>a;
    cin>>b;

    cout<<print_shortest_common_supersequence(a, b)<<endl;
}