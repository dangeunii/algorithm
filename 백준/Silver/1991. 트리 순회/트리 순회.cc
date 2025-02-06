#include<iostream>

using namespace std;

int N;
int tree[30][2];
int visited[30];

// 자식노드 먼저 탐색
void preorder(int n){
    // 방문하지 않았을때
    if(visited[n] == 0){
        visited[n] = 1;
        char a = n + 'A'; 
        cout << a;
        if(tree[n][0] != -19){
            preorder(tree[n][0]);
        }
        if(tree[n][1] != -19){
            preorder(tree[n][1]);
        }
    }
}

// 나먼저 탐색
void postorder(int n){
    // 방문하지 않았을때
    if(visited[n] == 0){
        if(tree[n][0] != -19){
            postorder(tree[n][0]);
        }
        if(tree[n][1] != -19){
            postorder(tree[n][1]);
        }
        visited[n] = 1;
        char a = n + 'A'; 
        cout << a ;
    }
}

// 가운데에 끼었다.
void inorder(int n){
    // 방문하지 않았을때
    if(visited[n] == 0){
        if(tree[n][0] != -19){
            inorder(tree[n][0]);
        }
        visited[n] = 1;
        char a = n + 'A'; 
        cout << a;
        if(tree[n][1] != -19){
            inorder(tree[n][1]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> N;

    for(int i = 0; i< N; i++){
        char node, left, right;
        cin >> node >> left >> right;

        int n = node - 'A';
        tree[n][0] = left - 'A';
        tree[n][1] = right - 'A';
        // .일 떄  = -19
    }

    preorder(0);
    std::fill_n(visited, 30, 0);
    cout << "\n";
    inorder(0);
    std::fill_n(visited, 30, 0);
    cout << "\n";
    postorder(0);


}