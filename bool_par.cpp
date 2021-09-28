 #include <bits/stdc++.h>
using namespace std;

int solve(string s, int i, int j, bool isTrue)
{
    if(i>j)
    return 0;

    if(i==j)
    {
        if(isTrue==true){
            if(s[i]=='T')
            return 1;

            else 
            return 0;
        }
        else{
            if(s[i]=='F')
            return 1;

            else 
            return 0;
        }
    }
    int ans = 0;

    for(int k = i+1; k<=j-1; k+=2){
        
        int lt = solve(s, i, k-1, true);
        int rt = solve(s, k+1, j, true);
        int lf = solve(s, i, k-1, false);
        int rf = solve(s, k+1, j, false);

        if(s[k]=='&')
        {
            if(isTrue==true)
            ans = ans+lt*rt;
            else 
            ans = ans+lt*rf+rt*lf+rf*lf;
        }

        else if(s[k]=='|')
        {
            if(isTrue==true)
            ans = ans+lt*rt +lf*rt+ rt*lf;
            else 
            ans = ans+lf*rf;
        }

        else{
            if(isTrue==true)
            ans = ans + lt*rf + rt*lf;
            else 
            ans = ans + rt*lt + rf*lf;
        }
    }

    return ans;
}

int main()
{
    string s;
    cout<<"boolean expression: ";
    cin>>s;
    cout<<"bool evaluation: ";
    bool is;
    cin>>is;
    cin.clear();
    cout<<"no. of ways this express can evaluate to "<<is<<" "<<solve(s, 0, s.length()-1, is);
}