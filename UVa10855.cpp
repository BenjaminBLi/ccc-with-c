#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, n, cnt[4];
char arr1[1000][1000], arr2[1000][1000], cpy[1000][1000];

void rotate(){
    for(int col = n-1; col >= 0; col--){
        for(int row = 0; row < n; row++){
            cpy[row][col] = arr2[n-col-1][row];
        }
    }
    for(int r = 0; r < n; r++)for(int c = 0; c < n; c++) arr2[r][c] = cpy[r][c];
}

int main(){
    for(scanf("%d %d", &N, &n); !(N == 0 && n == 0); scanf("%d %d", &N, &n)){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                scanf(" %c", &arr1[i][j]);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf(" %c", &arr2[i][j]);
            }
        }

        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < 4; i++){
            for(int sr = 0; sr <= N-n; sr++) for(int sc = 0; sc <= N-n; sc++){
                bool valid = true;
                for(int r = 0; r < n; r++)
                    for (int c = 0; c < n; c++)
                        valid &= arr1[sr+r][sc+c] == arr2[r][c];
                if(valid) cnt[i]++;
            }
            rotate();
        }
        printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
    }
    return 0;
}
