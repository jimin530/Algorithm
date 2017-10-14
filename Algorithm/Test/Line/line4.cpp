//
//  line4.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 14..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int check[1001];
std::vector<std::vector<int>> a(1001);
int total = 0;
bool is_cycle = false;

void dfs(int node) {
    check[node] = true;
    total++;
    
    for(int i = 0 ; i < a[node].size() ; i++) {
        int next = a[node][i];
        if(check[next]) {
            return;
        }
        dfs(next);
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    
    while(testcase--) {
        
        int n;
        scanf("%d", &n);
        
        int option;
        scanf("%d", &option);
        
        while(option--) {
            int from, to;
            scanf("%d %d", &from, &to);
            a[from].push_back(to);
        }

        for(int i = 0 ; i < n ; i++) {
            if(check[i] == false) {
                dfs(i);
                
                if(total == n) {
                    is_cycle = true;
                    break;
                } else {
                    total = 0;
                }
            }
        }
        if(is_cycle) {
            printf("O\n");
        } else {
            printf("X\n");
        }
        for(int i = 1 ; i <= n ; i++) {
            a[i].clear();
        }
        std::fill_n(check, 1001, false);
        is_cycle = false;
    }
    
    
    return 0;
}

