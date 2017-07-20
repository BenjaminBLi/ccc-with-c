#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> ii;

int n, m, grid[510][510], dist[510][510], dr[] = {1, -1, 0, 0}, dc[4] = {0, 0, -1, 1};;

int main(){
    scanf("%d %d", &n, &m);
    for(int r = 0; r < n; r++) for(int c = 0; c < m; c++) {
        char ch;
        dist[r][c] = -1, scanf(" %c", &ch);
        grid[r][c] = ch-'0';
    }
    queue<ii> q;
    q.push(ii(0, 0));
    dist[0][0] = 0;
    ii u;
    while(q.size()){
        u = q.front(); q.pop();
        int r = u.first, c = u.second;
        for(int i = 0; i < 4; i++){
            int dx = grid[r][c]*dr[i], dy = grid[r][c]*dc[i];
            if(r + dx >= 0 && r + dx < n &&  c + dy < m &&  c + dy >= 0){
                if(dist[r+dx][c+dy] == -1 || dist[r+dx][c+dy] > dist[r][c]+1) {
                    q.push(ii(r+dx, c+dy));
                    dist[r + dx][c + dy] = dist[r][c] + 1;
                }
            }
        }
    }

    printf("%d\n", dist[n-1][m-1]);
    return 0;
}
