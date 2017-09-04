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

int n, k, arr[10010], seats[10010][4];

bool solve(int r, int c){
    bool flag = false;
    int nc = (nc+1)%4, nr;
    if(nc < c) nr++;
    fori(i, 0, k){

    }
}

int main(){
    scanf("%d %d", &n, &k);
    fori(i, 0, k) scanf("%d", arr+i);
    int cr = 0, cc = 0;

    return 0;
}
