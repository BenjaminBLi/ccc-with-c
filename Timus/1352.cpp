#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

int ans[42] = {0, 2, 3, 5, 7, 13, 17, 19, 31, 61, 89,107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 
               9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 
               1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583};
int t;

int main(){
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }

    return 0;
}

