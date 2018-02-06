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

struct student{
    int t1, t2, en;
    student(){t1 = en = 0;}
    student(int a, int b, int c){t1 = a, t2 = b, en = c;}
    bool operator < (student &o) {
        if(t1 != o.t1) return t1 < o.t1;
        if(t2 != o.t2) return t2 < o.t2;
        return en < o.en;
    }
}s[50];

int n;

int main(){
    int a, b, c;
    scanf("%d", &n);
    fori(i, 0, n){
        scanf("%d%d%d", &s[i].t1, &s[i].t2, &s[i].en);
    }
    sort(s, s+n);

    int t = 0, ans = 0;
    fori(i, 0, n){
        if(t < s[i].t1) t = s[i].t1;
        t += s[i].t2;
        int dt = max(0, t - s[i].en);
        if(dt > ans) ans = dt;
    }

    cout << ans << endl;

    return 0;
}

