#include <bits/stdc++.h>
using namespace std;

int X, D, P, memo[100010], Q[100010], R[100010], N;
bool yes[100010];

int main(){
    scanf("%d", &X);
    //cout << "DONE" << endl;
    if(X == 1){
        scanf("%d %d %d", &D, &N, &P);
        //cout << "DONE" << endl;
        for(int i = 0; i < P; i++) scanf("%d", &Q[i]), scanf("%d", &R[Q[i]]), yes[Q[i]] = true;
        memo[D] = 1;
        for(int i = P; i > 0; i--){
            //if(R[i] != 0) cout << "YES" << endl;
            memo[i] = memo[i+1]*2-memo[i+R[i]+1];
        }
        for(int i = 0; i <= D; i++) printf("%d, ", R[i]); cout << endl;
        for(int i= 0; i <= D; i++)printf("%d, ", memo[i]); cout << endl;
        cout << memo[0] << endl;
    }else{

    }

    return 0;
}