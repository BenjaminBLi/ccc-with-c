#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> ii;
int N, X, T;
ii zombie[5010];
int main(){
	scanf("%d %d %d", &N, &X, &T);
	for(int i =0; i < N; i++){
		scanf("%d %d", &zombie[i].s, &zombie[i].f);
	}
	sort(zombie, zombie+N);

	int cPos = 1, time = 0, bullets = T;
	bool ok = true;
	for(int i =0;i < N; i++){
		ii curr = zombie[i];
		int dist = abs(cPos-curr.s);

		cPos = curr.s;
		time += dist;
		if(bullets == 0){
			bullets = T;
			time++;
		}
		bullets--;
		time++;
		if(time > curr.f){
			ok = false; break;
		}
	}
	if(ok) printf("You can do it, Ace!\n");
	else printf("Never lucky, Ace.");

	return 0;
}