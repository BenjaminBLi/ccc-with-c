#include <bits/stdc++.h>
using namespace std;

map<char, char> flip;
string l1, l2;

int main(){
    cin >> l1 >> l2;
    for(int i = 0; i < 26; i++){
        flip[l1[i]] = l2[i];
        flip[(char)toupper(l1[i])] = (char) toupper(l2[i]);
    }
    string word;
    cin >> word;
    for(char c : word){
        if(!flip.count(c)) putchar(c);
        else putchar(flip[c]);
    }
    cout << "\n";


    return 0;
}
