#include <bits/stdc++.h>
using namespace std;

int n;
char fin[1001010];
bool covered[1001010];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int en = 0;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        int strLen = word.size();
        int cLen;
        cin >> cLen;
        for(int j = 0; j < cLen; j++){
            int tmp;
            cin >> tmp;
            for(int a = 0; a < strLen; a++){
                covered[tmp+a] = true;
                fin[tmp+a] = word[a];
                en = max(en, tmp+a);
            }
        }
    }
    for(int i = 1; i <= en; i++){
        if(!covered[i]) putchar('a');
        else putchar(fin[i]);
    }

    return 0;
}
