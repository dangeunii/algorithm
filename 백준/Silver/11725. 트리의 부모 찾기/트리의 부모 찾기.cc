#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100001];
int visited[100001];
int parent[100001];

void dfs(int u){
    visited[u] = 1;
    for (int v : adj[u]){
        if(visited[v] == 0){
            parent[v] = u;
            dfs(v);
        }
    }

}

int main(){
    //freopen("input.txt","r",stdin);

    int N;
    cin >> N;

    for (int i = 0 ; i < N-1; i++){
        int x ,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    for(int i = 2 ; i <= N; i++){
        cout << parent[i] << "\n";
    }
}