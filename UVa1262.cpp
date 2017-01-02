#include <bits/stdc++.h>
using namespace std;

int T, K;
char g1[5][6], g2[5][6], curr[5];
map<char, bool> m;
map<string, bool> pass;
vector<vector<char>> f;
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for(;T--;){
        scanf("%d", &K);
        for(int i = 0; i < 6; i++) for(int j = 0; j < 5; j++) scanf(" %c", &g1[j][i]);
        for(int i = 0; i < 6; i++) for(int j = 0; j < 5; j++) scanf(" %c", &g2[j][i]);
        f.clear();f.assign(5, vector<char>()); pass.clear();
        for(int i = 0; i < 5; i++){
            m.clear();
            for(int j = 0; j < 6; j++){
                m[g1[i][j]] = true;
            }
            for(int j = 0; j < 6; j++){
                if(m[g2[i][j]])f[i].push_back(g2[i][j]);
            }
            sort(f[i].begin(), f[i].end());
        }
        int cnt = 0;
        for(int i = 0; i < (int)f[0].size() && cnt < K; i++)
            for(int j = 0;j < (int) f[1].size() && cnt < K; j++)
                for(int k = 0; k < (int) f[2].size() && cnt < K;k++)
                    for(int l = 0; l <  (int) f[3].size() && cnt < K;l++)
                        for(int m = 0;m < (int) f[4].size() && cnt < K;m++){
                            curr[0] = f[0][i]; curr[1] = f[1][j]; curr[2] = f[2][k]; curr[3] = f[3][l]; curr[4] = f[4][m];
                            if(pass.find((string) curr) == pass.end()){
                                pass[(string) curr] = true;
                                cnt++;
                            }
                        }




        //printf("%d %d %d %d %d\n", i, j, k, l, m);
        if(cnt < K) printf("NO\n");
        else printf("%c%c%c%c%c\n", curr[0], curr[1], curr[2], curr[3], curr[4]);
    }
    return 0;
}
