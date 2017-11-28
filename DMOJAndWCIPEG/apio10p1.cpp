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

int n;
ll a, b, c, val[1000010];
ll memo[1000010];

ll f(int l, int r){
	int sm = val[r] - val[l-1];
	return a * sm*sm + b * sm + c; 
}

int main(){
	scanf("%d%lld%lld%lld", &n, &a, &b, &c);
	fori(i, 1, n+1) scanf("%lld", val+i), val[i] += val[i-1];
	memo[0] = 0;
	int st = 1;
	fori(i, 1, n+1){
		memo[i] = f(1, i);
		fori(j, st, i){
			if(memo[j] + f(j + 1, i) >= memo[i]){
				st = j;
				memo[i] = memo[j] + f(j + 1, i);
			}
		}
	}
	printf("%lld\n", memo[n]);
	return 0;
}

