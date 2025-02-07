#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[51][51];
int visited[55][55];

int dy[4] = { -1, 0 ,1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int N, M;
int dp[55][55];
bool isCycle = false;

int dfs(int y,int x) {
	
	// hole 이거나 범위를 넘어서면 0을 리턴해준다. 즉 종료한다.
	if(y < 0 || y >= N || x < 0 || x >= M || arr[y][x] == -1 ){
		return 0;
	}

	// 이미 방문을 한 노드다? => 사이클판정!
	if (visited[y][x] == 1){
		isCycle = true;
		return -1;
	}

	if(dp[y][x] != -1){
		return dp[y][x];
	}

	visited[y][x] = 1;
	dp[y][x] = 0;

	int num = arr[y][x];

	for(int i =0; i< 4; i++){
		int ny = y + dy[i] * num;
		int nx = x + dx[i] * num;

		dp[y][x] = max(dp[y][x], dfs(ny,nx) +1);

	}

	visited[y][x] = 0;
	return dp[y][x];

}

int main() {

	//freopen("input.txt","r",stdin);

	cin >> N >> M;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char x;
			cin >> x;
			if (x == 'H') {
				arr[i][j] = -1;
			}
			else{
				arr[i][j] = x-'0';
			}
		}
	}

	int result  = dfs(0, 0);
	
	if(isCycle){
		cout << -1;
	}
	else{
		cout << result;
	}
	

	
}