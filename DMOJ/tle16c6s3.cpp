#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
int N;
ii houses[2010];
bool taken[2010];

long long solve(int l, int r){
	//HOW
}

int main(){
	scanf("%d", &N);
	int x, val;
	for(int i =0;i < N; i++){
		scanf("%lld %lld", &houses[i].first, &houses[i].second);
	}
	sort(houses, houses+N);
	int start;
	for(int i =0; i < N; i++) if(houses[i].first == 0) {start = i; break;}
	
	cout << solve(0, start, 0, 0) << endl;
	return 0;
}