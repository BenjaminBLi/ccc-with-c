#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
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

void adjust(int k, int v) {
    //cout << "adjusting: " << k <<  ", " << v << endl;
    for (; k < N; k += (k&(-k))) {
        //cout << k << endl;
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
        adjust(i, 2);
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
        if(c == 'D' || c == 'C') adjust(r, -1);
    }
    sort(ppl.begin(), ppl.end(), comp);

    return 0;
}
