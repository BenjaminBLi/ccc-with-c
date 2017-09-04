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

int N, S, m[20];

int solve(int mask, int c, bool flag){
    if(mask == (1<<N)-1) {
        return m[c];
    }
    int ans;
    if(flag){

    }else{

    }

}

int main(){
    scanf("%d %d", &N, &S);
    fori(i, 0, N) scanf("%d", m+i);


    return 0;
}
