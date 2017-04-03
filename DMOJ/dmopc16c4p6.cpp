#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, Q, h[1000010];
long long ans[1000010];
stack<ii> s;


int main(){
	scanf("%d %d", &N, &Q);
	s.push(ii(-1, 0));
	for(int i =1, h =0 ; i <= N; i++){
		scanf("%d", &h);
		while(s.top().first > h){
			int p0 = s.top().second, h0 = s.top().first;
			s.pop();
			int r = i-p0, l = p0-s.top().second;
			ans[h0] += 1LL*r*l;
		}
		s.push(ii(h, i));
	}
	while(s.size() > 1){
		int p0 = s.top().second, h0 = s.top().first;
		s.pop();
		int r = N+1-p0, l = p0-s.top().second;
		ans[h0] += 1LL*r*l;
	}
	for(int i = 1; i <= 1000000; i++) ans[i] += ans[i-1];

		for(int i =0, x, y; i < Q; i++){
			scanf("%d %d", &x, &y);
			printf("%lld\n", ans[y]-ans[x-1]);
		}

	return 0;
}