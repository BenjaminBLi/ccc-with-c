#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<long long, long long> ii;
typedef long long ll;
int N;
struct vec{
	ll x, y;
	vec(ll a, ll b){
		x = a, y = b;
	}
};

vec toVec(ii a, ii b){
	return vec(b.f-a.f, b.s-a.s);
}

ll cross(vec a, vec b){
	return a.x*b.y - a.y*b.x;
}
ll ccw(ii p, ii q, ii r){
	return cross(toVec(p, q), toVec(p, r));
}
vector<ii> xs;
int main(){
	scanf("%d", &N);
	ii p;
	scanf("%d %d", &p.f, &p.s);
	ii tmp;
	for(int i = 0;i < N-1; i++){
		scanf("%lld %lld", &tmp.f, &tmp.s);
		xs.push_back(tmp);
	}
	sort(xs.begin(), xs.end());

	int cnt = 0;
	bool valid;
	do{
		valid = true;
		for(int i =0; i < (int)xs.size() && valid; i++){
			ii p1 = i == 0 ? p : xs[i-1];
			ii q1 = xs[i];
			for(int j = i; j < (int)xs.size() && valid; j++){
				ii p2 = xs[j];
				ii q2 = (j == (int)xs.size()-1) ? p : xs[j+1];
				if(p1 == q2 || q1 == p2) continue;
				ll ccw1 = ccw(p2, q2, p1)*ccw(p2, q2, q1);
				ll ccw2 = ccw(p1, q1, p2)*ccw(p1, q1, q2);
				if(ccw1 <= 0 && ccw2 <= 0){
					//cout << "YES" << endl;
					valid = false;
				}
			}
		}
		if(valid){
			cnt++;
		}
		//cout << "YES" << endl;
	}while(next_permutation(xs.begin(), xs.end()));
	//cout << vals.size() << endl;
	//cout << i << endl;
	//cout << cnt << endl;
	cout << cnt/2 << endl;

	return 0;
}