
#include <bits/stdc++.h>

using namespace std;

struct Window {
	long long x1, y1, x2, y2;
	int t;
};

int N, T;
map<long long, int> compx;
map<long long, int> compy;
vector<long long> xs;
vector<long long> ys;
Window windows[2000];
long long diff[2002][2002], ans;

int main() {
	scanf("%d\n%d", &N, &T);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld %lld %lld %d", &windows[i].x1, &windows[i].y1, &windows[i].x2, &windows[i].y2, &windows[i].t);
		compx[windows[i].x1] = compx[windows[i].x2] = 0;
		compy[windows[i].y2] = compy[windows[i].y1] = 0;
	}

	int cntx = 1, cnty = 1;

	for (auto &key : compx) { key.second = cntx++; xs.push_back(key.first); }
	for (auto &key : compy) { key.second = cnty++; ys.push_back(key.first); }

	for (int i = 0; i < N; i++) {
		long long r1 = compx[windows[i].x1], r2 = compx[windows[i].x2], c1 = compy[windows[i].y1], c2 = compy[windows[i].y2];
		int t = windows[i].t;
		diff[r1][c1] += t; diff[r1][c2] -= t; diff[r2][c1] -= t; diff[r2][c2] += t;
	}

	for (int i = 1; i < cntx - 1; i++) {
		for (int j = 1; j < cnty; j++) {
			diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
			if (diff[i][j] >= T) ans += 1LL * (xs[i] - xs[i - 1])*(ys[j] - ys[j - 1]);
		}
	}

	printf("%lld", ans);

	return 0;
}