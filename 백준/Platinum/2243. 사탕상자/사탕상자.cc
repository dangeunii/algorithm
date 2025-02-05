#include <iostream>

using namespace std;
int n;
long long MAX = 1<<20;
//int MAX = 4;
long long arr[1<<21];

//이렇게 하면 시간초과!!
void construct1(){
    for(int i = MAX-1; i > 0; i--){
        arr[i] = arr[2*i] + arr[2*i + 1];
    }
}

void construct(long long idx){
    // 리프 노드에서부터 위로 채우면서 올라오기
    // 근데 모든 점을 다 이렇게 채워주는 건 불가능
    // 따라서 값의 변화가 있는 idx에 대해서 update하기
    while(idx >= 1){
        idx = idx/2;
        arr[idx] = arr[2*idx] + arr[2*idx + 1];
    }
}

int search(long long idx, int num){
    //cout << "num : " << num << "\n ";
    //cout << "idx : " << idx << "\n";
    //cout << "arr : " << arr[idx] <<" \n";
     // 기저조건
    if (idx >= MAX){
        //cout << "!!";
        arr[idx]--;
        return idx-MAX+1;
    }

    if(arr[2*idx] >= num){
            // cout << "arr2 : " << arr[2*idx] <<" \n";
        return search(2*idx, num);
    }else{
        return search(2*idx+1, num - arr[2*idx]);
    }

}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        int op;
        cin >> op;
        //cout << " i : "<< i  <<"op: " << op << "\n";

        // for(int j = 1 ; j < 2*MAX; j++){
        //         cout << arr[j]<< " ";
        //     }
        // cout << " \n";

        // 상자에서 사탕 꺼내기
        if(op == 1){
            int num;
            cin >> num;
            //cout << "num : " << num << "\n";
            int ans= 0;
            ans = search(1,num);
            cout << ans << "\n";
            construct(ans+ MAX -1);
            
        }

        //양수 : 넣기, 음수 : 빼기
        if(op == 2){
            long long num, cnt;
            cin >> num >> cnt;

            // 사탕 넣고
            arr[MAX + num - 1] += cnt;

            // 세그먼트 트리 생성하기 - 업데이트
            construct(MAX + num -1);
        }

        
    }

}