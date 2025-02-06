#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

//최대공약수 구하기
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int r[1 << 10];
int s[1 << 10];
int t[1 << 10];

int euclid(int i) {
    
	int q;
	int g =1;

	while (g > 0) {
		q = r[i] / r[i + 1];
		g = r[i] % r[i + 1];
		r[i + 2] = g;

		s[i + 2] = s[i] - s[i + 1] * q;
		t[i + 2] = t[i] - t[i + 1] * q;
		//cout << "s : " << s[i+2] << "\n";
		//cout << "t : " << t[i + 2] << "\n";
		//cout << "r : " << r[i + 2] << "\n";
		//cout << "q : " << q << "\n";
		i++;
	}
	//cout << " i : " << i << "\n";
	//cout << "값 : " << t[i] << "\n";
	return i;
}


int  N;
int ans;
int main() {
	//freopen("input.txt","r",stdin);
    cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		
		//최대공약수가 1이 아니라면 불가능 , 10^9가 넘어가는 사탕봉지는 구매 불가능
		if (gcd(a, b) != 1 || ((a >= 1000000000)&& b == 1)) {
			cout << "IMPOSSIBLE\n";
		}
        // 봉지에 담겨있는 사탕이 한개뿐이라면 사람 수 +1
        else if(b == 1){
            cout << a+1 << "\n";
        }
        // 사람수가 1명이라면
        else if(a == 1 && a < b){
            cout << 1 << "\n";
        }
        // 사람 수랑 봉지당 사탕 수가 정확히 일치하다면 사랆수 + 1개
        else if(a == b){
            cout << a+1 << "\n";
        }
		// 그럴때 C의 역원 찾기
		else {
			//확장 유클리드 알고리즘을 이용한 역원 구하기
			s[0] = 1;
			s[1] = 0;
			t[0] = 0;
			t[1] = 1;

			r[0] = a;
			r[1] = b;

			int value = euclid(0);

			/*
			for (int i = 0; i < 10; i++) {
				cout << t[i];
			}*/

			ans = t[value];
			if (ans < 0) {
				ans = ans + a;
				cout << ans << "\n";
				
			}
			else{
				cout << ans << "\n";
			}
			
		}
	}

}