#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

namespace MySol {

    int a[60][60];
    int X = 20; int Y = 20;
    int cnt = 0; //자물쇠 홈 개수
    void RotateKey(vector<vector<int>>& key) {
        int m = key[0].size();


        vector<vector<int>> ret(m, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = key[m - j - 1][i];
            }
        }

        key = ret;
    }

    bool inLock(int ROW, int COL, int n) {
        return ROW >= Y && ROW < Y + n && COL >= X && COL < X + n;
    }
    bool check(vector<vector<int>>& key, vector<vector<int>>& lock, int offset_x, int offset_y) {
        int m = key[0].size();
        int n = lock[0].size();
        int h = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                //키의 (i,j) 위치를, 확장 격자 a에서 (ROW, COL) = (Y+i+dy, X+j+dx) 로 대응시킴
                int ROW = Y + i + offset_y;
                int COL = X + j + offset_x;

                //그 칸이 자물쇠 내부일 때에만 검사
                if (inLock(ROW, COL, n)) {
                    if (a[ROW][COL] == 1 && key[i][j] == 1) return false;
                    else if (a[ROW][COL] == 0 && key[i][j] == 0) return false;
                    else if (a[ROW][COL] == 0 && key[i][j] == 1) h++;
                }

            }
        }

        if (cnt == h) return true;
        else return false;
    }

    bool Try(vector<vector<int>>& key, vector<vector<int>>& lock) {

        int m = key[0].size();
        int n = lock[0].size();
        int offset_x, offset_y;

        //offset 설정
        for (int i = -m + 1; i < n - 1; i++) {
            for (int j = -m + 1; j < n - 1; j++) {
                offset_x = j;
                offset_y = i;

                if (check(key, lock, offset_x, offset_y)) return true;
            }
        }

        return false;
    }

    bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
        bool answer = false;

        //자물쇠 여유있는 격자로 옮김
        int n = lock[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[Y + i][X + j] = lock[i][j];
                if (lock[i][j] == 0) cnt++;
            }
        }

        //열쇠 회전&이동
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> tmp = key;
            for (int j = 0; j < i; j++) {
                RotateKey(tmp); //회전
            }

            //맞춰보기
            if (Try(tmp, lock))
                return true;
        }
        return answer;
    }
}

namespace Sol {

    void _rotate(vector<vector<int>>& key) {
        int m = key.size();
        vector<vector<int>> tmp(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = key[m - j - 1][i];
            }
        }
        key = tmp;
        return;
    }
    bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
        int m = key.size(), n = lock.size(), cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lock[i][j] == 0) cnt++; //필요한 핀의 수를 카운트
            }
        }

        for (int k = 0; k < 4; k++) { //최대 4번 회전(360도)

            //열쇠를 이동시킬 정도(x,y offset)
            //x,y offset 범위 구하기

            //열쇠의 첫번째 행(0)이 자물쇠의 마지막 행(n-1)에 딱 맞닿으려면 0 + offset = n-1, offset=n-1
             //열쇠의 마지막 행(m-1)이 자물쇠의 첫번째 행(0)에 딱 맞닿으려면 m-1 + offset = 0, offset=-(m-1)
            //따라서 x,y 의 offset범위는 아래 반복문과 같다. -(m-1) <= offset <= n-1
            for (int i = -m + 1; i <= n - 1; i++) {
                for (int j = -m + 1; j <= n - 1; j++) {
                    int _count = 0, flag = 0;

                    for (int y = 0; y < m; y++) {
                        for (int x = 0; x < m; x++) {
                            int ny = y + i;
                            int nx = x + j;

                            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                            if (lock[ny][nx] == 1 && key[y][x] == 1) flag = 1; //돌기끼리 만나면 안됨
                            else if (lock[ny][nx] == 0 && key[y][x] == 1) _count++; //key의 돌기가 lock의 홈을 채우는 경우 카운트
                        }
                    }

                    if (_count == cnt && !flag) return true; //모든 필요한 홈이 채워지고, 돌기끼리 만나지 않으면 true반환
                }
            }
            _rotate(key);
        }
        
        return false;
    }
}
