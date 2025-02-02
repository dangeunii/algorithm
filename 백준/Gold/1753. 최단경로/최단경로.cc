#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define INF INT_MAX

using namespace std;

typedef struct
{
    int node;
    int weight;
} Data;

vector<Data> adj[20001];
int Dijk [20001];

struct cmp{
    bool operator()(Data a, Data b){
        return a.weight > b.weight;
    }
};

priority_queue< Data, vector<Data>, cmp> pq;

int V, E;
int start;

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    cin >> V >> E;
    cin >> start;

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >>  v >> w;

        adj[u].push_back({v,w});
    }

    for (int i = 0 ; i < V; i++){
        Dijk[i+1] = INF;
    }

    pq.push({start, 0});
    Dijk[start] = 0;

    while(pq.size()>0){
        int nownode = pq.top().node;
        int weightSum = pq.top().weight;
        pq.pop();

        if(Dijk[nownode] < weightSum){
            continue;
        }

        for(int i = 0 ; i < adj[nownode].size(); i ++){
            int nextnode = adj[nownode][i].node;
            int weight = adj[nownode][i].weight;

            if(Dijk[nextnode] > weight + weightSum){
                Dijk[nextnode] = weight + weightSum;
                pq.push({nextnode, weight+weightSum});
            }

        }
    }

    for(int i = 0 ; i < V; i++){
        if (Dijk[i+1] == INF){
            cout << "INF" << "\n";
        }
        else{
            cout << Dijk[i+1] << "\n";
        }
    }

}