#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

long long dist(ii a, ii b){
	return (1.0*a.first-b.first)*(a.first-b.first) + (1.0*a.second-b.second)*(a.second-b.second);
}

int N;
ii pts[20];

int main(){
	scanf("%d", &N);
	for(int i =0; i < N; i++) scanf("%d %d", &pts[i].first, &pts[i].second);
	long long best = 0;	
	for(int i=0; i < N; i++) for(int j = i+1; j < N; j++){
		//cout << dist(pts[i], pts[j]) << endl;
		best = max(dist(pts[i], pts[j]), best);
	}
	printf("%.2lf", round(sqrt(best)*100)/100);

	return 0;
}