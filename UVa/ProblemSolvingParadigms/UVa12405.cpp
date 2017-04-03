#include <bits/stdc++.h>
using namespace std;
int T, N = 0, cnt;
char ch[110];
int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        cnt = 0;
        scanf("%d", &N);
        scanf("%s", ch);
        for(int i = 0; i < N;){
            if(ch[i] == '#') i++;
            else{
                i += 3;
                cnt++;
            }
        }
        printf("Case %d: %d\n", t, cnt);
    }
    return 0;
}
