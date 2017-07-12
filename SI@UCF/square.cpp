#include <bits/stdc++.h>
using namespace std;

int r, c, grid[110][110];

int main(){
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char ch;
            scanf(" %c", &ch);
            if(ch == 'S'){
                grid[i][j] = 8;
                if(i+1 < r) grid[i+1][j]++;
                if(j+1 < c) grid[i][j+1]++;
                if(i-1 >= 0) grid[i-1][j]++;
                if(j-1 >= 0) grid[i][j-1]++;
                if(i+1 < r && j+1 < c) grid[i+1][j+1]++;
                if(i+1 < r && j-1 >= 0) grid[i+1][j-1]++;
                if(i-1 >= 0 && j+1 < c) grid[i-1][j+1]++;
                if(i-1 >= 0 && j-1 >= 0) grid[i-1][j-1]++;
            }
        }
    }
    int cnt = 0;
    if(r > 1 && c > 1) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int max = 8;
                if ((i == 0 || i == r - 1) && (j == 0 || j == c - 1)) max = 4;
                else if (i == 0 || i == r - 1 || j == 0 || j == c - 1) max = 6;
                if (grid[i][j] < max / 2) cnt++;
            }
        }
    }else if(r == 1 && c == 1){
        cnt = grid[0][0] == 8 ? 0 : 1;
    }else if(r == 1){
        for(int i = 0; i < c; i++){
            if(grid[0][i] == 0) cnt++;
        }
    }else if(c == 1){
        for(int i = 0; i < r; i++){
            if(grid[i][0] == 0) cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}
