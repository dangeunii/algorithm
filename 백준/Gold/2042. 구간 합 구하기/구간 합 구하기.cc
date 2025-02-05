#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M, K;
long long arr[20000001];


void construct(long long max) {
	for (int i = max - 1; i > 0; i--) {
		arr[i] = arr[2 * i] + arr[2 * i + 1];
	}
}

void update(int idx, long long x) {
	int tmp = idx;
	//cout << "tmp " << tmp << "\n";
	arr[tmp] = x;

	while (tmp) {
		tmp = tmp / 2;
		arr[tmp] = arr[2 * tmp] + arr[2 * tmp + 1];
	}
}

// 이건 재귀함수로 작성하려고 한다.
long long sum(int max, int idx, int s, int e, int i, int j) {
	//cout << "idx : " << idx << "\n"; 
	//cout << "s : " << s << " e : " << e << " i : " << i << " j : " << j << "\n";
	// 기저조건이 중요
	// s,e가 주어진 범위인 i~j를 벗어나서 존재하는 경우에는 return
	if (s > j || e < i) {
		//cout << "!!";
		return 0;
	}
	if (idx > max) {
		//cout << "!!!";
		return arr[idx];
	}

	// 주어진 범위가 s~e에 모두 들어가는 경우 
	if (s >= i && e <= j) {
		return arr[idx];
	}
	// 그렇지 않다면 만족하는 노드로 재귀를 돌면서 찾기
	else {
		int mid = (s + e) / 2;
		//cout << "mid : " << mid << "\n";
		return sum(max, 2 * idx, s, mid, i, j) + sum(max, 2 * idx + 1, mid + 1, e, i, j);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> K;
	int h = (int)ceil(log2(N));
	//cout << "h : " << h << " \n";
	long long max = (1 << (h));

	//cout << "max : " << max << " \n";

	for (int i = 0; i < N; i++) {
		cin >> arr[max + i];
	}
	construct(max);


	for (int i = 0; i < M+K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		
		// b번째 수를 c로 변경하기
		if (a == 1) {
			update(max + b -1 , c);
			//cout << "b : " << max + b -1 << " c : " << c << "\n";
			//for (int i = 1; i < 2 * max; i++) {
				//cout << arr[i] << " ";
			//}
		}
		// b~c까지 구간의 합 구하기
		else if (a == 2) {
			cout << sum(max, 1, 0, max - 1, b-1, c-1) << "\n";
		}
	}

}
