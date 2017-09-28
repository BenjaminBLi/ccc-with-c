#include <bits/stdc++.h>
using namespace std;
int K, N, M, Q, zombiesr[2000], zombiesc[2000], xs[4002], ys[4002];
unsigned short diff[4002][4002];
int r1, r2, c1, c2;
map<int, int> compx;
map<int, int> compy;

long long area(int Q) {
	memset(diff, 0, sizeof diff);
	compx.clear(); compy.clear();

	for (int i = 0; i < K; i++) {
		compx[max(zombiesr[i] - Q - 1, 0)] = compx[min(zombiesr[i] + Q, N)] = 0;
		compy[max(zombiesc[i] - Q - 1, 0)] = compy[min(zombiesc[i] + Q, M)] = 0;
	}
	int cntx = 1, cnty = 1;
	for (auto &key : compx) { xs[cntx - 1] = key.first; key.second = cntx++; }
	for (auto &key : compy) { ys[cnty - 1] = key.first; key.second = cnty++; }

	for (int i = 0; i < K; i++) {
		r1 = compx[max(zombiesr[i] - Q - 1, 0)];
		r2 = compx[min(zombiesr[i] + Q, N)];
		c1 = compy[max(zombiesc[i] - Q - 1, 0)];
		c2 = compy[min(zombiesc[i] + Q, M)];
		diff[r1][c1]++; diff[r1][c2]--; diff[r2][c1]--; diff[r2][c2]++;
	}

	long long ans = 0;
	for (int i = 1; i < cntx-1; i++) {
		for (int j = 1; j < cnty-1; j++) {
			diff[i][j] += diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
			if (diff[i][j])
				ans += 1LL * (xs[i] - xs[i - 1])*(ys[j] - ys[j - 1]);
		}
	}

	return ans;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &zombiesr[i], &zombiesc[i]);
	}

	scanf("%d", &Q);

	if (Q == 0)printf("%d", K);
	else printf("%lld", area(Q) - area(Q - 1));
	return 0;
}
