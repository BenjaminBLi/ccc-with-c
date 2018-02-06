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
int n, m, c[MAXN], flag[MAXN];

int main(){
    scanf("%d%d", &n, &m);

    fori(i, 0, m){
        scanf("%d", c+i);
        flag[c[i]]++;
    }


    int cnt = 0;
    fori(i, 0, n+1){
        fori(j, 0, flag[i]){
            c[cnt++] = i;
        }
        flag[i] = false;
    }

    fori(i, 0, m){
        if(!flag[c[i]] && c[i] <= n && c[i])
            flag[c[i]] = true;
        else if(!flag[c[i] + 1] && c[i] + 1 <= n)
            flag[c[i] + 1] = true;
        else{
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}

