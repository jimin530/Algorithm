//
//  bfs_list.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 26..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

int check[100];
std::vector<std::vector<int>> a(100);
int n; // 정점의 수

void bfs() {
    std::queue<int> q;
    check[1] = true;
    q.push(1);
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d", x);
        
        for(int i = 0 ; i < a[x].size() ; i++) {
            int y = a[x][i];
            
            if(check[y] == false) {
                check[y] = true;
                q.push(y);
            }
        }
    }
}

int main() {
    return 0;
}
