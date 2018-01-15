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

const int MAXN = 500010;
int n, m, pre[MAXN], nxt[MAXN], lst[MAXN], memo[MAXN];
bool inLis[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	fori(i, 1, n+10){
		pre[i] = i-1;
		nxt[i] = i+1;
	}
	char ch;
	int a, b;
	fori(i, 0, m){
		scanf(" %c%d%d", &ch, &a, &b);
		if(ch == 'A'){
			pre[nxt[a]] = pre[a];
			nxt[pre[a]] = nxt[a];
			pre[a] = pre[b];
			nxt[a] = b;
			pre[nxt[a]] = a;
			nxt[pre[a]] = a;	
		}else{
			pre[nxt[a]] = pre[a];
			nxt[pre[a]] = nxt[a];
			nxt[a] = nxt[b];
			nxt[b] = a;
			pre[a] = b;
			pre[nxt[a]] = a;
			nxt[pre[a]] = a;
		}
	}
	//fori(i, 1, n+1) printf("%d, ", pre[i]); cout << endl; fori(i, 1, n+1) printf("%d, ", nxt[i]); cout << endl;

	int st = -1;
	//generate ending list
	fori(i, 1, n+1) if(pre[i] == 0) st = i;
	int cnt = 0;
	for(int i = st; i <= n; i = nxt[i]) lst[cnt++] = i;

	//find longest increasing subsequence
	vi lis(n+1, MAXN);
	int ans = 0;
	fori(i, 0, n){
		auto it = lower_bound(lis.begin(), lis.end(), lst[i]);
		memo[i] = (int) (it - lis.begin()) + 1;
		ans = max(ans, memo[i]);
		*it = lst[i];
	}
	int tmp = ans;
	rfori(i, n-1, 0){
		if(memo[i] == tmp){
			inLis[lst[i]] = true;
			tmp--;
		}
	}
	cout << n-ans << endl;
	fori(i, 1, n+1){
		if(!inLis[i]){
			printf("B %d %d\n", i, i-1);
		}
	}
	
	return 0;
}

