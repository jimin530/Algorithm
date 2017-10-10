//
//  35245.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 10..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  모양 판별하기
/*  https://edu.goorm.io/learn/exam/6405/%EC%83%81%EC%8B%9C-%EC%9D%91%EC%8B%9C-2%EC%B0%A8-%EB%AA%A8%EC%9D%98-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8/quiz/35245/%EB%AA%A8%EC%96%91-%ED%8C%90%EB%B3%84%ED%95%98%EA%B8%B0#
 */
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int main() {
    string result;
    pair<int, int> p;
    pair<int, int> q;
    int px, py, qx, qy;
    scanf("%d %d", &px, &py);
    scanf("%d %d", &qx, &qy);
    
    if(px == qx && py == qy) {
        result = "DOT";
    }
    if( (px == qx && py != qy) || (px != qx && py == qy) ) {
        result = "SEGMENT";
    }
    if(px != qx && py != qy) {
        result = "RECTANGLE";
    }
    if( (px != qx && py != qy) && ((px -  qx) == (py - qy))  ) {
        result = "SQUARE";
    }
    
    cout << result;
    return 0;
}
