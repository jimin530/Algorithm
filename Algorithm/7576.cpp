//
//  7576.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 1..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  토마토
//  https://www.acmicpc.net/problem/7576
//

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int check[1001][1001];
int a[1001][1001] = {-1,};
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int day = 0;
int totalCnt = 0;
int cnt = 0;
std::queue<pair<int, int>> q;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            scanf("%1d", &a[i][j]);
            if(a[i][j] != -1) {
                totalCnt++; // 총 토마토 개수
                
                // 익은 토마토일 때
                if(a[i][j] == 1) {
                    cnt++; // 익은 토마토 개수
                    
                    // 큐에 넣음
                    q.push(make_pair(i, j));
                    // 몇 번째 날 익었다고 체크
                    check[i][j] = 1;
                    // 현재 며칠째인가
                    day = check[i][j];
                }
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                // 안익은 사과일 때 && 체크가 0일 때(아직 안지나갔으면)
                if(a[nx][ny] == 0 && check[nx][ny] == 0 ) {
                    q.push(make_pair(nx, ny));
                    // 익은 토마토 개수
                    cnt++;
                    check[nx][ny] = check[x][y] + 1;
                    day = check[nx][ny];
                }
            }
        }
    }
    if(totalCnt == cnt) {
        printf("%d", day - 1);
    } else {
        printf("%d", -1);
    }
    
    return 0;
}
