#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
deque<ii> q;

int N, K; 
long long arr[200010];

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) {
		scanf("%lld", arr+i);
		arr[N+i] = arr[i];
	}
	ll psum = 0;
	ll ans = -0x3f3f3f3f3f3f3f3fLL;
	for(int i =0; i < N<<1; i++){
		psum += arr[i];
		if(!q.empty()){
			while(!q.empty() && i-q.front().s > K) q.pop_front();
			ans = max(ans, psum-q.front().f);
			while(!q.empty() && q.back().f >= psum){q.pop_back();}
			q.push_back(ii(psum, i));
		}else{
			ans = max(ans, psum);
			q.push_back(ii(psum, i));
		}
	}

	printf("%lld\n", ans);
	//
	return 0;
}