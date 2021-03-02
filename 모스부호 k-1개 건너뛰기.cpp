#include <bits/stdc++.h>

using namespace std;

// n: 남은 '-' 갯수
// m: 남은 'o' 갯수
// s: 지금까지 만든 모스신호
int skip;
void generate2(int n, int m, string s){
    if(skip < 0) return;
    // 기저사례
    if(n == 0 && m == 0){
        if(skip == 0) cout << s << '\n';
        // n = 0, m = 0이 될때마다 하나의 경우가 된다는 것을 기억하자.
        --skip;
        return;
    }

    if(n > 0) generate2(n-1, m, s+"-");
    if(m > 0) generate2(n, m-1, s+"o");
}

int main(){
    cout.sync_with_stdio(0);
    cin.tie(0);

    string s = "";
    int n, m, k; // k번째 것을 출력한다.
    cin >> n >> m >> k;
    skip = k-1;
    generate2(n, m, s);

    return 0;
}