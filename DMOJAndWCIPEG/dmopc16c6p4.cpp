#include <bits/stdc++.h>
using namespace std;

int N, M, H, T, arr[1010], diff[1010];

int main(){
	scanf("%d %d %d", &N,&M,&H);
	for(int i =0;i < N; i++){
		scanf("%d", arr+i);
	}
	int cnt=0, diff = 0;
	for(int i = N-1; i > 0;i--){
		diff = arr[i]-arr[i-1];
		if(diff > H){
			cnt += ceil(1.0*(diff-H)/M);
			arr[i-1] += ceil(1.0*(diff-H)/M)*M;
		}
		//for(int i =0;i < N; i++) printf("%d, ", arr[i]); cout << endl;
	}
	printf("%d\n", cnt);

	return 0;
}