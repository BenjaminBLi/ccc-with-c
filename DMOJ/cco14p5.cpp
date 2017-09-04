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

int ft[600010];
int N, M, A, B, row[100010];
bool present[100010][6];

int rsq(int b) {
    int sum = 0;
    for (; b; b -= (b&(-b)))
        sum += ft[b];
    return sum;
}
int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
}

void upd(int k, int v) {
    for (; k < N; k += (k&(-k))) {
        ft[k] += v;
    }
}

bool comp(ii a, ii b){
    return abs(a.f - a.s) > abs(b.f - b.s);
}

int main(){
    scanf("%d %d %d %d", &N, &M, &A, &B);
    vii ppl;
    for(int i = 1; i <= N; i++) {
        upd(i, 2);
    }
    for(int i = 0; i < M; i++){
        int r; char c;
        scanf(" %d %c", &r, &c);
        int curr = 0;
        if(c == 'A') curr += present[r][1] + present[r][2];
        if(c == 'B') curr += present[r][2];
        int frst = rsq(r-1)+curr;
        int b = rsq(r+1, N)+curr;
        printf("%d %d\n", frst, b);
        ppl.pb(ii(frst, b));
        if(c == 'D' || c == 'C') upd(r, -1);
    }
    sort(ppl.begin(), ppl.end(), comp);

    return 0;
}
