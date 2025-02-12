#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

const int INF = 1e9;
using namespace std;
vector<int> adj[501];
int dist[501][501];
int path[501];
set<int> s;

int main(){

    //freopen("input.txt","r",stdin);

    int n,m;
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
    }

    for(int i  = 0 ; i < m ; i ++){
        int a, b;
        cin >> a >> b;

        dist[a][b] = 1;
    }

   
    

    for(int k = 1 ; k <= n; k++){
        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    // for(int i = 1 ; i <= n ; i ++){
    //     for(int j = 1 ; j <= n; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1 ; i <= n ; i++){
        for (int j = 1; j <= n; j++){
            if(i == j) continue;
            if(dist[i][j] < INF){
                path[i]++;
                path[j]++;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i<= n; i++){
        ans+= (path[i] == n-1);
    }
    
    cout << ans;
}