#include <bits/stdc++.h>
using namespace std;

//0 for unvisited, 1 for processed and 2 for processing
bool isCycle(vector<vector<int>>adj, vector<int>&vis, int source){
    if(vis[source]==2)
        return true;

    vis[source]=2;
    for(int i : adj[source]){
        if(vis[i]!=1){
            if(isCycle(adj, vis, i))
                return true;
        }
    }

    vis[source]=1;
    return false;
}

int main(){
    int ver, e, x, y;
    cout<<"vertices : ";
    cin>>ver;
    cout<<"edges : ";
    cin>>e;
    cout<<"Enter edges "<<endl;
    vector<vector<int>>v(ver);
    for(int i=0; i<e; i++){
        cin>>x>>y;
        v[x].push_back(y);
    }
    
    vector<int>vis(ver, 0);

    bool ans = false;
    for(int i=0; i<ver; i++){
        if(vis[i]==0){
            if (isCycle(v, vis, i)){
                ans = true;
                break;
            }
        }
    }

    if(ans)
        cout<<"Yes there is cycle "<<endl;

    else 
        cout<<"No there is no cycle "<<endl;
}