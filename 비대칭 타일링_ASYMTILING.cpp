// https://www.algospot.com/judge/problem/read/ASYMTILING
#include <bits/stdc++.h>

using namespace std;
int cache[101];
int countCache[101];
const int MOD = 1000000007; // 1,000,000,007

// 2 x width 인 타일이 있을때 타일을 채울수 있는 방법의 수를 반환한다.
int tiling(int width){
    /* 남은 타일의 갯수가 0칸, 혹은 한칸이라면 1을 반환한다. */
    if(width <= 1) return 1;
    int& ret = cache[width];
    if(ret != -1) return ret;
    return tiling(width - 1) + tiling(width - 2);
}
//2*width 크기의 사각형을 채우는 비대칭 방법의 수를 반환한다.
int asymmetry(int width){
    if(width % 2 == 1){
        return (tiling(width) - tiling(width/2) + MOD) % MOD;
    }
    else{
        int result = tiling(width);
        result = (result - tiling(width/2 - 1) + MOD) % MOD;
        result = (result - tiling(width/2) + MOD) % MOD;
        return result;
    }
}

int main(){
    cout.sync_with_stdio(0);
    cin.tie(0);
    int caseNum;
    cin >> caseNum;
    while(caseNum--){
        memset(cache, -1, sizeof(cache) );
        int width;
        cin >> width;
        cout << asymmetry(width) << '\n';
    }

    return 0;
}

