#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int K;
vi pts;

void printPart(int sz, int st){
    if(sz == 1){
        printf("%d %d\n", st+1, st+2);
        printf("%d %d\n", st+2, st+1);
        return;
    }
    fori(i, 1, sz){
        printf("%d %d\n", i+st, i+st+1);
    }
    printf("%d %d\n", st+sz, st+1);
}

int main() {
    scanf("%d", &K);
    if (K == 0) {
        printf("%d %d\n", 1, 0);
        return 0;
    }
    int c = 1;
    bool val = false;
    fori(i, 1, K) {
        if (i * (i - 1) / 2 <= K) {
            c = i;
            if (i * (i - 1) / 2 == K) {
                val = true;
                break;
            }
        } else break;
    }
    pts.pb(c);
    if (val) {
        printf("%d %d\n", c, c);
        printPart(c, 0);
    } else {
        int tmp = K - (c == 1 ? 1 : c * (c - 1) / 2);
        int e, v;
        v = e = c == 1 ? 2 : c;
        while (tmp > 0) {
            c = 1;
            fori(i, 1, tmp) {
                if (i * (i - 1) / 2 <= tmp) {
                    c = i;
                } else break;
            }
            if (c > 1) tmp -= c * (c - 1) / 2, v += c, e += c;
            else tmp--, v += 2, e += 2;
            pts.pb(c);
            e++;
        }
        printf("%d %d\n", v, e);
        int st = 0;
        for (int pt : pts) {
            if (st) printf("%d %d\n", st, st + 1);
            printPart(pt, st);
            st += pt;
            if (pt == 1) st++;
        }
    }

    return 0;
}