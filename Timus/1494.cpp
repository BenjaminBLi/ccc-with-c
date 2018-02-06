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

const int MAXN = 100010;
int n, a[MAXN], st[MAXN];
stack<int> stk;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    int pos = 0, pos2 = 0, sz = 0;
    bool ok = true;

    while(ok && pos < n){
        if(sz && st[sz-1] == a[pos]){
            sz--;
            pos++;
        }else if(pos2 < n){
            st[sz++] = ++pos2;
        }else ok = false;
    }

    if(ok) puts("Not a proof");
    else puts("Cheater");
    return 0;
}

