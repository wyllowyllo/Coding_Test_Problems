#include <bits/stdc++.h>
using namespace std;


//모든 친구 순서를 다 생성하고, 거기서 필요한 만큼(1명일 수도, 또 최대 8명일 수도) 
//k명만 쓰는 방식

//왜 순열인가=>친구마다 커버 거리가 다르니, 누굴 먼저 보내느냐에 따라 결과가 달라집니다.
const int INF = 1e9;



vector<int> changeStartIndex(vector<int> weak, int start, int n) {
    if (start == 0) return weak; //시작지점이 0이면 원래벡터 반환

    vector<int> ret;
    for (int i = start; i < weak.size(); i++) ret.push_back(weak[i]); //시작 지점부터 끝까지
    for (int i = 0; i < start; i++) ret.push_back(weak[i] + n); //원의 시작으로 다시 돌아오는 구간. 따라서 n을 더함

    return ret;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int ret = INF;

    sort(dist.begin(), dist.end());

    do {

        //정해진 순열(투입 순서)에 대해, 첫번째 인력이 어느 위치에 투입되는지가 결정되면, 이후에는 첫번째 인력이 커버 못하는 범위가 있을 때 다음사람 투입... 다음사람 투입... 이런식임
        for (int j = 0; j < (int)weak.size(); j++) {
            vector<int> weakList = changeStartIndex(weak, j, n); //원형 구조 -> 선형적인 리스트로 변환. 이때 시작 위치를 바꿔가며 리스트를 재생성함

            int idx = 0, flag = 0;

            int curr = weakList[0] + dist[0]; //첫 인력이 커버할 수 있는 최대거리

            for (int i = 1; i < weakList.size(); i++) {
                if (weakList[i] > curr) { //현재 인력이 현재 시작위치에서 검사 시 커버하지 못하는 지점
                    if (idx + 1 == dist.size()) {
                        flag = 1; break; //모든 인력을 사용한 경우, 실패
                    }
                    curr = weakList[i] + dist[++idx]; //다음 인력을 배치
                }
            }

            if (!flag) ret = min(ret, idx + 1);
        }

    } while (next_permutation(dist.begin(), dist.end()));

    return (ret == INF ? -1 : ret);
}