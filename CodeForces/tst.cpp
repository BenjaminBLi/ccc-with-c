#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
using namespace std;

int a, b, n, t;

int main(){
    scanf("%d %d %d", &n, &a, &b);
    int cnt = 0;
    b *= 2;
    fori(i, 0, n){
        scanf("%d", &t);
        if(t == 1){
           if(a > 0){
               a--;
           }else if(b > 0){
               b--;
           }else{
               cnt++;
           }
        }else{
            if(b/2 > 0){
                b -= 2;
            }else{
                cnt += 2;
            }
        }
    }
    printf("%d\n", cnt);


    return 0;
}
