#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>

#define MAX 100
using namespace std;
int Board[MAX][MAX];
int cache[MAX][MAX];
int n;
int jumpGame(int y, int x){

    
    if(y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;

    int& ret = cache[y][x];
    if(ret != -1) return ret;
    int jumpSize = Board[y][x];
    return ret = (jumpGame(y+jumpSize, x) || jumpGame(y, x+jumpSize) );

}
int main(){

    int c; cin >> c;
    while(c--){
        memset(Board, -1, sizeof(Board));
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int dy = 0; dy < n; dy++){
            for(int dx = 0; dx < n; dx++){
                int num; cin >> num;
                //printf("Board[%d][%d] = %d\n", dy, dx, num);
                Board[dy][dx] = num;
            }
        }
        if(jumpGame(0, 0)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        //cout << jumpGame(0, 0) << '\n';
    }
    return 0;
}