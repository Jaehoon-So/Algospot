// https://algospot.com/judge/problem/read/CLOCKSYNC

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 9999, SWITCHES = 10, CLOCKS = 16;
int clock[16];
int minimum = MAX;
char linked[SWITCHES][CLOCKS + 1] = { // NULL문자도 저장이되므로 clock+1로 지정
    // x: 연결된 시계, .: 연결되지 않은 시계.
    {"xxx............."},
    {"...x...x.x.x...."},
    {"....x.....x...xx"},
    {"x...xxxx........"},
    {"......xxx.x.x..."},
    {"x.x...........xx"},
    {"...x..........xx"},
    {"....xx.x......xx"},
    {".xxxxx.........."},
    {"...xxx...x...x.."},
};
// 모든 시계가 12시를 가리키고 있는지 확인.
bool areAligned(vector<int>& clock) {
    for (int i = 0; i < 12; i++) {
        if (clock[i] != 12)
            return false;
    }
    return true;
}
// switches번째 스위치를 눌렀을때.
void push(vector<int>& clock, int swtch) {
    for (int i = 0; i < CLOCKS; i++) {
        if (linked[swtch][i] == 'x') {
            clock[i] += 3;
            if (clock[i] == 15) clock[i] = 3;
        }
        
    }
}
int clockSync(vector<int>& clock, int swtch) {
    if (swtch == SWITCHES) return areAligned(clock) ? 0 : MAX;
    int ret = MAX;
    for (int i = 0; i < 4; i++) { // 모든 스위치는 3번까지만 누를 수 있음.
        ret = min(ret, i + clockSync(clock, swtch + 1));
        push(clock, swtch);
    }
    return ret;
}

int main() {
    int c;
    cin >> c; // 케이스의 갯수.
    while (c--) {
        vector<int> clock(16);
        for (int i = 0; i < 16; i++) {
            int time;
            cin >> time;
            clock[i] = time;
            //cout << "clock[" << i << "] = " << time << endl;
        }
        cout << clockSync(clock, 0) << endl;
    }
}