#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, -1, 1};
char grid[60][60];
bool visited[60][60];

/*
5 6
waaaww
wawawc
bbbbwc
wwwwww
dddddd
 */

void search(int r, int c){
    visited[r][c] = true;
    for(int i = 0; i < 4; i++){
        int dx = r+dr[i], dy = c+dc[i];
        if(!visited[dx][dy] && dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == 'w'){
            search(dx, dy);
        }
    }
}

int main(){
    cnt = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf(" %c", &grid[i][j]);

    for(int r = 0; r < n; r++) for(int c = 0; c < m; c++){
        if(!visited[r][c] && grid[r][c] == 'w'){
                cnt++;
                search(r, c);
            }
        }

    printf("%d\n", cnt);

    return 0;
}
