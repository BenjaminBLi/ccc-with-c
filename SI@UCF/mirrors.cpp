#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, t, b, totCnt;
bool glyph[2][100010];

bool check(){
    for (int st = 1; st <= n; st++) {
        int c = 0;
        int cnt = 0;
        int fc = 1;
        int fcnt = 0;
        for(int i = st; i <= n; i += st){
            c = 1-c;
            fc = 1-fc;
            if(glyph[c][i]) cnt++;
            if(glyph[fc][i]) fcnt++;
        }
        if(cnt == totCnt || fcnt == totCnt) {
            //cout << "JUMP SIZE: " << st << endl;
            return true;
        }
    }

    return false;
}

int main(){
    scanf("%d %d", &n, &t);
    for(int i = 0; i < t; i++){
        int tmp; scanf("%d", &tmp);
        glyph[0][tmp] = true;
    }
    scanf("%d", &b);
    for(int i = 0; i < b; i++){
        int tmp; scanf("%d", &tmp);
        glyph[1][tmp] = true;
    }
    totCnt = t+b;

    if(t == 0 && b == 0) printf("0\n");
    else if(check()) printf("1\n");
    else printf("2\n");

    return 0;
}
