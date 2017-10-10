//
//  33678.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 10..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  영역 교차 검사하기
/*  https://edu.goorm.io/learn/exam/6404/%EC%83%81%EC%8B%9C-%EC%9D%91%EC%8B%9C-1%EC%B0%A8-%EB%AA%A8%EC%9D%98-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8/quiz/33663/%EA%B2%BD%EB%A1%9C-%EC%B6%94%EC%A0%95%ED%95%98%EA%B8%B0
 */
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
int px, py, qx, qy, rx, ry, sx, sy;
bool check[20001][20001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main() {
    
    scanf("%d %d", &px, &py);
    scanf("%d %d", &qx, &qy);
    scanf("%d %d", &rx, &ry);
    scanf("%d %d", &sx, &sy);
    px+=10000;
    py+=10000;
    qx+=10000;
    qy+=10000;
    rx+=10000;
    ry+=10000;
    sx+=10000;
    sy+=10000;
    
    queue< pair<int, int> > q;
    int startx = min(px, qx);
    int starty = min(py, qy);
    check[startx][starty] = true;
    q.push(make_pair(startx, starty));
    
    int result = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int k = 0 ; k < 4 ; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(min(px, qx) <= nx && nx < max(px, qx) && min(py, qy) <= ny && ny < max(py, qy)
               && check[nx][ny] == false) {
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
                
                if(min(rx, sx) <= nx && nx < max(rx, sx) && min(ry, sy) <= ny && ny < max(ry, sy)) {
                    result++;
                }
                
            }
        }
    }
    printf("%d", result);
    
    return 0;
}
