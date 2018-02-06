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

int n;
vi curr;
vi medians;

int main(){
    scanf("%d", &n);
    for(int c = 0, x; c < n; c++){
        curr.clear();
        fori(i, 0, n){
            scanf("%d", &x);
            curr.pb(x);
        }
        sort(curr.begin(), curr.end());
        medians.pb(curr[n/2]);
    }

    sort(medians.begin(), medians.end());
    cout << medians[n/2] << endl;

    return 0;
}

