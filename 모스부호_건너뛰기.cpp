#include <bits/stdc++.h>

using namespace std;
int skip;
int bino[201][201];
const int MAX = 1000000000 + 100;
void calcBino(){
    memset(bino, 0, sizeof(bino));
    for(int i = 0; i <= 200; i++){
        bino[i][0] = bino[i][i] = 1;
        for(int j = 1; j < i; j++){
            bino[i][j] = min(MAX, bino[i-1][j-1] + bino[i-1][j]);
        }
    }
}
string result = "";
// n개의 -, m개의 o 로 이루어진 신호중 skip개를 건너뛰고
// 만들어지는 신호를 반환한다.
string kth(int n, int m, int skip){
    // n = 0 인경우 나머지는 m개의 o로 이루어질 수 밖에 없다.
    if(n == 0) return string(m, 'o');
    if(skip < bino[n+m-1][n-1]){
        return "-" + kth(n-1, m, skip);
    }
    return "o" + kth(n, m-1, skip - bino[n+m-1][n-1]);
}

void generate3(int n, int m, string s){
    if(skip < 0) return;
    if(n == 0 && m == 0){
        if(skip == 0) cout << s << '\n';
        skip--;
        return;
    }
    if(bino[n+m][n] <= skip){
        skip -= bino[n+m][n];
        return;
    }
    if(n > 0) generate3(n-1, m, s+"-");
    if(m > 0) generate3(n, m-1, s+"o");

    return;
}
int main(){
    cout.sync_with_stdio(0);
    cin.tie(0);

    string s = "";
    int n, m, k;
    cin >> n >> m >> k;
    calcBino();
    skip = k-1;
    //generate3(n, m, s);
    cout << kth(n, m, skip);


    return 0;
}