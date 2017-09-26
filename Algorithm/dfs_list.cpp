//
//  dfs_list.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 26..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//

#include <cstdio>
#include <vector>

int check[100];
std::vector<std::vector<int>> a(100);
int n; // 정점의 수

void dfs(int x) {
    check[x] = true;
    printf("%d", x);
    
    for(int i = 0 ; i < a[x].size() ; i++) {
        // y는 정점
        int y = a[x][i];
        // 아직 방문을 안했으면
        if(check[y] == false) {
            dfs(y);
        }
    }
}

int main() {
    return 0;
}
