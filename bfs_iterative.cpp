#include <bits/stdc++.h>
using namespace std;

vector<int>arr;

void bfs(vector<vector<int>>adj, vector<int>&vis, int source){
    queue<int>q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty()){
        source = q.front();
        q.pop();
        arr.push_back(source);
        for(int i : adj[source]){
            if(vis[i]==0){
                vis[i]=1;
                q.push(i);
            }
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
    
    bfs(v, vis, 0);

    if(arr.size()!=ver){
        cout<<"BFS not possible "<<endl;
    }

    else{
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
    } 
        
}