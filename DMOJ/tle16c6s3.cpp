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
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
int N;
ll memo[2010][2010][2];
ii h[2010];
bool taken[2010];

ll solve(int l, int r, int en){
	if(l > r) return 0;
    if(en){
        //solve(L+1, r, 0)
		//solve(l+1, r, r) - abs(dist[r] - dist[l])
	}else{
        //solve(l, r-1, R) - |dist[r]-dist[l]|
		//solve(l, r-1, L) - |dist[r] - dist[l]|
	}
}

int main(){
	scanf("%d", &N);
	for(int i =0;i < N; i++)
		scanf("%lld %lld", &h[i].first, &h[i].second);

	sort(h, h+N);
	int st = 0;
	for(int i =0; i < N; i++) if(h[i].first == 0) {st = i; break;}
	printf("%lld\n", max(solve(st, st, 0), solve(st, st, 1)));
	return 0;
}