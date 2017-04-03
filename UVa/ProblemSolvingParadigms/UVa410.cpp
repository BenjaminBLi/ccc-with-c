#include <bits/stdc++.h>
using namespace std;

int C, S, tmp, cnt;
double am, imb;
vector<int> spec;
int main(){
    cnt = 1;
    //freopen("in.txt", "r", stdin);
    while(scanf("%d %d", &C, &S) != EOF){
        printf("Set #%d\n", cnt++);
        spec.clear(); am = 0; imb = 0;
        if(S < C+C) spec.assign(C+C-S, 0);
        for(int i = 0; i < S; i++){
            scanf("%d", &tmp);
            spec.push_back(tmp);
            am += tmp;
        }
        sort(spec.begin(), spec.end());
        am /= 1.0*C;
        for(int i = C-1; i >= 0; i--){
            printf(" %d:", C-1-i);
            tmp = spec[i] + spec[C+C-1-i];
            if(spec[i]) printf(" %d", spec[i]);
            if(spec[C+C-1-i]) printf(" %d", spec[C+C-1-i]);
            printf("\n");
            imb += abs(tmp-am);
        }
        printf("IMBALANCE = %.05lf\n\n", imb);
    }
    return 0;
}
