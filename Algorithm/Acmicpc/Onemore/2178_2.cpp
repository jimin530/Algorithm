//
//  2178_2.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 1..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  미로 탐색
//  https://www.acmicpc.net/problem/2178
//

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int dis[101][101];
int a[101][101];
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int x, int y, int cnt) {
    std::queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    dis[x][y] = cnt;
    
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(a[nx][ny] == 1 && dis[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

//    for(int i = 0 ; i < n ; i++) {
//        for(int j = 0 ; j < m ; j++) {
//            if(a[i][j] == 1 && dis[i][j] == 0) {
//                bfs(i, j, ++cnt);
//            }
//        }
//    }
    bfs(0, 0, 1);
    
    printf("%d\n",dis[n-1][m-1]);
    
    return 0;
}
