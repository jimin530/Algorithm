//
//  4963_2.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 30..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  섬의 개수
//  https://www.acmicpc.net/problem/4963
//

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int a[100][100];
int check[100][100];
int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};
int n,m;

void bfs(int x, int y, int cnt) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = cnt;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int k = 0 ; k < 8 ; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(a[nx][ny] == 1 && check[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = cnt;
                }
            }
        }
    }
}

void dfs(int x, int y, int cnt) {
    check[x][y] = cnt;
    
    for(int i = 0 ; i < 8 ; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if (0 <= xx && xx < n && 0 <= yy && yy < m) {
            if(a[xx][yy] == 1 && check[xx][yy] == 0) {
                dfs(xx, yy, cnt);
            }
        }
    }
}
int main() {
    while (true) {
        scanf("%d %d",&m,&n);
        if (n == 0 && m == 0) break;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%d", &a[i][j]);
                check[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 1 && check[i][j] == 0) {
                    //dfs(i, j, ++cnt);
                    bfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
