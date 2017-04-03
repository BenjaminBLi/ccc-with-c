#include <bits/stdc++.h>
using namespace std;

#define fori(i,n) for (int i=0,_n=n; i<_n; i++)

#define MAXN 20000
int D[MAXN], K[MAXN], nk, nd;
int main(){
    for(;scanf("%d %d", &nd, &nk) && nd|nk;){
        fori(i, nd)scanf("%d", &D[i]);
        fori(i, nk) scanf("%d", &K[i]);
        if(nd <= nk){
            sort(D, D+nd); sort(K, K+nk);
            int g = 0, d = 0, kn = -1;
            for(;d<nd;d++){
                kn++;
                while(kn < nk && K[kn] < D[d])
                    kn++;
                if(kn == nk) break;
                g += K[kn];
            }
            if(d != nd) printf("Loowater is doomed!\n");
            else printf("%d\n", g);
        }else{
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}
