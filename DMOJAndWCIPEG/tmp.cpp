#include <bits/stdc++.h>
using namespace std;
string s1, s2;

int main(){
    cin >> s1 >> s2;
    bool ok = false, valid;
    int diff = s1.size()-s2.size() > 0 ? 0 : s1.size()-s2.size();
    for(int i = 0; i < diff; i++)
        cout << s1[i];
    for(int s = diff; s < s1.size(); s++){
        valid = true;
        cout << s1[s];
        for(int i = 0; i < s2.size() && s+i < s1.size(); i++){
            if(s1[s+i] != s2[i]){
                valid = false;
                break;
            }
        }
        if(valid){
            for(int i = 1; i < s2.size(); i++) cout << s2[i];
            ok = true;
            break;
        }
    }
    if(!ok){
        for(int i =0 ; i < s2.size(); i++) cout << s2[i];
    }
    return 0;
}
