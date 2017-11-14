#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

const int INF = 1000000000;
int n, ans, nxt[1001], memo[1001][5001];
char a[1001];

int solve(int idx, int rem){
	if(rem < 0) return INF;
	if(idx == n) return rem == 0 ? 0 : INF; 

	int ret = memo[idx][rem];
	if(ret != -1) return ret;

	ret = INF;
	int sum = 0;
	fori(i, nxt[idx], n){
		sum = sum * 10 + (a[i] - '0');
		if(sum > rem) break;
		int curr = 1 + solve(i+1, rem-sum); 
		if(ret > curr) ret = curr;
	}
	memo[idx][rem] = ret;
	return ret;
}

int printSol(int idx, int rem){
	if(idx == n) {
		printf("=%d\n", ans);
		return 1;
	}

	if(idx > 0) printf("+");

	int sum = 0;
	fori(i, idx, n){
		printf("%c", a[i]);
		sum = sum*10 + (a[i]-'0');
		if(solve(idx, rem) == 1 + solve(i+1, rem-sum)){
			return printSol(i+1, rem-sum);
		}
	}
	printf("REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n");
	return 0;
}

int main(){
	scanf("%[^=]=%d", a, &ans);
	n = strlen(a);
	
	nxt[n-1] = n-1;
	rfori(i, n-2, 0)
			nxt[i] = (a[i] == '0') ? nxt[i+1] : i;

	memset(memo, -1, sizeof(memo));

	printSol(0, ans);
	return 0;
}

