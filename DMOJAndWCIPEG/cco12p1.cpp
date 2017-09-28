#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;

int w, v, d, val[11], target;
bool vis[7][5000001];


int main() {
    scanf("%d %d", &w, &d);
    queue<ii> q;
    for (int i = 0; i < d; i++) {
        scanf("%d", val + i);
        q.push(ii(val[i], 0));
        vis[0][val[i]] = true;
    }

    while (q.size()) {
        int c = q.front().f, cd = q.front().s;
        q.pop();
        if (cd == w) continue;
        for (int i = 0; i < d; i++) {
            if (val[i] + c <= 5000000 && !vis[cd + 1][val[i] + c]) {
                q.push(ii(val[i] + c, cd + 1));
                vis[cd + 1][val[i] + c] = true;
            }
            if (val[i] * c <= 5000000 && !vis[cd + 1][val[i] * c]) {
                q.push(ii(val[i] * c, cd + 1));
                vis[cd + 1][val[i] * c] = true;
            }
        }
    }

    scanf("%d", &v);
    for (; v--;) {
        scanf("%d", &target);
        printf("%c\n", vis[w][target] ? 'Y' : 'N');
    }

    return 0;
}
