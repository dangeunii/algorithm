#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<pair<int,int>> adj[10001];
vector<priority_queue<int>> dist(10001);

int n,m,k;

// 다익스트라에서 사용할 비교op
struct cmp{
    bool operator()(pair<int, int> a, pair<int,int> b){
        a.second > b.second;
    }
};

//dist pq에서 max heap으로 사용할 비교 op
struct cmp2{
    bool operator()(pair<int,int> a, pair<int, int> b){
        a.second < b.second;
    }
};

void D(int start){
    // min heap
    priority_queue <pair<int,int>, vector<pair<int,int>>> pq;
    pq.push({start, 0});
    dist[start].push(0);

    while(pq.size()>0){
        pair<int,int> now = pq.top();
        int nownode = now.first;
        int weightSum = now.second;
        pq.pop();

        if (dist[nownode].size() == k && dist[nownode].top() < weightSum) continue;

       for(auto &next : adj[nownode]){
        int nextnode = next.first;
        int nextweight = next.second;

        // k 보다 작으면 그냥 넣기
        if (dist[nextnode].size() < k) {
            dist[nextnode].push(weightSum+nextweight);
            pq.push({nextnode, weightSum+nextweight});
        }
        else{
            int x = dist[nextnode].top();
            if(x > weightSum + nextweight){
                dist[nextnode].pop();
                pq.push({nextnode, weightSum+nextweight});
                dist[nextnode].push(weightSum+nextweight);
            }
        }
        
       }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt" ,"r", stdin);

    
    cin >> n >> m >> k;

    for(int i = 0; i < m ; i ++){
        int a,b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    D(1);
    for(int i = 1 ; i<=n; i++){
        // k번째 길이의 경로 존재 안함
        if(dist[i].size() < k){
            cout << -1 <<"\n";
        }
        else{
            cout << dist[i].top() << "\n";
        }
    }
}