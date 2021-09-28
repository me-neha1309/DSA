#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>v, vector<bool>&vis, int source){
    for(int i : v[source]){
        if(!vis[i]){
            vis[i] = true;
            dfs(v, vis, i);
        }
    }
}

bool isMother(vector<bool>vis){
    for(int i=0; i<vis.size(); i++){
        if(!vis[i])
            return false;
    }

    return true;
}

int main(){
    int n, edg,  x, y, check;
    cin>>n;
    cin>>edg;
    vector<vector<int>>v(n);

    for(int i=0; i<edg; i++){
        cin>>x>>y;
        v[x].push_back(y);
    }

    vector<bool>vis(n, false);

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(v, vis, i);
            check = i;
        }
    }

    fill(vis.begin(), vis.end(), false);

    dfs(v, vis, check);

    if(isMother(vis))
        cout<<check<<endl;
        
    else 
        cout<<"No mother vertex"<<endl;
}