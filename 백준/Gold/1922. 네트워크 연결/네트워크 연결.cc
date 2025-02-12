#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>


using namespace std;

int n,e;
//int time[501];
int p[1001];

struct Data {
	int s;
	int e;
	int dist;
};

struct cmp {
	bool operator()(Data a, Data b) {
		return a.dist < b.dist;
	}
};

int find(int a){
    if(p[a] < 0){
        return a;
    }

    // 찾으러 갈때 업데이트를 해두기
    return p[a] = find(p[a]);
}

void merge(int a, int b){
    int aroot = find(a);
    int broot = find(b);

    if(aroot == broot){
        return;
    }

    p[aroot] = broot;


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    //freopen("input.txt","r", stdin);

	cin >> n >> e;
	vector<Data> v;

    for(int i = 1 ; i < n+1; i++){
        p[i] = -1;
    }

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		Data data;
		data.s = a;
		data.e = b;
		data.dist = c;

		v.push_back(data);
	}

	sort(v.begin(), v.end(), cmp());

	// for (int i = 0; i < v.size(); i++) {
	// 	cout << v[i].s << " " << v[i].e << " " << v[i].dist << " " << "\n";
	// }

    int ans = 0;
    int cnt = 0;
    
    for(int i = 0 ; i < v.size(); i++){

        Data cur = v[i];
    
        int s = cur.s;
        int e = cur.e;
        int dist = cur.dist;

        //cout << "s : " << s << " e : " << e << " dist : " << dist <<"\n";
        // cout << "find : " << find(s);
        if(find(s) != find(e)){
            merge(s,e);
            ans += dist;
            cnt++;
        }

         if(cnt == n){
            break;
        }
    }

    cout << ans;
}