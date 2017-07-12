#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

int n, m;
bool grid[110][110];

int main(){
    scanf("%d %d", &n, &m);
    memset(grid, false, sizeof(grid));
    int cnt = 0;
    int lr = 100, lc = 100, hr = 0, hc = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            char ch;
            scanf(" %c", &ch);
            if(ch == 'B') {
                cnt++;
                grid[r][c] = true;
                lr = min(lr, r);
                lc = min(lc, c);
                hr = max(hr, r);
                hc = max(hc, c);
            }
        }
    }
    //printf("%d %d\n", lr, lc);
    //printf("%d %d\n", hr, hc);
    int rSz = 1+hr-lr, cSz = 1+hc-lc;
    int maxSz = max(rSz, cSz);
    if(maxSz > n || maxSz > m ){
        printf("-1\n");
    }else if(cnt == 0){
        printf("1\n");
    }else{
        int tot = 0;
        lr = hr - maxSz+1;
        lc = hc - maxSz+1;
        //cout << lr << ", " << lc << endl;
        for(int r = lr; r <= hr; r++){
            for(int c = lc; c <= hc; c++){
                if(!grid[r][c]) tot++;
            }
        }
        printf("%d\n", tot);
    }

    return 0;
}
