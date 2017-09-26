//
//  test.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 9. 25..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

std::vector<pair<int, int>> a[10];
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    
    for (int i=0; i<m; i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v, &w);
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }
    
    printf("%d", a[3][1].first);
    printf("%d", a[3][1].second);
}
