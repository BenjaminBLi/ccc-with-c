#include <bits/stdc++.h>
using namespace std;

int C, N food[1010];
bool reach[10000010]

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
int lcm(int a, int b){
	int tmp = gcd(a, b);
	return a/tmp*b;
}
int maxInvalid(int a, int b){
	return lcm(a, b)-a-b;
}

int main(){
	scanf("%d %d", &C, &N);
	for(int i =0; i < N; i++) scanf("%d", food+i);
	for(int i =0; i < N; i++){
		for(int j = i+1; j < N; j++){
			//find largest number, memset everything beyond that, 
		}
	}
	cout << memo[C];
	return 0;
}