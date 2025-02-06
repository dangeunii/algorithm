#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

void push(int x){

    st.push(x);
    return;
    
}

int pop(){

    if(st.empty() == 1){
        return -1;
    }
    else{
        int tmp  = st.top();
        st.pop();
        return tmp;

    }
    
}

int size(){

    return st.size();

}

int empty(){
    if(st.empty() == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int top(){
    if(st.empty() == 1){
        return -1;
    }
    else{
        return st.top();
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    while (n --)
    {
       string s;
        cin >> s;

        if(s == "push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(s == "pop"){
            cout << pop() << "\n";
        }
        else if(s == "top" ){
            cout << top() << "\n";
        }
        else if(s == "empty"){
            cout << empty() << "\n";
        }
        else if(s == "size"){
            cout << size() << "\n";
        }
    }
     

}

