#include <bits/stdc++.h>
using namespace std;

int T, cnt, minN, v[4];
bool seen[20][20][20][20];

void solve(int p, int g, int r, int o){
	if(seen[p][g][r][o]) return;
	seen[p][g][r][o] = true;
	if(p*v[0] + g*v[1] + r*v[2] + o*v[3] > T) return;
	if(p*v[0] + g*v[1] + r*v[2] + o*v[3] == T){
		printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", p, g, r, o);
		cnt++;
		minN = min(minN, p+g+r+o);
		return;
	}
	solve(p, g, r, o+1);
	solve(p, g, r+1, o);
	solve(p, g+1, r, o);
	solve(p+1, g, r, o);
}

int main(){
	for(int i =0; i < 4; i++) scanf("%d", v+i);
	scanf("%d", &T);
	minN = 1<<30;
	cnt = 0;
	solve(0, 0, 0, 0);
	printf("Total combinations is %d.\n", cnt);
	printf("Minimum number of tickets to print is %d.", minN);
	return 0;
}