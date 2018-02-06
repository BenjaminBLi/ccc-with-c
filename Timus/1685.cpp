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

int cnt = 0;
string str;
char ans[20010];

void dfs(int l, int r){
    if(l > r) return;
    int c = mid(l, r);
    ans[c] = str[cnt++];
    dfs(l, c-1);
    dfs(c+1, r);
}

int main(){
    getline(cin, str);
    int n = str.size();
    dfs(0, n-1);
    fori(i, 0, n) putchar(ans[i]);
    cout<<endl;
    return 0;
}

