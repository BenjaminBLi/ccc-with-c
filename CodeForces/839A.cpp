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

int n, k, arr[10010];

int main(){
    scanf("%d %d", &n, &k);
    fori(i, 0, n)
        scanf("%d", arr+i);

    int tot = 0, day = -1;
    fori(i, 0, n){
        if(arr[i] > 8){
            tot += 8;
            arr[i+1] += arr[i]-8;
        }else {
            tot += arr[i];
        }
        if(tot >= k){
            day = i+1;
            break;
        }
    }
    if(day == -1) printf("-1\n");
    else printf("%d\n", day);

    return 0;
}
