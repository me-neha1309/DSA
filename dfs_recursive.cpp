#include <bits/stdc++.h>
using namespace std;

vector<int>arr;

void dfs(vector<vector<int>>adj, vector<int>&vis, int source){
    for(int i : adj[source]){
        if(vis[i]==0){
            vis[i]=1;
            arr.push_back(i);
            dfs(adj, vis, i);
        }
    }
}

int main(){
    int ver, e, x, y;
    arr.clear();
    cout<<"vertices : ";
    cin>>ver;
    cout<<"edges : ";
    cin>>e;
    cout<<"Enter edges "<<endl;
    vector<vector<int>>v(ver);
    for(int i=0; i<e; i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int>vis(ver, 0);
    vis[0]=1;
    arr.push_back(0);
    dfs(v, vis, 0);

    if(arr.size()!=ver)
        cout<<"DFS traversal is not possible"<<endl;

    else{
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}