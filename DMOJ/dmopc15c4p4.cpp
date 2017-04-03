#include <bits/stdc++.h>
using namespace std;
int N, a, b, x, y, Q, K;
long long arr[(int)1e5+10];
vector<int> occur[2010];
int main(){
	scanf("%d %d %d", &N, &K, &Q);
	for(int i = 1; i <= N; i++){
		scanf("%lld", arr+i);
		occur[arr[i]+1000].push_back(i);
		arr[i] += arr[i-1];
	}
	for(int q = 1; q <= Q; q++){
		scanf("%d %d %d %d", &a, &b, &x, &y);
		long long sum = arr[y]-arr[x-1];
		bool valid = sum >= K;
		auto iter = upper_bound(occur[a+1000].begin(), occur[a+1000].end(), x)-1;
		printf("%d\n", iter-occur[a+1000].begin());
		valid = (iter-occur[a+1000].begin()) >= x && iter-occur[a+1000].begin() <= y;
		iter = upper_bound(occur[b+1000].begin(), occur[b+1000].end(), y);
		valid &= (iter-occur[b+1000].begin()) >= x && iter-occur[b+1000].begin() <= y;
		if(valid) printf("Yes\n");
		else printf("No\n");
	}
}