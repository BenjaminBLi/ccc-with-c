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

bool pop(vi &v){
    if(v.size() == 0) return false;
    printf("%d ", v.back());
    v.pop_back();
    return true;
}

bool check(int sz){
    if(sz < 0) return false;
    if(sz == 0) return a[1].size()+a[2].size() == 0;
    if(sz == 1) return a[1].size() == 0 || a[2].size() == 0;
    return sz <= a[1].size() + a[2].size();
}

void printRem(int cnt){
    rfori(i, cnt, 0){
        if(i == 1) while(pop(a[1]) || pop(a[2]));
        if(i == 2){
            if(a[1].size() == 0) pop(a[2]);
            else if(a[2].size() == 0) pop(a[1]);
            else while(pop(a[1]));
        }if(i > 2){
            if(a[1].size()) pop(a[1]);
            else pop(a[2]);
        }
        pop(a[0]);
    }
    cout<<endl;
}

int main(){
    scanf("%d", &n);
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);
        a[x%3].pb(x);
    }

    if(!check(a[0].size()-1) && !check(a[0].size()) && !check(a[0].size()+1)){
        printf("impossible\n");
        return 0;
    }

    fori(i, -1, 2){
        if(check(a[0].size()+i)){
            if(i == -1) pop(a[0]);
            if(i != 1) printRem(a[0].size());
            else printRem(a[0].size() + 1);
            return 0;
        }
    }

    return 0;
}
