#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;

int N, T;
ii events[100010], stations[100010];
long long dx, dy;

int main(){
	scanf("%d %d", &N, &T);
	for(int i = 1; i <= N; i++) scanf("%d %d", &stations[i].f, &stations[i].s);
	int cx = 0, cy = 0;
	for(int i =0;i < N; i++){
		scanf("%d %d", &events[i].s, &events[i].f);
	}


	return 0;
}