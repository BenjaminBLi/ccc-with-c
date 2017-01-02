#include <bits/stdc++.h>
using namespace std;

int N, g[10000][3][3];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
char t;
bool done(int id){
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
        if(g[id][i][j]) return false;
    return true;
}

int solve(int step){
    if(done(step)) return -1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int temp = 0;
            for(int d = 0; d < 4; d++){
                int r = i+dx[d], c = j+dy[d];
                if(r >= 0 && r < 3
                   && c >= 0 && c < 3
                   && g[step][r][c]) temp++;
            }
            g[step+1][i][j] = temp%2;
        }
    }
    return 1 + solve(step+1);
}


int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    memset(g, 0, sizeof(g));
    for(int i = 0; i < N; i++){
        for(int a = 0; a < 3; a++) for(int b = 0; b < 3; b++){
            scanf(" %c", &t);
            g[0][a][b] = t == '1' ? 1 : 0;
        }
        cout << solve(0) << endl;
    }
    return 0;
}
