#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ii;
int N, M, T;
ii people[100010];
long long times[110];

int main(){
	scanf("%d %d %d", &N, &M, &T);
	for(int i =0; i < M; i++) scanf("%lld %lld", &people[i].first, &people[i].second);
	sort(people, people+M);
	long long best = 0x3f3f3f3f3f3f3f3fLL;
	for(int i =0; i < M; i++){
		bool found = false;
		for(int j = N-1; j >= 0; j--){
			if(times[j] <= people[i].first){
				//cout << "YES: " << j << endl;
				if(times[j]+T <= people[i].first)
					best = min(best, times[j]);
				times[j] = people[i].first;
				times[j] += people[i].second;
				found = true;
				break;
			}
		}
		if(!found){
			//cout << "YES" << endl;
			long long bT = times[0];
			int idx = 0;
			for(int j = 1; j < N; j++){
				if(bT > times[j]){
					bT = times[j];
					idx = j;
				}
			}
			if(times[idx]+T <= people[i].first) best = min(best, times[idx]);

			times[idx] = max(times[idx], people[i].first);
			times[idx] += people[i].second;
		}

		sort(times, times+N);

		//printf("%lld %lld, %lld\n", people[i].first, people[i].second, best);
		//for(int i =0;i < N; i++) printf("%lld, ", times[i]); cout << endl;
		//if(best != 0x3f3f3f3f3f3f3f3fLL) break;
	}
	best = min(best, times[0]);
	for(int i = 0; i < N; i++) best = min(best, times[i]);
	cout << best << endl;

	return 0;
}