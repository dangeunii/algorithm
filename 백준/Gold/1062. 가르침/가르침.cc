#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

int k, N;
int cnt = 0;
vector<char> compare;
int valid = 0;
int arr[51][26];
int ans = 0;
int checkSum = 0;

vector<char> vec = {'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 'u', 'w', 'v', 'x', 'y', 'z'};
    

void combi(int start , vector<char> b){
    //기저 조건
    if (b.size() == k-5){
        int can = 0;
        int check[26] = {0};
        char n[5] = {'a','n','t','c','i'};
        for(char c : n){
            int idx = (c -'a');
            check[idx] = 1;
        }
        //cout << "\n";
        // 문제에 나온 로직 추가
        for(char  c: b){
            //cout << c << "\n";
            int idx = (c - 'a');
            check[idx] = 1;
        }
        /*

        for(int i = 0 ; i < 26; i++){
            cout << check[i] << " ";
        }
        cout << "\n";
*/
        for(int i = 0; i < N; i++){
            int flag = 1;
            for(int j = 0 ; j < 26; j++){
                if(arr[i][j] == 1 && check[j] == 0){
                    flag = 0;
                }
            }
            if (flag == 1) can++;
            //cout<< "can : " << can << "\n";
        }
        ans = max(ans, can);
    }

    for(int i  = start+1; i < vec.size(); i ++){
        b.push_back(vec[i]);
        combi(i,b);
        b.pop_back(); 
    }
    return;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    vector<char> b;

    cin >> N >> k;
 
    if(k < 5){
        cout << cnt;
    }
    else{
        for (int i = 0; i < N; i++){
            char n[5] = {'a','n','t','c','i'};
            for(char c : n){
                int idx = c -'a';
                arr[i][idx] = 1;
            }
            string s;
            compare.clear();
            cin >> s;
            int num = 0;
            //cout << "s : " << s << "\n";
            for(char c : s){
                int idx = c - 'a';
                arr[i][idx] = 1;
            }
            

        }

        /*
        for(int i = 0; i < N ; i++){
            for(int j = 0; j < 26; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        */
        combi(-1, b);
        cout << ans;
    }
    

}