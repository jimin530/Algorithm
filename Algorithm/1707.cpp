//
//  11724.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 26..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  이분 그래프
//  https://www.acmicpc.net/problem/1707
//
// 이해못함

#include <cstdio>
#include <vector>

int check[20001];
std::vector<std::vector<int>> a(20001);

bool dfs(int node, int c) {
    check[node] = c;
    
    for(int i = 0 ; i < a[node].size() ; i++) {
        int next = a[node][i];
        if(check[next] == 0) {
            if(dfs(next, 3-c) == false) {
                return false;
            }
        } else if (check[next] == check[node]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int testcase = 0;
    scanf("%d", &testcase);
    
    while(testcase--) {
        int n, m = 0; // 정점의수, 간선의 수
        scanf("%d %d", &n, &m);
        
        for (int i=1; i<=n; i++) {
            a[i].clear();
            check[i] = 0;
        }
        
        while(m--) {
            int u, v = 0;
            scanf("%d %d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        bool isEven = true;
        for(int i = 1 ; i <= n ; i++) {
            if(check[i] == 0) {
                if(dfs(i,1) == false) {
                    isEven = false;
                }
            }
        }
        printf("%s", isEven ? "YES" : "NO");
    }
    
    return 0;
}

