#include<iostream>
#include <vector>
#include<queue>

using namespace std;

vector<int> adj[100];
int visited[100];

int bfs(int here){
    std::fill_n(visited, 100, -1);
    queue<int> q;
    visited[here] = 0;
    q.push(here);

    while (q.size()>0)
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here]){
            if (visited[there] != -1){
                continue;
            }
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }

    int sum = 0;
    for(int i = 0 ; i < 100; i ++){
        if(visited[i] != -1){
            sum += visited[i];
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int min = 6000;
    int tmp_i = 0;
    for(int i = 0 ; i < N; i++){
        //cout << "bfs : " << i << "\n";
        int tmp = bfs(i+1);
        if (min > tmp){
            min = tmp;
            tmp_i = i+1;
        }
    }

    cout << tmp_i;


}
