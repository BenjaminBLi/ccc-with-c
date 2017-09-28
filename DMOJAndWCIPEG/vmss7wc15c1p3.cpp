#include <bits/stdc++.h>

using namespace std;

int N, K, arr[7010];

bool isPrime(int n){
	if(n == 2 || n == 3) return true;
	if(n%2 == 0) return false;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

void gen(){
	//memset(arr, 3, sizeof(arr));
	arr[1] = 0;
	for(int i = 2; i <= N; i++){
		if(isPrime(i)) arr[i] = 1;
		else if(i%2 == 0 || isPrime(i-2)) arr[i] = 2;
		else arr[i] = 3;
	}
}

int main(){
	scanf("%d %d", &N, &K);
	if(K > 3) printf("0\n");
	else{
		gen();
		int cnt = 0;
		//cout << isPrime(5) << endl;
		for(int i = 1; i <= N; i++) {
			if(arr[i] == K) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
