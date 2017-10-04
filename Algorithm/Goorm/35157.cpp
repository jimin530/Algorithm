//
//  35157.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 4..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  길 확인하기
/*  https://edu.goorm.io/learn/exam/6245/%EC%99%84%EB%A3%8C-2%EC%B0%A8-2015%EB%85%84-%EA%B8%B0%EC%B6%9C-%EB%AC%B8%EC%A0%9C-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-9%EC%9B%94-19%EC%9D%BC/quiz/35157/%EA%B8%B8-%ED%99%95%EC%9D%B8%ED%95%98%EA%B8%B0#
 */
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int map[9][9];
int check[9][9];

bool isOk(int a, int b) {
    if(a == 1 && b == 2)
        return false;
    if(a == 2 && b == 1)
        return false;
    if(a == 1 && b == 3)
        return false;
    if(a == 2 && b == 4)
        return false;
    if(a == 3 && b == 2)
        return false;
    if(a == 4 && b == 1)
        return false;
    if(a == 3 && b == 3)
        return false;
    if(a == 4 && b == 4)
        return false;
    
    return true;
}

bool bfs() {
    std::queue<pair<int, int>> q;
    check[0][0] = true;
    q.push(make_pair(0, 0));
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int value = map[x][y];
        q.pop();
        
        if(value == 1) {
            int nx = x;
            int ny = y + 1;
            if(isOk(map[x][y], map[nx][ny]) && 0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                check[nx][ny] = true;
                if(nx == 7 && ny == 7 && (map[nx][ny] == 1 || map[nx][ny] == 4) ) {
                    return true;
                }
                q.push(make_pair(nx, ny));
            }
        } else if(value == 2) {
            int nx = x + 1;
            int ny = y;
            if(isOk(map[x][y], map[nx][ny]) && 0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                check[nx][ny] = true;
                if(nx == 7 && ny == 7 && (map[nx][ny] == 2 || map[nx][ny] == 3) ) {
                    return true;
                }
                q.push(make_pair(nx, ny));
            }
        } else if(value == 3) {
            int nx = x;
            int ny = y + 1;
            if(isOk(map[x][y], map[nx][ny]) && 0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                check[nx][ny] = true;
                if(nx == 7 && ny == 7 && (map[nx][ny] == 1 || map[nx][ny] == 4) ) {
                    return true;
                }
                q.push(make_pair(nx, ny));
            }
        } else if(value == 4) {
            int nx = x + 1;
            int ny = y;
            if(isOk(map[x][y], map[nx][ny]) && 0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                check[nx][ny] = true;
                if(nx == 7 && ny == 7 && (map[nx][ny] == 2 || map[nx][ny] == 3) ) {
                    return true;
                }
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    
    while(n--) {
        
        for(int i = 0 ; i < 8 ; i++) {
            for(int j = 0 ; j < 8 ; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        if(bfs()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
        for(int i=0; i<9; i++){
            memset(check[i], 0, sizeof(int)*9); //모든 값 0으로 초기화
        }
        
    }
    
    return 0;
}
