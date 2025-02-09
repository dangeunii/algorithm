#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ans;
int arr[51][51];
int N, M, K, sum;
int answer = 1e9;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;


void find(vector<int> b){
    int a = 0;
    for(int j = 0 ; j < house.size(); j++){
        int dist = 1e9;
        int hy = house[j].first;
        int hx = house[j].second;
       

        for(int c : b){
             int cy = chicken[c].first;
            int cx = chicken[c].second;

            //cout << "cy : " << cy << " cx : " << cx << " hy : "<< hy << " hx : " << hx << "\n";
            dist = min(dist , (abs(cy - hy) + abs(cx - hx)));

            //cout << "dist : " << dist << "\n";
            
        } 
        a += dist;
        //cout << "answer :" << a << "dist : " << dist << "\n";
    }
    //cout << "answer :" << a << "\n";
    ans.push_back(a);
    return;
}

void combi(int start, vector<int> b){
    if(b.size() == M){
        // 로직 들어오고
        // 이제 이 b가 chicken에서의 idx이며 이걸 기준으로 house와의 거리를 비교하는 로직이 들어오면 된다.
        // for(int i = 0 ; i < b.size(); i++){
        //     cout << b[i] << " ";
        // }
        // cout << "\n";
        find(b);
        return;
    }

    for(int i = start +1; i < chicken.size(); i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }

    return;
} 

int main(){
    //freopen("input.txt", "r", stdin);

    cin >> N >> M;
    //cout << "   N : " << N << " M : " << M << "\n";
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                house.push_back({i,j});
            }
            else if(arr[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    } 

    vector<int> v;
    combi(-1, v);

    // for( int i = 0 ; i< ans.size(); i ++){
    //     cout << ans[i] << " \n";
    // }
    sort(ans.begin(), ans.end());
    cout << ans[0];
    //cout << answer;

    
}