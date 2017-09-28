#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, M, J, memo[100010];
ii mud[100010];

int main() {
    scanf("%d %d %d", &n, &M, &J);
    fori(i, 1, M + 1) {
        scanf("%d %d", &mud[i].f, &mud[i].s);
    }
    sort(mud, mud + M + 1);
    priority_queue<ii, vii, greater<ii>> pq;
    rfori(i, M, 0) {
        int c = mud[i].f, t = mud[i].s;
        while(pq.size() && pq.top().s > c + J) pq.pop();
        memo[i] = c + J > n ? t : 0x3f3f3f3f;
        if(pq.size()) memo[i] = min(memo[i], pq.top().f);
        memo[i] = max(memo[i], t);
        pq.push(ii(memo[i], c));
    }
    printf("%d\n", memo[0] == 0x3f3f3f3f ? -1 : memo[0]);

    return 0;
}
