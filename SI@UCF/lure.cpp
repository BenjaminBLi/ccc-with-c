#include "bits/stdc++.h"
#define vi vector<int>
#define YES 2
#define NO 0
#define MAYBE 1
#define ii pair<int, int>
using namespace std;

int N, memo[100010][3];
vi adj[100010], tree[100010];
bool chain = false, visited[100010], leaf[100010];

void setRoot() {
    queue<ii> q;
    q.push(ii(1, 1));
    visited[1] = true;
    int prev = -1, maxD = 0;
    while (q.size()) {
        int u = q.front().first, d = q.front().second;
        maxD = max(maxD, d);
        q.pop();
        if(prev != -1) tree[prev].push_back(u);
        prev = u;
        bool flag = false;
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(ii(v, d+1));
                flag = true;
                visited[v] = true;
            }
        }
        leaf[u] = !flag;
    }
    chain = maxD == N;
}

int solve(int u, int state){
    if(leaf[u] && state != YES) return 0;
    else if(leaf[u] && state == YES) return 1;
    if(memo[u][state] != -1) return memo[u][state];
    int ans = 0;
    int sum;
    if(state == NO){
        sum = 0;
        for(int v : tree[u]){
            sum += solve(v, YES);
        }
        ans = sum;
    }else if (state == YES){
        sum = 1;
        for(int v : tree[u]){
            sum += solve(v, MAYBE);
        }
        ans = sum;
    }else{
        int n = solve(u, 0);
        int y = solve(u, 2);
        //printf("u: %d\nNO: %d\nYES: %d\n", u, n, y);
        ans = min(n, y);
        //printf("%d\n", ans);
    }
    return memo[u][state] = ans;
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    setRoot();
    if(!chain) {
        memset(memo, -1, sizeof(memo));
        printf("%d\n", solve(1, 1));
    }else{
        //cout << "YES" << endl;
        printf("%d\n", N/3 + (N%3 ? 1 : 0));
    }
    //cout << memo[1][1] << endl;
    //for(int i = 1; i<= N; i++)printf("%d, ", memo[i][0]); cout << endl;
    //for(int i = 1; i<= N; i++)printf("%d, ", memo[i][1]); cout << endl;
    //for(int i = 1; i<= N; i++)printf("%d, ", memo[i][2]);


    return 0;
}