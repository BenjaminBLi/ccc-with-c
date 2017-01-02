#include <bits/stdc++.h>
using namespace std;

char ch, t;
int r, c, arr[200][200], q1r, q1c, q2r, q2c, q3r, q3c, q4r, q4c;
/**
q1: top left
q2: top right
q3: bottom left
q4: bottom right
*/
int main(){
    while(scanf("%c", &ch) && ch != '#'){
        scanf("%d %d", &r, &c);
        for(int i = 0; i < r; i++) for(int i = 0; i < c; i++){
            scanf("%c", &t);
            arr[i][j] = t == '0' ? 0 : 1;
        }
        q1r = q2r = q3r = q4r = r/2;
        q1c = q2c = q3c = q4c = c/2;
        if(r&1){
            q1r++; q2r++;
        }if(c&1){
            q1c++; q3c++;
        }
        //
    }
    return 0;
}
