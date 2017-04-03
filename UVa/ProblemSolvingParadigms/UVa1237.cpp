#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int P, D, Q, L[10000], H[10000], T;
char id[10000][25];
int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for(;T--;){
        scanf("%d", &D);
        for(int i = 0; i < D; i++){
            scanf(" %s %d %d", id[i], &L[i], &H[i]);
            //printf("%s\n", id[i]);
        }
        scanf("%d", &Q);
        for(int i = 0; i < Q; i++){
            scanf("%d", &P);
            int idx;
            int cnt = 0;
            for(int i = 0; i < D; i++){
                if(L[i] <= P && H[i] >= P){
                    //printf("%s contains %d\n", id[i], P);
                    cnt++; idx = i;
                }
            }
            if(cnt == 1) printf("%s\n", id[idx]);
            else printf("UNDETERMINED\n");
        }
        if(T) printf("\n");
    }
    return 0;
}
