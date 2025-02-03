#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    int N, M;
    int arr[101] = {0}; // 정렬할 학생 배열
    int time[101] = {0}; // 학생이 처음 추천받은 시간
    int reco[101] = {0}; // 학생이 추천받은 횟수

    cin >> N >> M;

    int cnt = 0;  // 게시판에 등록된 학생 수

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        // 이미 게시판에 있는 경우 추천 수 증가
        if (reco[x] > 0) {
            reco[x]++;
        }
        else {
            if (cnt < N) {  // 게시판에 자리 남아있을 경우
                reco[x] = 1;
                time[x] = i+1;  // 🔹 1-based index 유지
                cnt++;
            }
            else {  // 게시판이 가득 찼을 경우
                int ridStudent = -1;
                int comtime = 1001;
                int comreco = 1001;

                // 1️⃣ 최소 추천 수 찾기
                for (int j = 1; j < 101; j++) {
                    if (reco[j] > 0 && reco[j] < comreco) {
                        comreco = reco[j];
                    }
                }

                // 2️⃣ 최소 추천 수를 가진 학생 중 가장 오래된 학생 찾기
                for (int j = 1; j < 101; j++) {
                    if (reco[j] == comreco) {
                        if (time[j] < comtime) {
                            comtime = time[j];
                            ridStudent = j;
                        }
                    }
                }

                // 3️⃣ 해당 학생 삭제 (유효한 경우만)
                if (ridStudent != -1) {
                    reco[ridStudent] = 0;
                    time[ridStudent] = 0;
                }

                // 4️⃣ 새로운 학생 추가
                reco[x] = 1;
                time[x] = i+1;
            }
        }
    }

    // 5️⃣ 추천된 학생 목록을 배열에 저장
    int k = 0;
    for (int i = 1; i < 101; i++) {
        if (reco[i] > 0) { // 추천 수가 1 이상인 학생만 포함
            arr[k++] = i;
        }
    }

    // 6️⃣ 학생 번호 정렬
    sort(arr, arr + k);

    // 7️⃣ 정렬된 학생 번호 출력
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
