#include "bits/stdc++.h"
using namespace std;

int n;
bitset<30> rw, ld, rd;
bool found = false;
string ret = "";

void solve(int c, string str) {

    if (c == n) {
        ret = min(ret, str);
        return;
    }
    for (int r = 0; r < n; r++) {
        if (!rw[r] && !ld[r - c + n - 1] && !rd[r + c]) {
            rw[r] = ld[r - c + n - 1] = rd[r + c] = true;
            string tmp = str;
            tmp += r;
            if(tmp < ret) solve(c + 1, tmp);
            rw[r] = ld[r - c + n - 1] = rd[r + c] = false;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        ret += n;
    }
    solve(0, "");
    for(int i = 0; i < n; i++) {
        printf("%d ", ret[i]+1);
    } printf("\n");
    return 0;
}
