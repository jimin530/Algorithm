//
//  dfs_arr.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 26..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//

#include <cstdio>

int check[100];
int a[100][100];
int n; // 정점의 수

void dfs(int x) {
    check[x] = true;
    printf("%d", x);
    
    for(int i = 1 ; i <= n ; i++) {
        // 간선이 있고 && 방문을 아직 안했으면
        if(a[x][i] == 1 && check[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    return 0;
}
