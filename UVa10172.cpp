#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
	int n, s, q, SET;

	scanf("%d", &SET);

	for (; SET--;) {
		stack<int> carrier;
		queue<int> platforms[100];

		cin >> n >> s >> q;

		for (int i = 0; i < n; i++) {
			int nc;
			cin >> nc;
			for (int j = 0; j < nc; j++) {
				int target;
				cin >> target;
				platforms[i].push(target - 1);
			}
		}

		int i = 0, time = 0;
		while (true) {
			while (!carrier.empty() && (carrier.top() == i || platforms[i].size() < q)) {
				if (carrier.top() != i)
					platforms[i].push(carrier.top());

				carrier.pop();
				time++;
			}

			while ((carrier.size() < s) && !platforms[i].empty()) {
				carrier.push(platforms[i].front());
				platforms[i].pop();
				time++;
			}

			bool clear = carrier.empty();
			for (int i = 0; i < n; i++) clear &= platforms[i].empty();

			if (clear) break;
			i = (i + 1) % n;
			time += 2;
		}

		printf("%d\n", time);
	}

	return 0;
}
