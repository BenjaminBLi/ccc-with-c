#include <bits/stdc++.h>
using namespace std;

int q[8], best, curr[8];

bool val(int r, int c){
    for(int p = 0; p < c; p++){
        if(curr[p] == r || abs(curr[p]-r) == abs(p-c)) return false;
    }
    return true;
}

void solve(int c){
    if(c == 8){
        int t = 0;
        for(int i = 0; i < 8; i++) if(curr[i] != q[i]) t++;
        //for(int i = 0; i < 8; i++) cout << curr[i] << " ";
        //cout << endl;
        best = min(best, t);
    }else{
        for(int i = 0; i < 8; i++){
            if(val(i, c)){
                curr[c] = i;
                solve(c+1);
            }
        }
    }
}

int main(){
    int cnt = 1;
    //freopen("in.txt", "r", stdin);
    while(scanf("%d %d %d %d %d %d %d %d", &q[0], &q[1], &q[2], &q[3], &q[4], &q[5], &q[6], &q[7]) != EOF){
        memset(curr, 0, sizeof(curr));
        for(int i = 0; i < 8; i++) q[i]--;
        //cout << "ORIG: ";
        //for(int i = 0; i < 8; i++) cout << q[i] << " ";
        //cout << endl;
        best = 8;
        solve(0);
        printf("Case %d: %d\n", cnt++, best);
    }
    return 0;
}
