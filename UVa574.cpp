#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int t, n, arr[13];
vi ans;
map<vi, bool> m;
void solve(int idx, int c,vi curr ){
    if(c > t) return;
    else if(c == t){
        if(m[curr]) return;
        m[curr] = true;
        printf("%d", curr[0]);
        for(int i = 1; i < (int) curr.size(); i++) printf("+%d", curr[i]);
        printf("\n");
        return;
    }
    if(idx == n) return;
    curr.push_back(arr[idx]);
    solve(idx+1, c+arr[idx], curr); curr.pop_back();
    solve(idx+1, c, curr);
}

int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d %d", &t, &n) && !(t == 0 && n == 0)){
        m.clear(); ans.clear();
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("Sums of %d:\n", t);
        solve(0, 0, ans);
        if(m.size() == 0) printf("NONE\n");
    }
    return 0;
}
