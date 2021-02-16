#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int c; cin >> c;
    while(c--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            int height; cin >> height;
            v[i] = height;
        }
        int maxSpace = 0;
        int ret = 0;
        int N = v.size();
        for(int left = 0; left < N; left++){
            int minHeight = v[left];
            for(int right = left; right < N; right++){
                minHeight = min(minHeight, v[right]);
                ret = max(ret, (right - left + 1) * minHeight ); // 완전탐색하면서 출력
            }
        }

        cout << ret << '\n';

    }

    return 0;
}