#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#define INF INT_MAX
using namespace std;

int N, M, X;

typedef struct
{
    int node;
    int weight;
} Data;

vector<Data> adj[1001];
int Dijk[1001];
int cnt[1001];

struct cmp
{
    bool operator()(Data a, Data b){
        return a.weight > b.weight;
    }
};

priority_queue<Data, vector<Data>, cmp> pq;

void D(int start) {
    for(int i = 1; i < N+1; i++){
        Dijk[i] = INF;
    }

    Dijk[start] = 0;
    pq.push({start, 0});

    while (pq.size()>0)
    {
        int nownode = pq.top().node;
        int weightSum = pq.top().weight;
        pq.pop();

        if (Dijk[nownode] < weightSum){
            continue;
        }

        for(int i = 0 ; i < adj[nownode].size(); i ++){
            int nextnode = adj[nownode][i].node;
            int weight = adj[nownode][i].weight;

            int w = weight + weightSum;
            if ( Dijk[nextnode] > w){
                Dijk[nextnode] = w;
                pq.push({nextnode, w});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);

    cin >> N >> M >> X;

    for(int i = 0 ; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    D(X);

    for(int i = 1 ; i < N+1; i++){
        cnt[i] = Dijk[i];
    }

    for(int i = 1; i < N+1; i++){
        if (i == X){
            continue;
        }
        else{
            D(i);
            cnt[i] += Dijk[X];
        }
    }

    int max = *std::max_element(cnt, cnt+N+1);
    cout << max;
    

}