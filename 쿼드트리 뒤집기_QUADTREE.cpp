
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10000000
string s;


char decompressed[16][16];
/* 압축을 푸는 함수를 작성하였으나, 압출을 풀면서 뒤집는 과정을 동시에 할수
있는 방법을 발견하여 주석처리 하였다.
이함수는 압축을 전부 푼 배열을 얻는 함수로, 그 배열의 원소를 하나하나 뒤집는 방법을
사용할때 사용하는 함수이다.
void decompressor(string::iterator& it, int y, int x, int size){
    char head = *(it++); // 한문자를 읽을 때마다 반복자를 한칸 증가시킨다.
    cout << "head: " << head << " " << endl;
    if(head == 'd' || head == 'w'){
        for(int dy = 0; dy < size; dy++){
            for(int dx = 0; dx < size; dx++){
                decompressed[y+dy][x+dx] = head;
                printf("devompressed[%d][%d] = %c\n", y+dy, x+dx, head);
            }
        }
    }
    else{
        int half = size / 2;
        decompressor(it, y, x, half);
        decompressor(it, y+half, x, half);
        decompressor(it, y, x+half, half);
        decompressor(it, y+half, x+half, half);
    }
}
*/
string Reverse(string::iterator& it){
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w'){
        //cout << string(1, head) << endl;
        return string(1, head); // head를 한개 채워서 리턴.
    } 
    string upperLeft = Reverse(it);
    string upperRight = Reverse(it);
    string lowerLeft = Reverse(it);
    string lowerRight = Reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
int main(){
    int c;
    cin >> c;
    int size = 16;
    while(c--){
        cin >> s;
        string::iterator start = s.begin();
        // string::iterator start = s.begin();
        //decompressor(start, 0, 0, size);
        cout << Reverse(start) << endl;
    }
}