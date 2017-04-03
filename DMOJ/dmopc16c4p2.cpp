#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int B, F, arr[100010];
//unordered_set<int> idxs, oIdx;
vector<int> idxs, oIdx;
bool valid[100010];
//int pts[100010];

struct batch{
	int l, r, p;
};
batch bs[100010];
bool comp(batch a, batch b){
	if(a.l == b.l){
		if(a.r == b.r) return a.p < b.p;
		return a.r < b.r;
	}
	return a.l < b.l;
}

int main(){
	scanf("%d", &B);
	int a;
	long long total = 0;
	for(int i =0; i < B; i++) {
		scanf("%d %d %d", &bs[i].l, &bs[i].r, &bs[i].p);
		total += bs[i].p;
		idxs.push_back(i);
	}
	//cout << total << endl;
	sort(bs, bs+B, comp);
	scanf("%d", &F);
	//for(int i =0 ;i < B; i++) printf("(%d, %d), ", batch[i].first, batch[i].second); cout << endl;
	//int lowestIdx = 0;
	for(int i =0; i < F; i++) {
		scanf("%d", &a);
		//printf("%d: ", a);
		for(int idx : idxs){
			//if(bs[idx].l > a) break;
			if( bs[idx].l <= a && bs[idx].r >= a){
				//lowestIdx = min(lowestIdx+1, i);
				//printf("%d %d\n", bs[idx].l, bs[idx].r);
				total -= bs[idx].p;
			}else{
				oIdx.push_back(idx);
			}
		}
		idxs = oIdx;
		//cout << endl;
		oIdx.clear();
	}
	printf("%lld\n", total);
	return 0;
}