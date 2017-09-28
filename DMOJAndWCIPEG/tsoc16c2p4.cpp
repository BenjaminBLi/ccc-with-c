#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
using namespace std;

int N, M, p[210];
bool prime[10010], memo[10010];

void gen(){
    memset(prime, true, sizeof(prime));
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
    bool hasOne = false;
    for(int i =0;i < M; i++){
        scanf("%d", p+i);
        tot += p[i]<<1;
        p[M+i] = p[i];
        if(p[i] == 1) hasOne = true;
    }
    if(hasOne && tot <= N) printf("its primetime\n");
    else if (tot > N) printf("not primetime\n");
    else{
        memo[tot] = true;
        fori(i, 0, M+M){
            fori(j, tot, N+1){
                if(memo[j]) memo[j+p[i]] = true;
            }
        }
        bool ok = false;
        fori(i, tot, N+1){
            if(memo[i] && prime[i]) ok = true;
        }
        if(ok) printf("its primetime\n");
        else printf("not primetime\n");
    }

    return 0;
}
