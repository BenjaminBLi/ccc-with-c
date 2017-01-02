#include <bits/stdc++.h>
using namespace std;

int s, d, m[12], best;

bool solve(int month){
    if(month > 4)
        if(accumulate(m+month-5, m+month, 0) > 0) return false;
    if(month == 12){
        int yr = accumulate(m, m+12, 0);
        if(yr <= 0) printf("Deficit\n");
        else printf("%d\n", yr);
        return true;
    }
    m[month] = s;
    if(!solve(month+1)){
        m[month] = -d;
        return solve(month+1);
    }
    return true;
}

int main(){
    //freopen("in.txt", "r", stdin);
    while(scanf("%d %d", &s, &d) != EOF){
        best = 0;
        solve(0);
    }
    return 0;
}
