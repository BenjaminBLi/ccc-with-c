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
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int N;

int main(){
    scanf("%d", &N);
    int sum = 0;
    while(N) {
        int i;
        for(i = 2; i*i <= N; i++)
            if(N%i == 0) break;

        if(i < N && N%i == 0){
            int cval = N/i;
            N -= cval;
            sum += N/cval;
        }else{
            N--;
            sum += N;
        }
    }
    printf("%d\n", sum);
    return 0;
}
