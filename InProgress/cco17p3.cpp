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

const int maxn = 200010;
int n, q;

struct event{
    int x, yl, yh;
    event(){x = yl = yh = 0;}
    event(int a, int b, int c){x = a, yl = b, yh = c;}
}events[maxn*2];

bool ecmp(event a, event b){
    if(a.x != b.x) return a.x < b.x;
    if(a.yl != b.yl) return a.yl < b.yl;
    return a.yh < b.yh;
}

inline ll flip(ll val){
    ll ret = 0;
    fori(i, 0, 64){
        ret <<= 1;
        ret |= val&1;
        val >>= 1;
    }
    return ret - (ret & -ret);
}

int main(){
    //
    return 0;
}
