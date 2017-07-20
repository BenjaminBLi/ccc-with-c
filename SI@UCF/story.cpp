#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 * counting # of topological sorts in a tree

 * each node stores two things: how many topsorts it's subtree has t[i], and the # of nodes in its subtree including itself s[i]
 *  initially set to one

 *  how to do it:
 *      dfs down tree
 *      calculating s[i] is just s[] of children + 1
 *      calculating t[i] is done using maths
 *      first assume that all subtrees have one valid topsort
 *          the formula is just to calculate (s[i])!/(s[] of all children)! * t[i] of all children
 *              nCs[v1] * (n-v1)Cv2 * (n-v1-v2)Cv3...
 *
 *      choose function can just be done with pascal's triangle to do choose notation
 */

int n, e[5010], p[5010], s[5010], choose[5010][5010], inDeg[5010];
long long t[5010];
vector<int> adj[5010];
long long MOD = 1000000007;

void gen(){
    memset(choose, 1, sizeof(choose));
    for(int i = 1; i <= 5000; i++){
        for(int j = 1; i <= 5000; i++){
            choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
            choose[i][j] %= MOD;
        }
    }
}

int findKids(int u){
    //cout << u << endl;
    if(adj[u].size() == 0) return 0;
    for(int v : adj[u]) s[u] += findKids(v);
    return s[u];
}

ll solve(int u){
    if(adj[u].size() == 0)
        return t[u] = 1;

    ll ans = 1;
    int c = s[u];
    for(int v : adj[u]){
        ans *= choose[c][s[v]];
        ans %= MOD;
        c -= s[v];
    }
    return t[u] = ans;
}

int main() {
    gen();
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d", e + i);
        adj[e[i]].push_back(i);
        s[i] = 1;
    }
    s[n] = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++)
          if (!inDeg[i]) {
            q.push(i);
    }
    findKids(n);
    cout << solve(n) << endl;
    return 0;
}
