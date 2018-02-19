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

int n, a[110], mn = 1e9+1;

inline bool check(int val){
    if(val == 1) return false;
    int mod = a[0]%val;
    fori(i, 1, n) if(a[i]%val != mod) return false;
    return true;
}

void factor(int c){
    if(check(c)) printf("%d ", c);
    int i;
    for(i = 2; i*i < c; i++){
        if(c%i) continue;
        if(check(i)) printf("%d ", i);
        if(check(c/i)) printf("%d ", c/i);
    }

    if(i*i == c && check(i)) printf("%d", i);
    printf("\n");
}

int main(){
    scanf("%d", &n);
    fori(i, 0, n) scanf("%d", a+i);
    sort(a, a+n);

    fori(i, 1, n)
        mn = min(mn, a[i]-a[i-1]);

    factor(mn);
    
    return 0;
}

