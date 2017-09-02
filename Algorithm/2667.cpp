//
//  2667.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 2..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/2667
//

#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int a[26][26] = {0, };
int d[26][26] = {0, };

int group[25*25] = {0, };

int n = 0;

void bfs(int x, int y, int cnt) {
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(x, y));
    d[x][y] = cnt;
    
    for(int k = 0 ; k < 4 ; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if(a[nx][ny] == 1 && d[nx][ny] == 0) {
                q.push(std::make_pair(nx, ny));
                bfs(nx, ny, cnt);
            }
        }
    }
}

int main(void) {
    
    scanf("%d", &n);
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    
    int cnt = 0;
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(a[i][j] == 1 && d[i][j] == 0) {
                bfs(i, j, ++cnt);
            }
        }
    }
    
    printf("%d\n", cnt);
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            group[d[i][j]]++;
        }
    }
    
    sort(group + 1, group + cnt +1);
    
    for(int i = 1 ; i <= cnt ; i++) {
        printf("%d\n", group[i]);
    }
    
    return 0;
}
