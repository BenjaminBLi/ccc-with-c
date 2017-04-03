#include <bits/stdc++.h>
using namespace std;

string line;
short high, low;
char c;
int main(){
    getline(cin, line);
    int lc=0,uc=0;
    getline(cin,line);
    for(int i = 0; i < line.length(); i++){
        if(line[i]>=97) lc++;
        else if(line[i]!=32) uc++;
    }
    if(lc<uc){
        int i=0;
        while(line[i])
        {
            printf("%c",toupper(line[i]));
            i++;
        }
    } else if(lc>uc){
        int i=0;
        while(line[i])
        {
            printf("%c",tolower(line[i]));
            i++;
        }
    } else if(lc==uc) cout << line << endl;
    return 0;
}
