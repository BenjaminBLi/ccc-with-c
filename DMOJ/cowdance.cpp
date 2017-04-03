#include <bits/stdc++.h>
using namespace std;

int N, a[100000], T;


bool check(int sz){
	priority_queue<int, vector<int>, greater<int>> pq;
	int lst = 0;
	for(int i =0; i < N; i++){
		if(pq.size() == sz){
			lst = pq.top(); pq.pop();
		}
		if(lst+a[i] > T) return false;
		pq.push(lst+a[i]);
	}
	return true;
}

int main(){
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	scanf("%d %d", &N, &T);
	for(int i =0;i < N;i ++) scanf("%d", a+i);
	int hi = N, lo = 1, mid;
	while(hi != lo){
		mid = (hi+lo)/2;
		if(check(mid)) hi = mid;
		else lo = mid+1;
	}
	cout << lo << endl;
	return 0;
}