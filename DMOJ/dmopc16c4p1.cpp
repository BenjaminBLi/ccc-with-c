#include <bits/stdc++.h>
#define fori(i, N) for(int i =0; i < N; i++)
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

int N;
unsigned long long n;

int main(){
	scanf("%d", &N);
	//cout << N << endl;
	fori(i, N){
		scanf("%llu", &n);
		//cout << n<< endl;
		//cout << __builtin_popcount(n) << endl;
		if(__builtin_popcount(n) == 1) printf("T\n");
		else printf("F\n");
	}
	return 0;
}