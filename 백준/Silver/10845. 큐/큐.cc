#include<iostream>
#include<queue>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);

    int N;
    cin >> N;

    queue<int> q;
    for(int i = 0; i<N;i++){
        string op;
        cin >>op;
        //cout << op << " ";
        if(op == "push"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(op == "pop"){
            if(!q.empty()){
                cout << q.front() <<"\n";
                q.pop();
            }
            else{
                cout << -1 <<"\n";
            }
        }
        else if(op == "size"){
            cout << q.size() <<"\n";
        }
        else if(op == "empty"){
            if(!q.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << 1<<"\n";
            }
        }
        else if(op == "front"){
            if(!q.empty()){
                cout << q.front() <<"\n";
            }
            else{
                cout << -1<<"\n";
            }
        }
        else if(op == "back"){
            if(q.empty()){
                cout << -1 <<"\n";
            }
            else{
                cout << q.back() <<"\n";
            }
        }
    }
}