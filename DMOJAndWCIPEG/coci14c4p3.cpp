#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;

int main(){
	scanf("%d", &N);
	long long total = 0, largest = 0, c;
	for(int i = 0; i < N; i++) {
		scanf("%lld", &c);
		total += c;
		largest = max(largest, c);
	}
	printf("%lld\n", max(2*largest, total));


	return 0;
}