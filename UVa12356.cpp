#include <bits/stdc++.h>
using namespace std;

int S, B, ls[1000100], rs[1000100], L, R;

int main(){
    for(scanf("%d %d", &S, &B); !(S == 0 && B == 0);scanf("%d %d", &S, &B)){
        for(int i = 0; i < S+1; i++){
            ls[i] = i-1;
            rs[i] = i+1;
        }
        for(int i = 0; i < B; i++){
            scanf("%d %d", &L, &R);
            if(ls[L] < 1) printf("* ");
            else printf("%d ", ls[L]);
            if(rs[R] > S) printf("*\n");
            else printf("%d\n", rs[R]);
            ls[rs[R]] = ls[L];
            rs[ls[L]] = rs[R];
        }
        printf("-\n");
    }
    return 0;

}
