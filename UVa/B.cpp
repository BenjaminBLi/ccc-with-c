#include <bits/stdc++.h>
#define fori(i, n) for(int i = 0, _n = n; i < _n; i++)
using namespace std;

char arr[4][4];
int dx[3] = {1, 0}, dy[3] = {0, 1}, r, c, xs, no;
bool poss = false;

int main(){
    fori(i, 4)fori(j, 4) scanf(" %c", &arr[i][j]);
    fori(r, 4){
        xs = 0; no = 0;
        fori(c, 4){
            if(arr[r][c] == 'x') xs++;
            else if (arr[r][c] == '.')no++;
            else{
                if((xs == 2 && no == 1) || xs > 2) poss = true;
                xs = 0;
                no = 0;
            }
        }
    }
    if((xs == 2 && no == 1) || xs > 2) poss = true;
    fori(c, 4){
        xs = 0; no = 0;
        fori(r, 4){
            if(arr[r][c] == 'x') xs++;
            else if (arr[r][c] == '.')no++;
            else{
                if((xs == 2 && no == 1) || xs > 2) poss = true;
                xs = 0;
                no = 0;
            }
        }
    }
    if((xs == 2 && no == 1) || xs > 2) poss = true;

    c = 2;
    xs = 0; no = 0;
    for(int r = 0; r < 3; r++){
        if(arr[r][c] == 'x') xs++;
            else if (arr[r][c] == '.')no++;
            else{
                if((xs == 2 && no == 1) || xs > 2) poss = true;
                xs = 0;
                no = 0;
            }
        c--;
    }
    if((xs == 2 && no == 1) || xs > 2) poss = true;
    c = 3;
    xs = 0; no = 0;
    fori(r, 4){
        if(arr[r][c] == 'x') xs++;
            else if (arr[r][c] == '.')no++;
            else{
                if((xs == 2 && no == 1) || xs > 2) poss = true;
                xs = 0;
                no = 0;
            }
        c--;
    }
    if((xs == 2 && no == 1) || xs > 2) poss = true;
    c = 3;
    xs = 0; no = 0;
    for(int r = 1; r < 4; r++){
        if(arr[r][c] == 'x') xs++;
            else if (arr[r][c] == '.')no++;
            else{
                if((xs == 2 && no == 1) || xs > 2) poss = true;
                xs = 0;
                no = 0;
            }
        c--;
    }
    if((xs == 2 && no == 1) || xs > 2) poss = true;
    c = 0; xs = 0; no = 0;
    fori(r, 4){
        if(arr[r][c] == 'x') xs++;
        else if (arr[r][c] == '.')no++;
        else{
            if((xs == 2 && no == 1) || xs > 2) poss = true;
            xs = 0;
            no = 0;
        }
        c++;
    }
    if((xs == 2 && no == 1) || xs > 2) poss = true;
    c = 1; xs = 0; no = 0;
    fori(r, 3){
        if(arr[r][c] == 'x') xs++;
        else if (arr[r][c] == '.')no++;
        else{
            if((xs == 2 && no == 1) || xs > 2) poss = true;
            xs = 0;
            no = 0;
        }
        c++;
    }
    if((xs == 2 && no == 1) || xs > 2) poss = true;
    c = 0; xs = 0; no = 0;
    for(int r = 1; r < 4; r++){
        if(arr[r][c] == 'x') xs++;
        else if (arr[r][c] == '.')no++;
        else{
            if((xs == 2 && no == 1) || xs > 2) poss = true;
            xs = 0;
            no = 0;
        }
        c++;
    }
    if((xs == 2 && no == 1) || xs > 2) poss = true;
    if(poss) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
