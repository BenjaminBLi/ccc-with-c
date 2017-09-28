#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

stack<ii> stk;
int N;
ll tot = 0, tmp;

int main(){
    scanf("%d", &N);
    fori(i, 0, N){
        scanf("%lld", &tmp);
        int val = 1;
        while(stk.size() && stk.top().f <= tmp){
            tot += stk.top().s;
            if(stk.top().f == tmp){
                val += stk.top().s;
            }
            stk.pop();
        }
        if(stk.size()) tot++;
        stk.push(ii(tmp, val));
    }
    printf("%lld\n", tot);

    return 0;
}
