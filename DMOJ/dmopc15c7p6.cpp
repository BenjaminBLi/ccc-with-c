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

int N, r[10010];
char str[20010];

int main(){
    scanf("%d", &N);
    for(int i = 1; i < (N<<1); i += 2){
         str[i-1] = 0;
        scanf(" %c", str+i);
    }
    str[N<<1] = 0;
    int n = N<<1;
    n++;
    int p = 0, mx = 0;
    fori(i, 0, n){
        if(mx > i) r[i] = min(r[(p<<1)-i], mx-i);
        else r[i] = 0;
        while(i>=r[i] && i+r[i] <n && str[i+r[i]] == str[i-r[i]]) r[i]++;
        if(i+r[i] > mx) p = i, mx = i+r[i];
    }

    return 0;
}
