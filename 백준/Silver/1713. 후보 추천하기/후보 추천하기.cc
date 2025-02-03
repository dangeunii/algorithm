#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

   //freopen("input.txt", "r", stdin);

	int N, M;
	int arr[101];
	int time[101] = {0};
	int reco[101] = {0};

	cin >> N >> M;

	int cnt = 0;

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;

		//cout << "x : " << x << "\n";
		//이미 추천 받은 경우
		if (reco[x] > 0) {
			reco[x]++;
		}
		// 추천 받은 적이 없다면 일단 틀이 비었나 확인
		else {
			if (cnt < N) {
				reco[x] = 1;
				time[x] = i+1;
				cnt++;
				//cout << "cnt : " << cnt << "\n";
			}
			// 틀이 안비었어 -> 먼저 추천수 확인하기
			else {
				// 일단 최소 추천수를 갖는 학생 찾기
                int ridStudent = -1;
                int comtime = 1001;
                int comreco = 1001;

                for(int j = 1 ; j < 101; j++){
                    if(reco[j] != 0 && comreco > reco[j]){
                        comreco = reco[j];
                    }
                }

                for(int j = 1; j < 101; j++){
                    // 가장 오래된, time이 작은애를 ridStudent로 지정
                    if (reco[j] == comreco)
                    {
                        if(comtime > time[j]){
                            comtime = time[j];
                            ridStudent = j;
                        }
                    }
                }

                //cout << "ridStudent : " << ridStudent << " reco : " << reco[ridStudent] << " time : " << time[ridStudent] << "\n";  

                //찾은 ridStudent를 기준으로 삭제 및 새로운 학생 넣기
                reco[ridStudent] = 0;
                time[ridStudent] = 0;

                reco[x] = 1;
                time[x] = i+1;
			}
		}
	}

	int k = 0;
	for (int i = 1; i < 101; i++) {
		if(reco[i]>0){
            arr[k] = i;
            k++;
        }
	}

	
	sort(arr,arr+k);

	for (int i = 0; i < k; i++) {
		cout << arr[i] << " ";
	}
}
