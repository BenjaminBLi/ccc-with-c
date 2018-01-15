#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

int n, a[4], memo[1<<4][28562], ans = 0;

ll calc(int a, int b, int type){
	if(type == 0) return a + b;
	if(type == 1) return a * b;
	if(type == 2) return a - b;
	if(type == 3 && b != 0 && a%b == 0) return a/b;
	return 0x3f3f3f3f;
}

void solve(vi curr){
	if(curr.size() == 1){
		if(curr[0] > 24) return;
		ans = max(ans, curr[0]);
		return;
	}
	fori(i, 0, curr.size()){
		fori(j, 0, curr.size()){
			if(i == j) continue;
			fori(type, 0, 4){
				vi nxt;
				fori(k, 0, curr.size()) if(k != i && k != j) nxt.pb(curr[k]);
				nxt.pb(calc(curr[i], curr[j], type));
				solve(nxt);
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	while(n--){
		ans = 0;
		vi init;
		fori(i, 0, 4){
			int tmp;
			scanf("%d", &tmp);
			init.pb(tmp);
		}
		solve(init);
		printf("%d\n", ans);
	}
	return 0;
}