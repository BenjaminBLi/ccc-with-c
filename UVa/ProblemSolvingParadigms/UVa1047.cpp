#include <bits/stdc++.h>
using namespace std;
int n, a, arr[25], m, t, p1, p2, val;
map<int, int> comm;
void printLoc(int loc){
    for(int i = 0; i < n; i++) if(loc & (1<<i))
        printf(" %d", i+1);
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cse = 1;
    while(scanf("%d %d", &n, &a) != EOF && !(n == 0 && a == 0)){
        printf("Case Number  %d\n", cse++);
        comm.clear();
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        scanf("%d", &m);

        for(int i = 0; i < m; i++){
            scanf("%d", &t);
            int id = 0;
            //printf("T: %d", t);
            for(int i = 0; i < t; i++){
                scanf("%d", &p1);
                //printf(" %d", p1);
                p1--;
                id |= (1<<p1);
            }
            //printf("%d", id);
            //cout << endl;
            scanf("%d", &val);
            comm[id] = val;
            //cout << comm[id] << endl;
        }
        int best = -1, mask;
        for(int i = 0; i < (1<<n); i++) if(__builtin_popcount(i) == a){
            int tot = 0;
            for(int b = 0; b < n; b++) if(i&(1<<b)){
                tot += arr[b];
            }
            for(auto it : comm){
                int btz = __builtin_popcount((it.first)&i);
                if(btz >= 2)
                    tot -= (btz-1)*it.second;
            }
            if(tot > best){
                best = tot;
                mask = i;
            }
        }
        printf("Number of Customers: %d\n", best);
        printf("Locations recommended:"); printLoc(mask);
        printf("\n\n");
    }
    return 0;
}
