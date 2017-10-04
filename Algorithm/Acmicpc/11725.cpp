//
//  11725.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 2..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  트리의 부모 찾기
//  https://www.acmicpc.net/problem/11725
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> a(100111);
bool check[100111];
int depth[100111];
int dist[100111];
int parent[100111];

int main() {
    int n = 0;
    scanf("%d", &n);
    
    for(int i = 0 ; i < n-1 ; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    depth[1] = 0;
    check[1] = true;
    
    queue<int> q;
    q.push(1);
    parent[1] = -1;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        for(int i = 0 ; i < a[x].size() ; i++) {
            int y = a[x][i];
            if(check[y] == false) {
                depth[y] = depth[x] + 1;
                check[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }
    for(int i = 2 ; i <= n ; i++) {
        printf("%d\n", parent[i]);
    }
    
    return 0;
}
