#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int n, a[100010], val[100010], ft[100010], memo[100010], pre[100010];
map<int, int> id;

void upd(int a, int val){
	for(;a <= n; a += a&(-a)) ft[a] += val;
}

int q(int idx){
	int ret = 0;
	for(; idx; idx -= idx&(-idx)) ret += ft[idx]; 
	return ret;
}


int main(){
	scanf("%d", &n);
	int tmp;
	fori(i, 1, n+1){
		scanf("%d", &tmp);
		upd(i, 1);
		id[tmp] = i;
	}
	fori(i, 1, n+1){
		scanf("%d", &tmp);
		a[i] = id[tmp];
	}
	int l = 1, r = 1, ans = 1;
	memo[1] = 1, pre[1] = 0;

	fori(i, 2, n+1){
		if(a[i] > a[i-1]) {
			memo[i] += memo[i-1]+1, pre[i] = pre[i-1];
		}
		else memo[i] = 1, pre[i] = i;
		if(memo[i] > ans){
			l = pre[i];
			ans = memo[i];
			r = i;
		}
	}
	printf("%d\n", n-ans);
	fori(i, r+1, n+1){
		printf("B %d\n", q(a[i]));
		upd(a[i], -1);
	}
	rfori(i, l-1, 1){
		printf("F %d\n", q(a[i]) + (l-1-i));
		upd(a[i], -1);
	}
	return 0;
}
