#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int gCnt, T, G, a, b, sa, sb, arr[4], cnt, w[3][2] = {{3, 0}, {0, 3}, {1, 1}};
bool played[4][4], taken[6];
ii game[6]; 

void check(){
	//cout << "YES" << endl;
	int bTeam = arr[T];
	bool valid = true;
	for(int i =0; i < 4; i++){
		if(i == T) continue;
		else if (arr[i] >= bTeam) valid = false;
	}
	if(valid) cnt++;
}

void solve(int curr){
	//printf("step: %d, %d %d %d %d\n", curr, arr[0], arr[1], arr[2], arr[3]);

	int a1 = game[curr].first, b1 = game[curr].second;
	if(curr == gCnt) check();
	else{
		for(int i = 0; i < 3; i++){
		//a = game[curr].first; b = game[curr].second;
			arr[a1] += w[i][0]; arr[b1] += w[i][1];
		//if(curr == gCnt) check();
			solve(curr+1);
		//a = game[curr].first; b = game[curr].second;
			arr[a1] -= w[i][0]; arr[b1] -= w[i][1];
		}
	}
	//cout << endl;
}

int main(){
	scanf("%d %d", &T, &G);
	T--;
	cnt = 0;
	memset(arr, 0, sizeof(arr));
	for(int i =0 ; i < G; i++){
		scanf("%d %d %d %d", &a, &b, &sa, &sb);
		a--; b--;
		if(sa > sb) arr[a] += 3;
		else if(sb > sa) arr[b] += 3;
		else {arr[a]++; arr[b]++;}
		played[a][b] = true;
	}
	gCnt = 0;
	for(int i =0; i < 4; i++) for(int j = i+1; j < 4; j++){
		if(!played[i][j]) {
			game[gCnt++] = ii(i, j);
		}
	}
	//cout << gCnt << endl;
	//cout << cnt << endl;
	solve(0);
	printf("%d\n", cnt);
	return 0;
}