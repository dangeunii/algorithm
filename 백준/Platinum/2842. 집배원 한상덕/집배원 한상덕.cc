#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// 탐색 시 사용할 방향 벡터
int dy[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dx[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

// 처음 시작 점( 점 P의 위치)
int sy, sx;

int m[51][51];
int home[51][51];
int visited[51][51];
//int t[51][51];
// 나중에 중복 피하기
vector<int> t;
int N;
int low, high;

vector<vector<int>> v;


int dfs(int y, int x) {
    int cnt = 0;
	visited[y][x] = 1;
    if(home[y][x] == 1){
        cnt++;
    }

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

        //cout << "ny, nx : " << ny << " " << nx << "\n";

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
			continue;
		}

		if (visited[ny][nx] == 0 && m[ny][nx] <= t[high] && m[ny][nx]>= t[low]) {
            //cout << "ny, nx : " << ny << " " << nx << " m: " << m[ny][nx] << " home : " << home[ny][nx];
			cnt += dfs(ny, nx);
		}
	}
	//cout << "cnt : " << cnt << "\n";
	return cnt;
}

int main() {
    //freopen("input.txt","r",stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			if (c == 'P') {
				sy = i;
				sx = j;
				home[i][j] = 1;
			}
			else if (c == 'K') {
				v.push_back({ i,j });
				home[i][j] = 1;
			}

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int k;
			cin >> k;
			t.push_back(k);
			m[i][j] = k;
		}
	}

	// cout << "map" << "\n";
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < N; j++) {
	// 		cout << m[i][j];
	// 	}
	// 	cout << "\n";
	// }

	// cout << "v  \n";
	// for (int i = 0; i < v.size(); i++) {
	// 	for (int j = 0; j < v[i].size(); j++) {
	// 		cout << v[i][j];
	// 	}
	// 	cout << "\n";
	// }

    // cout << "home  \n";
    // for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < N; j++) {
	// 		cout << home[i][j];
	// 	}
	// 	cout << "\n";
	// }

	sort(t.begin(), t.end());
    // 중복값 제거
    t.erase(unique(t.begin(), t.end()), t.end());

	low =0; high = 0;
	int tired = t[t.size() - 1];

	while (low < t.size() && high < t.size() && low <= high) {
        //cout << "low : " << low << " high : " << high << " tired : " << tired << "\n";
		//그래프 탐색 후 가능하면 1 불가능이면 0 리턴

        //visited 배열 초기화
        memset(visited, 0, sizeof(visited));

		if (m[sy][sx] <= t[high] && m[sy][sx] >= t[low] && dfs(sy, sx) == v.size()+1) {
			tired = min(tired, t[high] - t[low]);
			low++;
		}
        else{
            high++;
        }
		

	}

	cout << tired; 

}
