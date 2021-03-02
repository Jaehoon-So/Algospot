#include <bits/stdc++.h>

using namespace std;

// n: 더 필요한 -의 갯수
// m: 더 필요한 o의 갯수
// s: 지금까지 만든 기호의 갯수
void generate(int n, int m, string s){
    if(n == 0 && m == 0){
        cout << s << '\n';
        return;
    }
    if(n > 0) generate(n-1, m, s + "-");
    if(m > 0) generate(n, m-1, s + 'o');

    return;
}

int main(void){
    cout.sync_with_stdio(0);
    cin.tie(0);
    string s = "";
    int n, m;
    cin >> n >> m;
    generate(n, m, s);

    return 0;
}