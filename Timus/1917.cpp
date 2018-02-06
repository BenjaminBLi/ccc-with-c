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

const int MAXN = 1010;
int n, p, a[MAXN];

int main(){
    scanf("%d%d", &n, &p);
    fori(i, 0, n)
        scanf("%d", a+i);
    sort(a, a+n);

    int i = 0, j; 
    ll sz, a1 = 0, a2 = 0, cnt = 0;
    while(i < n){
        j = upper_bound(a+i, a+n, a[i]) - a;
        sz = (j-i);
        if((cnt + sz)*a[i] <= p) cnt += sz;
        else{
            if(!cnt || cnt * a[i-1] > p) break;
            a1 += cnt, a2++;
            cnt = sz;
        }
        i = j;
    }

    if(cnt && cnt * a[i-1] <= p) a1 += cnt, a2++;
    cout << a1 << " " << a2 << endl;

    return 0;
}

