//
//  2667_2.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 27..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  단지번호붙이기
//  https://www.acmicpc.net/problem/2667
//

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int a[30][30];
int check[30][30];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n = 0;
int ans[25*25];

void bfs(int x, int y, int cnt) {
    std::queue<pair<int, int>> q;
    check[x][y] = cnt;
    q.push(make_pair(x, y));
    
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (a[nx][ny] == 1 && check[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = cnt;
                }
            }
        }
    }
}

void dfs(int x, int y, int cnt) {
    check[x][y] = cnt;
    for (int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (a[nx][ny] == 1 && check[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && check[i][j] == 0) {
                //dfs(i, j, ++cnt);
                bfs(i, j, ++cnt);
            }
        }
    }
    printf("%d\n",cnt);
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            ans[check[i][j]] += 1;
        }
    }
    
    std::sort(ans+1, ans+cnt+1);
    for (int i=1; i<=cnt; i++) {
        printf("%d\n",ans[i]);
    }

    return 0;
}
