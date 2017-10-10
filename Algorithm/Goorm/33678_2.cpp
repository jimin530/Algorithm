//
//  33678_2.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 10..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  영역 교차 검사하기
/*  https://edu.goorm.io/learn/exam/6404/%EC%83%81%EC%8B%9C-%EC%9D%91%EC%8B%9C-1%EC%B0%A8-%EB%AA%A8%EC%9D%98-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8/quiz/33678/%EC%98%81%EC%97%AD-%EA%B5%90%EC%B0%A8-%EA%B2%80%EC%82%AC%ED%95%98%EA%B8%B0
 */
//
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int px, py, qx, qy, rx, ry, sx, sy;
    scanf("%d %d", &px, &py);
    scanf("%d %d", &qx, &qy);
    scanf("%d %d", &rx, &ry);
    scanf("%d %d", &sx, &sy);
    
    vector<int> vx;
    vector<int> vy;
    vx.push_back(px);
    vx.push_back(qx);
    vx.push_back(rx);
    vx.push_back(sx);
    vy.push_back(py);
    vy.push_back(qy);
    vy.push_back(ry);
    vy.push_back(sy);
    
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    
    // 겹치면 x, y좌표를 정렬했을 때 2번 째, 3번 째 줄이 겹친다.
    
    if( min(px, qx) <= vx[1] && vx[1] <= max(px, qx) && min(rx, sx) <= vx[1] && vx[1] <= max(rx, sx) &&
       min(px, qx) <= vx[2] && vx[2] <= max(px, qx) && min(rx, sx) <= vx[2] && vx[2] <= max(rx, sx) &&
       min(py, qy) <= vy[1] && vy[1] <= max(py, qy) && min(ry, sy) <= vy[1] && vy[1] <= max(ry, sy) &&
       min(py, qy) <= vy[2] && vy[2] <= max(py, qy) && min(ry, sy) <= vy[2] && vy[2] <= max(ry, sy) ) {
        int width = max(vx[1], vx[2]) - min(vx[1], vx[2]);
        int height = max(vy[1], vy[2]) - min(vy[1], vy[2]);
        
        printf("%d", width * height);
    }
    else {
        printf("%d", 0);
    }
    
    
    return 0;
}
