//
//  10451.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 27..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  순열 사이클
//  https://www.acmicpc.net/problem/10451
//

#include <cstdio>
#include <vector>

int check[1001];
std::vector<std::vector<int>> a(1001);

void dfs(int node) {
    check[node] = true;
    
    for(int i = 0 ; i < a[node].size() ; i++) {
        int next = a[node][i];
        if(check[next]) {
            return;
        }
        dfs(next);
    }
}

int main(void) {
    int testcase = 0;
    scanf("%d", &testcase);
    
    while (testcase--) {
        int n = 0;
        int cycleCount = 0;
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++) {
            int u;
            scanf("%d", &u);
            a[i].push_back(u);
        }
        
        for(int i = 1; i <= n ; i++) {
            if(check[i] == false) {
                dfs(i);
                cycleCount++;
            }
        }
        printf("%d\n", cycleCount);

        for(int i = 1 ; i <= n ; i++) {
            a[i].clear();
        }
        std::fill_n(check, 1001, false);
    }
    
    return 0;
}


