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

int n, m, ans = 0, bst = -1;

int getCurr(int in, bool flag){
    int c = in, palin = in;

    if(flag) in /= 10;

    while(c){
        palin = palin*10 + (c%10);
        c /= 10;
    }
    return palin;
}

void gen(){
    int val;
    fori(j, 0, 2){
        int i = 1;
        while((val = getCurr(i++, j&1)) < m){
            int c = min(abs(m-val), abs(n-val));
            if((n <= val && val <= m) && (c > ans || (c == ans && val > bst))){
                ans = c;
                bst = val;
            }
       
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    gen();
    cout << bst << endl;
    return 0;
}

