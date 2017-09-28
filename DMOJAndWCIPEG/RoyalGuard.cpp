#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int N, M, x, y;

vii xs, ys, tp;

int main(){
	scanf("%d", &N);
	for(int i =0; i < N; i++){
		scanf("%d %d", &x, &y);
		xs.push_back(ii(x,  y)); ys.push_back(ii(y, x));
	}
	sort(xs.begin(), xs.end()); 
	sort(ys.begin(), ys.end());
	scanf("%d", &M);
	for(int i =0 ; i < M; i++){
		scanf("%d %d", &x, &y);
		tp.push_back(ii(x, y));
	}
	//for(ii p : ys) printf("(%d, %d), ", p.second, p.first); cout << endl;
	//for(ii p : xs) printf("(%d, %d), ", p.first, p.second); cout << endl;
	ii prev, curr;
	int sIdx = -1, eIdx = -1, minC, maxC;
	vii::iterator iter;
	long long tot = 0;
	for(int i =0; i < M-1; i++){
		prev = tp[i]; curr = tp[i+1];
		//printf("(%d, %d) and (%d, %d)\n", prev.first, prev.second, curr.first, curr.second);
		if(prev.second == curr.second){
			//x coords are equal
			minC = min(prev.first, curr.first);
			maxC = max(prev.first, curr.first);
			iter = lower_bound(ys.begin(), ys.end(), ii(prev.second, minC));
			sIdx = iter-ys.begin();
			if(iter == ys.end() || ys[sIdx].first != prev.second) continue;
			//printf("%d %d\n", ys[sIdx].second, ys[sIdx].first);
			iter = upper_bound(ys.begin(), ys.end(), ii(prev.second, maxC));
			eIdx = iter-ys.begin()-1;
			if(ys[eIdx].first != prev.second) continue;
			//printf("%d %d\n", ys[eIdx].second, ys[eIdx].first);
			//printf("%d, %d\n", sIdx, eIdx);
			tot += eIdx-sIdx+1;
		}else{
			minC = min(prev.second, curr.second);
			maxC = max(prev.second, curr.second);
			iter = lower_bound(xs.begin(), xs.end(), ii(prev.first, minC));
			sIdx = iter-xs.begin();
			//cout << sIdx << endl;
			if(iter == xs.end() || xs[sIdx].first != prev.first) continue;
			//printf("%d %d\n", xs[sIdx].first, xs[sIdx].second);
			iter = upper_bound(xs.begin(), xs.end(), ii(prev.first, maxC));
			eIdx = iter-xs.begin()-1;
			if(xs[eIdx].first != prev.first) continue;
			//printf("%d %d\n", xs[eIdx].first, xs[eIdx].second);
			//cout << sIdx << ", " << eIdx << endl;
			tot += eIdx-sIdx+1;
		}
		//cout << tot << endl;
	}
	cout << tot << endl;
	return 0;
}