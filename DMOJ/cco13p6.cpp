#include "bits/stdc++.h"
using namespace std;

long long memo[10010], M;
char s[100010];
bool seen[1000];

int main(){
    scanf(" %s", s);
    scanf("%lld", &M);
    int len = strlen(s);
    memo[0] = 1;
    for(int i = 1; i <= len; i++){
        //cout << s[i] << endl;
        int prev = 0;
        if(seen[s[i-1]]) {
            seen[s[i-1]] = true;
            for (int j = 1; j < i; j++) {
                if(s[j-1] == s[i-1]) prev = memo[j-1];
                memo[j] += prev;
                memo[j] %= M;
            }
            memo[i] = memo[i - 1] << 1;
            memo[i] %= M;
        }else{
            seen[s[i-1]] = true;
            memo[i] = memo[i-1]<<1;
            memo[i] %= M;
        }
        //for(int k= 0; k<= len; k++) printf("%d, ", memo[k]); cout << endl;
    }
    cout << memo[len] << endl;
    return 0;
}
