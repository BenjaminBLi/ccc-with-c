#include <bits/stdc++.h>
#define fori(i, n) for(int i = 0;i < n; i++)
#define f first
#define s second
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
struct grid{
	string name;
	int s[3], total;
	string prev;
};

bool comp(grid a, grid b){
	if(a.total == b.total){
		if(a.s[2] == b.s[2]){
			if(a.s[1] == b.s[1]){
				return a.s[0] > b.s[0];
			}
			return a.s[1] > b.s[1];
		}
		return a.s[2] > b.s[2];
	}
	return a.total > b.total;
}
bool equal(grid a, grid b){
	if(a.total != b.total){
		return false;}
		for(int i =0;i < 3; i++) if(a.s[i] != b.s[i]) return false;
	return true;
}
grid id[110];
bool flag[110];
int main(){
	//freopen("DATA22.txt", "r", stdin);
	fori(t, 10){
		int N; scanf("%d", &N);
		grid clean;
		memset(flag, false, sizeof(flag));
		for(int i =0;i < 110; i++){
			id[i] = clean;
		}
		int cnt = -1;
		string line;
		while(cnt < N){
			cin >> line;
			if(line[0] == '*') break;
			if(line[0] != 'J'){
				id[++cnt].name = line;
			}else{
				int val;
				cin >> val;
				id[cnt].s[0] += val;
				id[cnt].total += val; 
				cin >> val; 
				id[cnt].s[1] += val; 
				id[cnt].total += val;
				cin >> val;
				id[cnt].total += val;
				id[cnt].s[2] += val;
			}
		}
		sort(id, id+N, comp);
		grid tmp; tmp.total = -1;
		flag[0] = true;
		cnt = 1;
		for(int i =1;i < N; i++){
			if(equal(id[0], id[i])) {
				flag[i] = true;
				cnt++;
			}
		}
	//	cout << cnt << endl;
		for(int i =0;i < N; i++){
			if(flag[i]){
				cout << id[i].name;
				if(--cnt > 0) cout << ",";
			}
		}
		cout << endl;
	}

	return 0;
} 