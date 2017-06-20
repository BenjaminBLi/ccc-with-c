#include "bits/stdc++.h"
using namespace std;

map<int, int> behaviour;
map<int, string> flip;
char line[110];

void gen(){
    flip[2] = "abc";
    flip[3] = "def";
    flip[4] = "ghi";
    flip[5] = "jkl";
    flip[6] = "mno";
    flip[7] = "pqrs";
    flip[8] = "tuv";
    flip[9] = "wxyz";
}

int main(){
    gen();
    for(int i = 1; i <= 9; i++){
        int id;
        scanf("%d", &id);
        behaviour[id] = i;
    }
    scanf(" %s", line);
    bool found;
    int prev = -1;
    int len = strlen(line);
    for(int i =0 ; i < len; i++){
        char ch = line[i];
        //cout << ch << endl;
        for(auto it : flip){
            found = false;
            int fIdx = -1, idx = 0;
            for(char let : it.second){
                ++idx;
                if(let == ch) fIdx = idx, found = true;
            }
            if(found){
                if(prev == it.first){
                    printf("#");
                }
                for(int i = 0; i < fIdx; i++){
                    printf("%d", behaviour[it.first]);
                }
                prev = it.first;
                break;
            }
        }
    }

    return 0;
}
