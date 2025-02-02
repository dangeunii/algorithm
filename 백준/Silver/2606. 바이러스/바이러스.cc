#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[101];
int visited[101];

void dfs(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if (visited[v] == 0){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    //freopen("input.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i ++){
        int x, y;

        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    int cnt = 0;

    for(int i = 1 ; i <= N; i++){
        if(visited[i] == 1){
            cnt++;
        }
    }

    // 1번 노드는 제외하기
    cout << cnt-1;
}
