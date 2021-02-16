#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<int> h; // 블록들의 높이를 저장할 벡터.
int solve(int left, int right){
    // 기저사례: 하나의 블록을 가리킬 경우
    if(left == right) return h[left]; // h[right] 도 상관없다.
    
    int mid = (left + right) / 2; // 문제를 두 구구나으로 분할 한다.
    int ret = max(solve(0, mid), solve(mid+1, right) );
    int lo = mid, hi = mid+1;
    int height = min(h[lo], h[hi]);

    ret = max(ret, height*2);

    while(left < lo || hi < right){
        if(hi < right && (lo == left || h[lo-1] < h[hi+1]) ){
            hi++;
            height = min(height, h[hi]);
        }
        else{
            lo--;
            height = min(height, h[lo]);
        }

        ret = max(ret, (hi-lo+1) * height);
    }
    return ret;
}
int main(){
    int c; cin >> c; // 케이스의 갯수
    while(c--){ // 케이스의 갯수만큼 반복
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int height; cin >> height;
            h[i] = height;
        }
        cout << solve(h[0], h[n-1]) << '\n'; 
    }

    return 0;
}