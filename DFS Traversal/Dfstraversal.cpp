#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define endl '\n'
#define fo(i,o,n) for(int i=o;i<n;i++)
#define rfo(i,o,n) for(int i=n-1;i>=o;i--)
#define all(v) v.begin(),v.end()
#define vi vector<int> 
#define mii map<int,int>
#define miv map<int,vector<int>>
#define pb push_back

vector<int>adj[100001];
int visited[100001];

void dfs(int node){
    visited[node]=1;
    cout<<node<<" ";
    for(int child: adj[node]){
        if(visited[child] == 0){
            dfs(child);
        }
    }
}

void addedge(int a, int b){
    adj[a].pb(b);
    adj[b].pb(a);
}

int32_t main(){
    f;
    addedge(1,2);
    addedge(2,4);
    addedge(4,3);
    addedge(5,1);
    addedge(3,6);
    for(int i=1; i<=6; i++){
        if(visited[i]==0) dfs(i);
    }
    return 0;
}
