//
//  9466.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 27..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  텀 프로젝트
//  https://www.acmicpc.net/problem/9466
//  못풀음
//

#include <cstdio>
#include <vector>

bool check[100001];
//bool is_term[100001] = {false, };
std::vector<std::vector<int>> a(100001);
int start_node = 0;
int count = 0;

void dfs(int node) {
    check[node] = true;

    for(int i = 0 ; i < a[node].size() ; i++) {
        int next = a[node][i];
        if(check[next] && next == start_node) {
            count++;
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
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++) {
            int u;
            scanf("%d", &u);
            a[i].push_back(u);
        }
        
        for(int i = 1; i <= n ; i++) {
            std::fill_n(check, 100001, false);
//            if(check[i] == false && is_term[i] == true) {
            if(check[i] == false) {
                start_node = i;
                dfs(i);
            }
        }
        printf("%d\n", count);
        
        for(int i = 1 ; i <= n ; i++) {
            a[i].clear();
        }
        std::fill_n(check, 100001, false);
    }
    
    return 0;
}


