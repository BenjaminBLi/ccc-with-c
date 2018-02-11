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

int n, a[110][110];

inline bool check(){
    fori(x, 1, n+1) fori(y, 1, n+1) fori(z, 1, n+1)
        if(a[x][a[y][z]] != a[a[x][y]][z]) return false;

    bool found = false;
    fori(i, 1, n+1){
        bool ok = true;
        fori(x, 1, n+1){ 
            if(a[i][x] != x || a[x][i] != x) ok = false;
        }
        if(ok) {
            bool c = true;
            fori(x, 1, n+1){
                bool valid = false;
                fori(x1, 1, n+1)
                    if(a[x][x1] == i && a[x1][x] == i) {
                        valid = true;
                        break;
                    }
                c &= valid;
            }
            if(c) found = true;
        }
    }

    return found;
}

int main(){
    scanf("%d", &n);
    for(;n; scanf("%d", &n)){
        fori(i, 1, n+1) fori(j, 1, n+1) scanf("%d", &a[i][j]);
        bool ok = check();
        if(ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

