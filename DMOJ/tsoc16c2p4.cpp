#include <bits/stdc++.h>
using namespace std;

int N, M, p[110];
bool prime[10010], memo[10010][110];

void gen(){
    memset(prime, false, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= 10000; i++){
        if(prime[i]){
            for(int j = i*i; j <= 10000; j+= i){
                prime[j] = false;
            }
        }
    }
}

int main(){
    gen();
    scanf("%d%d", &N, &M);
    int tot = 0;
    bool valid = true;
    for(int i =0;i < M; i++){
        scanf("%d", p+i);
        tot += p[i]<<1;
        valid &= prime[p[i]];
    }
    memset(memo[0], true, sizeof(memo[0]));
    if(valid) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (i + p[j] <= N) memo[i+j][j] = true;
            }
        }
    }else{
        printf("not primetime");
    }

    return 0;
}
