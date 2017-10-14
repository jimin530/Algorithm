//
//  line1.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 14..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int main() {
    vector<double> score;
    int n;
    scanf("%d", &n);
    
    int cnt = n;
    
    for(int i = 0 ; i < n ; i++) {
        int tmp;
        scanf("%d", &tmp);
        score.push_back(tmp);
    }
    
    while(true) {
        double sum = 0;
        for(int i = 0 ; i < score.size() ; i++) {
            sum += score[i];
        }
        if(sum / cnt >= 9.5) {
            break;
        }
        score.push_back(10);
        cnt++;
    }
    
    printf("%d\n", cnt - n);
    
    return 0;
}








