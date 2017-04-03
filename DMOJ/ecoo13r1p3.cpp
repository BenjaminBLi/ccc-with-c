#include <bits/stdc++.h>
using namespace std;

int grid[16][16];
map<char, int> id;

void gen(){
	id['A'] = 10;
	id['B'] = 11;
	id['C'] = 12;
	id['D'] = 13;
	id['E'] = 14;
	id['F'] = 15;
	id[(char)45] = -1;
}
bool valid(int r, int c, int val){
	int qr = (r/4)*4, qc = (c/4)*4;
	for(int i = 0; i<4; i++) for(int j = 0; j < 4; j++){
		if(grid[qr+i][qc+j] == val) return false;
	}
	for(int i =0;i < 16; i++) if(grid[r][i] == val || grid[i][c] == val) return false;
	return true;
}

int main(){
	gen();
	int T = 10;
	for(;T--;){
		for(int r = 0; r < 16; r++){
			for(int c = 0; c < 16; c++){
				char ch; scanf(" %c", &ch);
				if('0' <= ch && ch <= '9') grid[r][c] = ch-'0';
				else grid[r][c] = id[ch];
			}
		}
		int cnt = 0;
		for(int r = 0; r < 16; r++){
			for(int c = 0; c < 16; c++){
				if(grid[r][c] != -1) continue;
				for(int val = 0; val < 16; val++){
					if(valid(r, c, val)){
						grid[r][c] = val;
						cnt++;
						break;
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}