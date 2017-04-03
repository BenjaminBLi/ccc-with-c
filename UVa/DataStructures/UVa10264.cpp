#include <bits/stdc++.h>
using namespace std;

int numE, edges[20000], sum[20000], maxS, N;

int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &N) == 1){
        numE = 1 << N;
        maxS = 0;
        memset(edges, 0, sizeof(edges)); memset(sum, 0, sizeof(edges));
        for(int i = 0; i < numE; i++) scanf("%d", &edges[i]);
        for(int c = 0; c < numE; c++){
            for(int b = 0; b < N; b++){
                sum[c] += edges[c^(1<<b)];
            }
        }

        for(int c1 = 0; c1 < numE; c1++){
            for(int i = 0; i < N; i++){
                maxS = max(maxS, sum[c1] + sum[c1^(1<<i)]);
            }
        }
        printf("%d\n", maxS);
    }
    return 0;
}
