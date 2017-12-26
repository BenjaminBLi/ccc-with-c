#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

const int MAXN = pow(5, 9) + 10;
int n, a[9];
ull memo[MAXN][2], init[MAXN];

int main(){
	scanf("%d", &n);

	int en = 1;
	rfori(i, n-1, 0) scanf("%d", a+i), en *= a[i];
	fori(i, 0, en) scanf("%lld", &memo[i][0]), init[i] = memo[i][0];

	int d = 1, c = 1;
	for(int i = 0; i < n; c = 1 - c, i++){
		//i is current node, just check if the adj is the same to
		//leftmost is with the dim
		int dim = a[i] * d;
		fori(j, 0, en){
			memo[j][c] += memo[j][1-c];
			if(j - d >= 0 && (j-d)/dim == j/dim) memo[j][c] += memo[j-d][1-c];
			if(j + d < MAXN && (j+d)/dim == j/dim) memo[j][c] += memo[j+d][1-c]; 
		}
		if(i + 1 != n)fori(j, 0, en) memo[j][1-c] = 0;
		d *= a[i];
	}
	fori(i, 0, en){
		printf("%lld\n", memo[i][n&1] - init[i]);
	}
	return 0;
}

