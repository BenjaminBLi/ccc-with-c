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
int n, a[MAXN];

int main(){
    int cnt = 0;
    scanf("%d", &n);
    fori(i, 0, n) scanf("%d", &a[i]);
    fori(i, 0, n){
        int c = a[i];
        fori(j, i+1, n) if(a[j] > c) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

