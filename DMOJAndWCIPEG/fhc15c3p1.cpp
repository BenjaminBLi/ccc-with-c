#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<double, double> ii;
typedef pair<double, int> di;
typedef long long ll;
typedef vector<ii> vii;

int T, n, d;

const double eps = 1e-9;
ii pts[3010], piv, init;
vector<double> sweep;
vector<di> sweep2;

int main(){
	scanf("%d", &T);
	fori(t, 0, T){
		sweep.clear();
		scanf("%lf%lf", &init.f, &init.s);
		scanf("%d%d", &d, &n);
		//sort line sweep with respect to init.
		fori(i, 0, n){
			scanf("%lf%lf", &pts[i].f, &pts[i].s);
			double ang = atan2(pts[i].s - init.s, pts[i].f - init.f);
			sweep.pb(ang);
		}

		int ans = 0;
		//i is the initial direction the boomerang goes in
		fori(i, 0, n){
			sweep2.clear();
			int a = 0;
			ii en = ii(init.f + d * cos(sweep[i]), init.s + d * sin(sweep[i]));
			//process angles from end and count points part of A
			int b = 0;
			fori(j, 0, n){
				if (fabs(sweep[i]-sweep[j]) <= eps && 
					hypot(init.f - pts[j].f, init.s - pts[j].s) <= d){
					a++;
				}
				//point is equal to end point;
				if(fabs(en.f - pts[j].f) <= eps && fabs(en.s - pts[j].s) <= eps){
					b++;
					continue;
				}
				double cang = atan2(pts[j].s - en.s, pts[j].f - en.f);
				sweep2.pb(di(cang, j));
			}
			if (a == 0) continue;
			sort(sweep2.begin(), sweep2.end());
			//pick second direction and do a radial sweep to find teh answer
			//remember to omit point j, if it exists
			int sz = (int) sweep2.size();
			for(int j = 0, k = 0; j < sz; j++){
				while(k < sz && fabs(sweep2[j].f - sweep2[k].f) <= eps){
					k++;
					b++; 
				}
				ans = max(ans, a * b);
				b--;
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}