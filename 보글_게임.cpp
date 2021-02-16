/*
보글은 상하좌우 / 대각선으로 인접한 칸들의 글자들을 이어서 단어를 찾아내는 것이다
각 글자들은 대각선으로도 이어질 수 있으며, 한 글자가 두번 이상 사용될 수도 있다.
주어진 칸에서 시작해서 특정단어를 찾을 수 있는지 확인하는 알고리즘은 작성해보자.
*/

#include <iostream>
#include <string>

using namespace std;
char gameBoard[5][5] = {
    {'U','R','L','P','M'},
    {'X','P','R','E','T'},
    {'G','I','A','E','T'},
    {'X','T','N','Z','Y'},
    {'X','O','Q','R','S'},
};
// 방향을 8개의 좌표로 나타냄.
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
// 해당 좌표가 보드판 내부에 위치하는지 확인.
bool inRange(int y, int x){
    if(y < 0 || x < 0)
        return false;
    else
        return true;    
}

bool hasWord(int y, int x, const string& word){
    // 기저사례1: 보드 바깥범위로 접근하면 false 리턴
    if(!inRange(y,x)) return false;
    // 기저사례2: 첫글자가 틀리면 false 리턴.
    if(gameBoard[y][x] != word[0]) return false;
    // 기저사례3: 글자가 하나로 이루어진 문자열일 경우 true를 리턴.
    if(word.size() == 1) return true;
    // 각각의 방향에 대해서
    for(int direction = 0; direction < 8; ++direction){
        // 다음 위치를 선정 한 후
        int nextY = y + dy[direction], nextX = x + dx[direction];
        // 다음위치에 대해서 hasWord의 재귀함수 실행, word의 경우 앞의 한문자를 자른 것으로
        // 새로 넣어준다.
        if(hasWord(nextY, nextX, word.substr(1))){
            return true;
        }
  }

}

int main(){
    
    string word;
    cin >> word;
    int x, y;
    cin >> x >> y;
    if(hasWord(y, x, word))
        cout << word << " is exist";
    else
        cout << word << " is not exist";
    return 0;
}