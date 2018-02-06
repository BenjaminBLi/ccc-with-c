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

const int MAXN = 1000010;
int n, a, b, carry = 0;
ii c[MAXN];
stack<int> stk;

int main(){
    scanf("%d", &n);

    fori(i, 0, n)
        scanf("%d%d", &c[i].f, &c[i].s);

    rfori(i, n-1, 0){
        a = c[i].f, b = c[i].s;
        stk.push((a+b+carry)%10);
        carry = (a+b+carry)/10;
    }

    if(carry) cout << carry;
    while(stk.size()){
        cout << stk.top();
        stk.pop();
    }
    return 0;
}

