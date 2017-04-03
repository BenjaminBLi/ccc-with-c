#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, D;
ii pts[100010];

int getDist(ii a, ii b){
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

bool valid(ii a, ii b){
	return getDist(a, b) <= D;
}

int main(){
	scanf("%d %d", &N, &D);
	D *= D;
	for(int i =0; i < N; i++){
		scanf("%d %d", &pts[i].first, &pts[i].second);
	}

	int best = 0, combo = 1;
	bool miss = false;
	for(int i = 1; i < N; i++){
		if(miss){
			combo++;
			miss = false;
			continue;
		}
		if(valid(pts[i], pts[i-1])) combo++;
		else{
			best = max(combo, best);
			miss = true;
			combo = 0;
		}
	}
	best = max(combo, best);
	printf("%d\n", best);

	return 0;
}