#include <bits/stdc++.h>

using namespace std;

int cache[1001][101];
int n, w;
int volume[101]; // 용량
int need[101]; // 절박도
int itemNum;
string name[101];
// 남은 용량이 capacity일때 item 이후의 물건담아서 얻을 수 있는 최대 절박도.
int pack(int capacity, int item){
    // 기저사례 (더이상 담을 물건이 없을 때)
    if(item == n) return 0;
    int& result = cache[capacity][item];
    if(result != -1) return result;
    // 물건을 포함하지 않았을 때
    result = pack(capacity, item+1);
    // 이 물건을 포함 할 경우
    if(capacity >= volume[item]){
        result = max(result, pack(capacity - volume[item], item + 1) + need[item]);
    }
    return result;
}

void reconstruct(int capacity, int item, vector<string>& picked){
    if(item == n) return;
    if(pack(capacity, item + 1) == pack(capacity - volume[item], item + 1)){
        reconstruct(capacity, item+1, picked);
    }
    else{
        itemNum++;
        picked.push_back(name[item]);
        reconstruct(capacity - volume[item], item + 1, picked);
    }
}

int main(){
    cout.sync_with_stdio(0);
    cin.tie(0);

    int caseNum;
    cin >> caseNum;
    while(caseNum--){
        memset(cache, -1, sizeof(cache));
        itemNum = 0;
        vector<string> picked;
        cin >> n >> w;
        for(int i = 0; i < n; i++){
            cin >> name[i];
            cin >> volume[i];
            cin >> need[i];
        }
        int ret = pack(w, 0);
        reconstruct(w, 0, picked);
        cout << ret << " " << itemNum << '\n';
        for(int i = 0; i < picked.size(); i++){
            cout << picked[i] << '\n';
        }
    }

    return 0;
}