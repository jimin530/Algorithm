//
//  33676.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 10..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  화학 반응
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
    int num;
    scanf("%d", &num);
    
    int case_num = 1;
    while(num--) {
        // 종류의 수, 필요한 합성 물질의 양
        int n, g;
        scanf("%d %d", &n, &g);
        // 각각 필요한 기본 물질의 양(벡터)
        vector<int> v;
        for(int i = 0 ; i < n ; i++) {
            int tmp;
            scanf("%d", &tmp);
            v.push_back(tmp);
        }
        
        int req_g = 0;
        while(true) {
            sort(v.begin(), v.end());
            if(req_g == g)
                break;
            v[0]++;
            v[1]++;
            v[2]++;
            req_g++;
        }
        int max = v[n-1];
        
        printf("Case #%d\n", case_num++);
        if(max % 50 == 0) {
            printf("%d\n", max/50);
        } else {
            printf("%d\n", max/50 + 1);
        }
    }
    
    return 0;
}




















