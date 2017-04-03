#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int N, S;

set<ii> apples[101];
int stalls[100010];

int main(){
	scanf("%d %d", &N, &S);

	for(int i = 1; i <= N; i++){
		int a;
		scanf("%d", stalls+i);
		//stalls[i] = ii(a, 0);
	}
	for(int i =0; i < S; i++){
		int a, b;	
		scanf("%d %d", &a, &b);
		apples[b].insert(ii(stalls[a], a));
	}
	int Q;
	scanf("%d", &Q);
	char ch;
	for(int q =0; q < Q; q++){
		getchar(); ch = getchar();
		//printf("%d:\n", q);
		if(ch == 'Q'){
			int a;
			scanf("%d", &a);
			if(apples[a].size() == 0) printf("-1\n");
			else printf("%d\n", apples[a].begin()->second);
		}else if(ch == 'A'){
			int a, b;
			scanf("%d %d", &a, &b);
			//stalls[a] = ii(stalls[a].first, b);
			apples[b].insert(ii(stalls[a], a));
		}else if (ch == 'S'){
			int a, b;
			scanf("%d %d", &a, &b);
			apples[b].erase(ii(stalls[a], a));
		}else{
			int a, b;
			scanf("%d %d", &a, &b);
			//stalls[a] = b;
			for(int i = 0; i <= 100; i++) apples[i].erase(ii(stalls[a], a));
			stalls[a] = b;
		}
	}
	return 0;
}