#include <bits/stdc++.h>
using namespace std;

int n, s[100010];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", s+i);
    sort(s, s+n);

    int minR = 2000000;
    for(int i = 0; i < n/2; i++){
        if(minR > s[i] + s[n-i-1]) minR = s[i] + s[n-i-1];
    }
    printf("%d\n", minR);

    return 0;
}