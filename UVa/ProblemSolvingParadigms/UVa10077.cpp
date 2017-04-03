#include <bits/stdc++.h>
using namespace std;

int m, n, lm, ln, rm, rn, cm, cn;

int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d %d", &m, &n) && !(m == 1 && n == 1)){
        lm = 0; ln = 1; rm = 1; rn = 0; cm = 1; cn = 1;
        for(;!(cm == m && cn == n);){
            //printf("%d/%d\n", cm, cn);
            if(cm*n < m*cn){
                printf("R");
                lm = cm; ln = cn;
                cm += rm; cn += rn;
            }else{
                printf("L");
                rm = cm; rn = cn;
                cm += lm; cn += ln;
            }
        }
        printf("\n");
    }
    return 0;
}
