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

int n, a, b, c, arr[1000010];
int memo[1000010];

inline int val(int x){
    return x*x*a + x*b + c;
}

int main(){
    scanf("%d %d %d %d", &n, &a, &b, &c);
    fori(i, 1, n+1) {
        scanf("%d", arr+i);
        arr[i] += arr[i-1];
    }
    rfori(i, n, 0) rfori(j, i-1, 0) memo[i] = max(memo[i], memo[j] + val(arr[i]-arr[j]));
    fori(i, 0, n+1) cout << memo[i] << ", "; cout << endl;
    cout << memo[1] << endl;

    return 0;
}
