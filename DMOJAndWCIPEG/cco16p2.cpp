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

const double eps = 1e-6;
const int MAXN = 4000;

int n, w[MAXN], ans;
ii pts[MAXN];
vector<pair<double, int>> sweep, compressed;

int main(){
	scanf("%d", &n);
	fori(i, 0, n) scanf("%d%d%d", &pts[i].f,&pts[i].s, w+i);

	ans = 0;
	fori(i, 0, n){
		sweep.clear();
		compressed.clear();

		fori(j, 0, n){
			if(i == j) continue;
			double ang = atan2(pts[j].s - pts[i].s, pts[j].f - pts[i].f);
			sweep.pb({ang, w[j]});
			sweep.pb({ang + 2 * M_PI, w[j]});
		}
		sort(sweep.begin(), sweep.end());
	
		fori(j, 0, sweep.size()){
			int val = sweep[j].s;
			while(j+1 < (int) sweep.size() && fabs(sweep[j].f - sweep[j + 1].f) <= eps) val += sweep[++j].s;
			compressed.pb({sweep[j].f, val});
		}	
		//sort(compressed.begin(), compressed.end());

		int cans = max(0, w[i]);
		for(int a = 0, b = 0; compressed[a].f < M_PI; a++){
			while(compressed[b].f - compressed[a].f <= M_PI) cans += compressed[b++].s;
			ans = max(ans, cans);
			cans -= compressed[a].s; 
		}
	}

	printf("%d\n", ans);
	
	return 0;
}

