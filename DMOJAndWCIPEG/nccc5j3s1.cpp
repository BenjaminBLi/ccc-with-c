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

const int MAXN = 110;
int n, a[MAXN], val;

int main(){
    scanf("%d%d", &n, &val);
    fori(i, 0, n) scanf("%d", a+i);
    sort(a, a+n);

    int cnt = 0;
    fori(i, 0, n){
        fori(j, i+1, n){
            if(a[j] != val) continue;
            fori(k, j+1, n){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

