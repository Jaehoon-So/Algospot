#include <iostream>
#include <vector>
#define MAX 
using namespace std;
int n, m;
int white, black;

const int coverType[4][3][2] = {
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}},  
};
// board의 (y,x)를 type번 블록으로 덮거나 지운다.
// delta = 1 이면 덮고, delta = -1이면 지운다.
bool set(vector<vector<int>> &board, int y, int x, int type, int delta){
    bool ok = true;
    for(int i = 0; i < 3; ++i){
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
    
        if(ny < 0 || ny > board.size() || nx < 0 || nx >= board[0].size())
            ok = false;
        else if((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}
int cover(vector<vector<int> >& board){
    // 아직 채우지 못한 칸 중 가장 위쪽에 있는 칸을 찾는다.
    int y = -1; int x = -1;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            // board[i][j] = 0: (i,j)가 아직 덮이지 않음
            // board[i][j] = 1: (i,j)가 덮임.
            if(board[i][j] == 0){
                y = i;
                x = j;
                break; // 최초로 쓰이지 않은 좌표만 택하고 탈출한다.
            }
        }  
        if(y != -1) break; // 좌표를 선택했는지 여부를 확인하고 선택했다면 탈출.
    }
    if(y == -1) return 1;
    int ret = 0;
    for(int type = 0; type < 4; type++){
        if(set(board, y, x, type, 1))
            ret += cover(board);
        set(board, y, x, type, -1);
    }
    return ret;
}

int main(){
    
    int c;
    cin >> c;
    while(c--){
        white = black = 0;
        int h, w;
        cin >> h >> w;
        vector<vector<int> > board(h, vector<int>(w, 0));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                char color = getchar();
                if(color == '\n') {j--; continue;}
                else if(color == '#') {board[i][j] = 1; black++;}
                else if(color == '.') {board[i][j] = 0; white++;}

            }
        }
        if(white%3 == 0) cout << 0 << endl;
        else cout << cover(board) << endl;
    }
    return 0;
}
