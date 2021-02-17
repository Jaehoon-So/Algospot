// https://algospot.com/judge/problem/read/NUMB3RS

#include <bits/stdc++.h>

using namespace std;
double cache[51][101];
int connected[51][51];
int deg[51];
int n, d, p, t, q;
// days일자에 here 에 있다고 가정하고, 마지막날에 q번 마을에 숨어있을 확률을 반환
double search(int here, int days){
    //cout << "search(" << q << ")" << '\n';
    if(days == d) return (here == q ? 1.0 : 0.0);
    double& result = cache[here][days];
    if(result > -0.5) return result;
    result = 0.0;
    for(int there = 0; there < n; there++){
        if(connected[here][there])
            result += search(there, days + 1) / deg[here];
    }
    return result;
}
int main(){
    cout.sync_with_stdio(0);
    cout.precision(8);
    cin.tie(0);

    int caseNum;
    cin >> caseNum;

    while(caseNum--){
        memset(cache, -1, sizeof(cache) );
        memset(connected, -1, sizeof(connected) );
        memset(deg, 0, sizeof(deg) );

        /*
        * n: 지도에 포함된 마을의 수
        * d: 지금까지 지난 일 수
        * p: 교도소가 있는 마을의 번호
        * t: 확률을 계산할 마을의 수
        * q: 확률을 계산할 마을의 번호
        */
        cin >> n >> d >> p;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> connected[i][j];
                if(connected[i][j]) deg[i]++;
            }
        }
        cin >> t;
        while(t--){
            memset(cache, -1, sizeof(cache) );
            cin >> q;
            double possible;
            //cout << "q: " << q << '\n';
            if((possible = search(p, 0) ) == 0) cout << "0.00000000" << " ";
            else
                cout << possible << " ";
        }
        cout << '\n';


    }

    return 0;
}