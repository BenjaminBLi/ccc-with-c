#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, int> cnt;

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d %d", &N, &M) && !(N == 0 && M == 0)){
        cnt.clear();
        for(int i= 0; i < N; i++){
            int cd;
            scanf("%d", &cd);
            cnt[cd] = 1;
        }
        int both = 0;
        for(int i = 0;i < M; i++){
            int cd; scanf("%d", &cd);
            if(cnt.find(cd) != cnt.end()) both++;
        }
        cout << both << endl;
    }
    return 0;
}
