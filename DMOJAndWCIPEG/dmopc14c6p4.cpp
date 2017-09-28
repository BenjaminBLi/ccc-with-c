#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int N, M, a, b, good[100110], bad[100110];

int main(){
	scanf("%d %d", &N, &M);
	//int a, b;
	//cout << "DONE" << endl;
	long long totMass = 0, sG = 0, sB = 0, bCnt = 0, gCnt = 0;
	for(int i =0 ; i < N; i++){
		scanf("%d %d", &a, &b);
		if(b == 1) {
			bad[bCnt++] = a;
			sB += a;
		}
		else {
			good[gCnt++] = a;
			sG += a;
		}
		totMass += a;
	}
	sort(bad, bad+bCnt);
	sort(good, good+gCnt);

	if(sG+sB <= M) printf("%lld\n", bCnt + ((gCnt)<<1));
	else{
		int best = 0;
		int p1 = gCnt-1;
		sB = 0; 

		for(int i = 0; i < bCnt; i++){
			//printf("%d: %d\n", p1+1, sG);
			if(sB + sG > M)
				while(sB + sG > M && p1 >= 0) 
					sG -= good[p1--];
			if(sB+sG <= M) best = max(best, i + ((p1+1)<<1));
			sB += bad[i];
			if(sB + sG > M)
				while(sB + sG > M && p1 >= 0) 
					sG -= good[p1--];
			if(sB+sG <= M) best = max(best, i+1 + ((p1+1)<<1));
			
		}
		cout << best << endl;
	}
	return 0;
}