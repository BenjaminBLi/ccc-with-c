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

int N, M, K, pts[110];

ll memo[110][510];

inline ll choose(int n){
	return 1LL * n * (n+1) / 2;
}

inline ll getC(int m, int k){
	int ck = k+1;
	int whole =  m / ck;
	int mx = (m + ck -1) / ck;
	int pt2 = m % ck;
	int pt1 = ck - pt2;
	return 1LL * pt1 * choose(whole) + 1LL * pt2 * choose(mx);
}

int main(){
	scanf("%d%d%d", &N, &M, &K);
	fori(i, 0, N){
		int c;
		scanf("%d", &c);
		pts[c]++;
	}

	fori(m, 1, M+1){
		fori(k, 0, K+1){
			memo[m][k] = getC(pts[m], 0) + memo[m-1][k];
			fori(i, 1, k+1){
				memo[m][k] = min(memo[m][k], getC(pts[m], i) + memo[m-1][k-i]);
			}
		}
	}
	cout << memo[M][K] << endl;
	return 0;
}

