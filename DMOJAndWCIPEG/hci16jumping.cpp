#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int n, c, memo[2010][2010];
bool ok[2010][2010];

int main(){
	scanf("%d%d", &c, &n);
	char ch;
	fori(i, 0, n){
		fori(j, 0, c){
			scanf(" %c", &ch);
			if(ch == '1') ok[i][j] = true;
		}
	}

	//do dp lol
	int ans = 0x3f3f3f3f;
	memset(memo, 0x3f, sizeof(memo));
	fori(i, 0, n) if(ok[i][0]) memo[i][0] = 0;
	fori(col, 1, c){
		fori(row, 0, n){
			///???HM?!?!?!?!?!?!????
			if(!ok[row][col]) continue;
			fori(i, 0, n){
				if(!ok[i][col-1]) continue;
				memo[row][col] = min(memo[row][col], memo[i][col-1] + (row - i) * (row - i));
			}
		}
	}
	fori(i, 0, n) ans = min(ans, memo[i][c-1]);
	printf("%d\n", ans);
	return 0;
}

