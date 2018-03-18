#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <cstring>
#include <sstream>
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

const int MAXN = 10010;
int n;
vi a[3];

int main(){
    scanf("%d", &n);
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);
        a[x%3].pb(x);
    }

    if((a[2].size() && a[1].size() && !a[0].size()) || (n == 1 && a[0].size()) || a[0].size() > a[1].size() + a[2].size() + 1){
        printf("impossible\n");
        return 0;
    }

    if(a[0].size() > a[1].size() + a[2].size()) printf("%d ", a[0].back()), a[0].pop_back();
    while(a[1].size()){
        printf("%d ", a[1].back());
        a[1].pop_back();
        if(a[1].size() <= a[0].size()) {
            printf("%d ", a[0].back()), a[0].pop_back();
        }
    }

    while(a[2].size()){
        printf("%d ", a[2].back());
        a[2].pop_back();
        if(a[0].size()) printf("%d ", a[0].back()), a[0].pop_back();
    }

    if(a[0].size()) cout << a[0].back() << endl;

    return 0;
}
