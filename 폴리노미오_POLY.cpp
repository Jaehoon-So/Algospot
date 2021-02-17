#include <bits/stdc++.h>

using namespace std;

const int MOD = 10000000; // 10,000,000
/* cache에는 (n, first) n개의 정사각형을 첫줄에 first개가 놓였을때의 값을 저장 */
int cache[101][101];
// n개의 정사각형을가지고 첫줄에 first개의 정사각형이 
// 놓였을 때 가능한 폴리오미노의 갯수를 반환한다.
int poly(int n, int first) {
    // 기저사례
    if (n == first) return 1;
    int& result = cache[n][first];
    if (result != -1) return result;
    result = 0;
    for (int second = 1; second <= n - first; second++) {
        int add = first + second - 1;
        add *= poly(n - first, second);
        add %= MOD;
        result += add;
        result %= MOD;
    }
    return result;
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);

    int caseNum;
    cin >> caseNum;
    while (caseNum--) {
        memset(cache, -1, sizeof(cache));
        int n;
        cin >> n;
        cout << poly(n, 0) << '\n';
    }

    return 0;
}