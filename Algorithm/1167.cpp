//
//  1167.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 2..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  트리의 지름
//  https://www.acmicpc.net/problem/1167
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};

vector<vector<pair<int, int>>> a(10001);
int dis[10001];
bool check[10001];

void bfs(int start) {
    memset(dis, 0, sizeof(dis));
    memset(check, 0, sizeof(check));
    queue<int> q;
    check[start] = true;
    q.push(start);
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0 ; i < a[x].size() ; i++) {
            int to = a[x][i].first;
            int cost = a[x][i].second;
            if(check[to] == false) {
                dis[to] = dis[x] + cost;
                q.push(to);
                check[to] = true;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    for(int i = 0 ; i < n ; i++) {
        int node;
        scanf("%d", &node);
        while(true) {
            int u;
            scanf("%d", &u);
            if(u == -1)
                break;
            
            int dis;
            scanf("%d", &dis);
            a[node].push_back(make_pair(u, dis));
        }
    }
    
    bfs(1);
    int start = 1;
    for (int i=2; i<=n; i++) {
        if (dis[i] > dis[start]) {
            start = i;
        }
    }
    bfs(start);
    int ans = dis[1];
    for (int i=2; i<=n; i++) {
        if (ans < dis[i]) {
            ans = dis[i];
        }
    }
    printf("%d\n",ans);
    
    return 0;
}
