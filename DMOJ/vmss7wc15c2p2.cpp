#include <bits/stdc++.h>
using namespace std;

int N;
char str[25010];

void printStr(int st, int len){
	for(int i = 0;i < len;i++){
		printf("%c", str[st+i]);
	}
}

void solve(){
	int maxL = 1, st = 0;
	int lo, hi;
	for(int i = 1; i < N; i++){
		//cout << i << endl;
		for(lo = i-1, hi = i; str[lo] == str[hi] && lo >= 0 && hi < N; lo--, hi++){
			if(hi-lo+1 > maxL){
				//cout << hi << ", " << lo << endl;
				maxL = hi-lo+1;
				st = lo;
			}
		}
		for(lo = i-1, hi = i+1; str[lo]==str[hi] && lo >= 0 && hi < N; lo--, hi++) if(hi-lo+1 > maxL){
			//cout << hi << ", " << lo << endl;
			maxL = hi-lo+1;
			st = lo;
		}
	}
	printStr(st, maxL);
	//cout << "DONE" << endl;
	printf("\n%d", maxL);
}

int main(){
	scanf("%d", &N);
	for(int i =0;i < N; i++) scanf(" %c", str+i);
	solve();

	return 0;
}