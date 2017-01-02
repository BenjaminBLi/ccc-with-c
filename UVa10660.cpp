#include <bits/stdc++.h>
using namespace std;

int T, n, pop[25], a, b, c;

int calc(int d, int o){
    return abs(d/5-(o/5)) + abs(d%5-o%5);
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for(;T--;){
        scanf("%d", &n);
        memset(pop, 0, sizeof(pop));
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &a, &b, &c);
            pop[a*5+b] = c;
        }
        //for(int i = 0; i < 25; i++) printf("%d ", pop[i]);
        //cout << endl;
        int bdist = (1<<30), dist = 0;
        int o1 = -1, o2 = -1, o3 = -1, o4 = -1, o5 = -1;
        //cout << bdist << endl;
        //cout << "YES" << endl;
        for(int i = 0; i < 21; i++){
            for(int j = i+1; j < 22; j++){
                for(int k = j+1; k < 23; k++){
                    for(int l = k+1; l < 24; l++){
                        for(int m = l+1; m < 25; m++){
                            dist = 0;
                            for(int r = 0; r < 25; r++){
                                if(pop[r] > 0){
                                    int tmp = calc(r, i);
                                    tmp = min(tmp, calc(r, j));
                                    tmp = min(tmp, calc(r, k));
                                    tmp = min(tmp, calc(r, l));
                                    tmp = min(tmp, calc(r, m));
                                    dist += pop[r]*tmp;
                                    //cout << tmp << endl;
                                }
                            }
                            //if(dist == 0) printf("%d %d %d %d %d\n", i, j, k, l, m);
                            if(dist < bdist){
                                //cout << dist << endl;
                                bdist = dist;
                                o1 = i; o2 = j; o3 = k; o4 = l; o5 = m;
                            }
                            //cout << m << endl;
                        }
                    }
                    //cout << k << endl;
                }
                //cout << j << endl;
            }
            //cout << i << endl;
        }
        printf("%d %d %d %d %d\n", o1, o2, o3, o4, o5);
    }
    return 0;
}
