//
//  11724.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 26..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  연결 요소의 개수
//  https://www.acmicpc.net/problem/11724
//

#include <cstdio>
#include <vector>
#include <queue>

int check[1001];
std::vector<std::vector<int>> a(1001);

void dfs(int node) {
    check[node] = true;
    
    for(int i = 0 ; i < a[node].size() ; i++) {
        int next = a[node][i];
        if(check[next] == false) {
            dfs(next);
        }
    }
}

void bfs(int node) {
    std::queue<int> q;
    check[node] = true;
    q.push(node);
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        for(int i = 0 ; i < a[x].size() ; i++) {
            int y = a[x][i];
            
            if(check[y] == false) {
                check[y] = true;
                q.push(y);
            }
        }
    }
}

int main(void) {
    int n; // 정점의 수
    int m; // 간선의 수
    int count = 0;
    scanf("%d %d", &n, &m);
    
    while(m--) {
        int u;
        int v;
        scanf("%d %d", &u, &v);
        
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for(int i = 1; i <= n ; i++) {
        if(check[i] == false) {
            // dfs(i);
            bfs(i);
            count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
