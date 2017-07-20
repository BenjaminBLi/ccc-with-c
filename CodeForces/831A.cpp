#include <bits/stdc++.h>
using namespace std;

int n, arr[110];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    bool inc = true, ok = true;
    if (n == 1) printf("YES\n");
    else {
        bool dec = false, inc = false, mid = false, ok = true;
        int id = 0;
        for(int i = 1; i < n; i++){
            if(arr[i-1] == arr[i]){
                if(id > 1) ok = false;
                else if(id == 0){
                    mid = true;
                    id++;
                }
            }else if(arr[i-1] < arr[i]){
                if(id) ok = false;
                else inc = true;
            }else if(arr[i-1] > arr[i]){
                dec = true;
                if(id == 0){
                    id = 2;
                    dec = true;
                }
                else if(id == 1){
                    id++;
                }
            }
        }
        //printf("%c %c\n", inc ? 'T' : 'F', dec ? 'T' : 'F');
        if(ok && ((!dec && !inc) || (dec && inc))) printf("YES\n");
        else printf("NO\n");
    }
}
