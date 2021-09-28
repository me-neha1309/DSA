#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>>adj, rev;

void dfs1(int i, vector<bool>&vis, stack<int>&mp){
    vis[i] = true;

    for(int j : adj[i]){
        if(!vis[j])
            dfs1(j, vis, mp);
    }

    mp.push(i);
}

void reverse(){
    int n = adj.size();
    for(int i=0; i<adj.size(); i++){
        for(int j : adj[i]){
            rev[j].push_back(i);
        }
    }
}

void dfs2(int i, vector<bool>&vis){
    cout<<i<<" ";
    vis[i] = true;

    for(int j : rev[i]){
        if(!vis[j])
            dfs2(j, vis);
    }
}

void fscc(int n){
    stack<int>mp;

    vector<bool>vis(n, false);

    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs1(i, vis, mp);
    }

    reverse();

    for(int i=0; i<n; i++)
        vis[i] = false;

    cout<<"The strongly connected componenets are "<<endl;

    while(!mp.empty()){
        int curr = mp.top();
        mp.pop();

        if(!vis[curr]){
            dfs2(curr, vis);
            cout<<endl;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of vertices : ";
    cin>>n;
    int e;
    cout<<"\nEnter the no. of edges : "<<endl;
    cin>>e;
    cout<<"\nEnter the edges \n";
    for(int i=0; i<e; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    fscc(n);
}