#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
using namespace std;
typedef pair<long long, long long> ii;
int C, N;
long long c[20010], cnt[20010];
bool covered[20010];
ii n[20010];

bool comp(ii a, ii b){
	if(a.second-a.first == b.second-b.first){
		if(a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
	return a.second-a.first < b.second-b.first;
}

int main(){
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);
	scanf("%d %d", &C, &N);
	fori(i, C) scanf("%lld", &c[i]);
	long long  a, b;
	fori(i, N){
		scanf("%lld %lld", &a, &b);
		//printf("%d %d\n", a, b);
		n[i] = ii(a, b);
		//cout << n[i].first << ", " << n[i].second << endl;
	}
	sort(c, c+C); sort(n, n+N); 
	memset(covered, false, sizeof(covered));
	for(int j = 0; j < N; j++){
		for(int i =0; i < C; i++){
			if(!covered[i] && c[i] >= n[j].first && c[i] <= n[j].second){
				covered[i] = true;
				break;
			}
		}
	}

	int cnt = 0;
	for(int i =0; i < N; i++) if(covered[i]) cnt++;
	cout << cnt << endl;

	return 0;
}