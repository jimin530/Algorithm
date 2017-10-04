//
//  bfs_arr.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 26..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//

#include <cstdio>
#include <queue>

int check[100];
int a[100][100];
int n; // 정점의 수

void bfs() {
    std::queue<int> q;
    check[1] = true; // 시작
    q.push(1); // 시작
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d", x);
        
        for(int i = 1 ; i <= n ; i++) {
            // 간선이 있고 && 방문을 아직 안했으면
            if(a[x][i] == 1 && check[i] == false) {
                check[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    return 0;
}
