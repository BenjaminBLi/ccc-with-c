#include <bits/stdc++.h>
using namespace std;

int table[20][1000010];
int N, arr[1000010];

int nor(int a, int b){
	if(a == 0 && b == 0) return 1;
	return 0;
}

int main(){
	scanf("%d", &N);
	for(int i =1;i <= N; i++)
		scanf("%d", &arr[i]);
	int Q;
	scanf("%d", &Q);
	
	for(;Q--;){
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = nor(arr[a], arr[a+1]);
		//cout << "ans: " << ans << ", ";
		for(int i = a+2; i <= b; i++){
			//cout << "i: " << i << " gives ";
			ans = nor(ans, arr[i]);
			//cout << ans << ", ";
		}
		//cout << endl;
		printf("%d\n", ans);
	}

	return 0;
}