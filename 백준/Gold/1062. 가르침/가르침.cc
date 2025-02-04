#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

int k, N;
int check[26];
int cnt = 0;
vector<char> compare;
int valid = 0;
int arr[51];
int ans = 0;
int checkSum = 0;

vector<char> vec = {'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'w', 'x', 'y', 'z'};
    

void combi(int start , vector<char> b, int checkSum){
    //기저 조건
    if (b.size() == k-5){
        int can = 0;
        // 문제에 나온 로직 추가
        for (int i = 0; i < N; i++){
            //cout << " arr : " << arr[i] <<"\n";
            //cout << checkSum << "\n";
            if((arr[i] & checkSum) == arr[i]){
                can++;
                //cout << "can++ :" << can <<"\n";
            }
        }
        ans = max(ans, can);
        return;
    }

    for(int i  = start+1; i < vec.size(); i ++){
        b.push_back(vec[i]);
        combi(i,b, checkSum | (1 << (vec[i]-'a')));
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

    char n[5] = {'a','n','t','c','i'};
    for(char c : n){
        checkSum |= 1 << (c - 'a');
    }
    //cout << checkSum;
 
    if(k < 5){
        cout << cnt;
    }
    else{
        for (int i = 0; i < N; i++){
            string s;
            compare.clear();
            cin >> s;
            int num = 0;
            //cout << "s : " << s << "\n";
            for(char c : s){
                // 비트 마스킹
                num |= 1 << (c- 'a'); 
                /*
                if(c != 'a' && c != 'n' && c != 't' && c != 'c' && c != 'i'){
                    compare.push_back(c);
                }*/
            }
            arr[i] = num;
            /*
            for(char c : compare){
                cout << c << " ";
            }*/
            //cout << "\n";

        }
        combi(-1, b, checkSum);
        cout << ans;
    }
    

}