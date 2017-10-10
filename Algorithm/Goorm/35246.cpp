//
//  35246.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 10..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  쿼드 코어
/*  https://edu.goorm.io/learn/exam/6404/%EC%83%81%EC%8B%9C-%EC%9D%91%EC%8B%9C-1%EC%B0%A8-%EB%AA%A8%EC%9D%98-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8/quiz/33676/%ED%99%94%ED%95%99-%EB%B0%98%EC%9D%91
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
    vector<int> v;
    for(int i = 0 ; i < 5 ; i++) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    if(v[3] + v[4] > v[0]) {
        printf("%d\n", v[0] + v[4] - (v[0] - v[3]));
    } else {
        printf("%d\n", v[0]);
    }
    
    return 0;
}
