#include <bits/stdc++.h>
#define f first
#define s second
#define x first
#define y second
using namespace std;
typedef pair<int, int> ii;
int t, n, b[1000010];
ii init[1000010], end[500010], ip[1000010], ep[500010];

void kmpPreProcess(){
	int i = 0, j = -1; b[0] = -1;
	while(i < n){
		while(j >= 0 && end[i] != end[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}
int kmpSearch(){
	int i = 0, j = 0;
	bool found = false;
	while(i < n && !found){
		while(j >= 0 && init[i] != end[j]) j = b[j];
		i++; j++;
		if(j == n){
			found = true;
			j = b[j];
		}
	}
	if(!found) return -1;
	return i-j;
}

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b, a%b);
}
int cross(ii a, ii b){
	return a.x*b.y - a.y*b.x;
}
int dot(ii a, ii b){
	return a.x*b.x + a.y*b.y;
}

int main(){
	scanf("%d", &t);
	for(;t--;){
		scanf("%d", &n);
		for(int i =0;i < n; i++){
			scanf("%d %d", &init[i].x, &init[i].y);
			init[i] = init[n+i-1];
		}
		for(int i =0;i < n; i++) scanf("%d %d", &end[i].x, &end[i].y);

		//
	}

	return 0;
}