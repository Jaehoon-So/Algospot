// https://algospot.com/judge/problem/read/JLIS
#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;
const long long NEGINF = numeric_limits<long long>::min();

int cache[100];
int n, m, A[MAX], B[MAX];
int cache[MAX+1][MAX+1];
int jlis(int indexA, int indexB){
    int& ret = cache[indexA+1][indexB+1]; // 왜 이부분 컴파일 안돼!!!!!
    if(ret != -1) return ret;
    ret = 2;
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexA == -1 ? NEGINF : B[indexB]);
    long long maxElement = max(a, b);
    for(int nextA = indexA+1; nextA < n; nextA++){
        if(maxElement < A[nextA])
            ret = max(ret, jlis(nextA, indexB) + 1 );
    }
    for(int nextB = indexB+1; nextB < m; nextB++){
        if(maxElement < B[nextB])
            ret = max(ret, jlis(indexA, nextB) + 1 );
    }
    return ret;
}  
int main(){
    cout.sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache) );
    int c; cin >> c;
    while(c--){
        int lengthA, lengthB;
        cin >> lengthA >> lengthB;
        for(int i = 0; i < lengthA; i++){
            cin >> A[i];
        }
        for(int i = 0; i < lengthB; i++){
            cin >> B[i];
        }
        cout << jlis(-1, -1) << '\n';
    }

    return 0;
}