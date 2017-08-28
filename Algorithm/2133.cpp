//
//  2133.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 28..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/2133
//

#include <stdio.h>

int d[31] = {0, };

int main(void) {
    
    int n = 0;
    scanf("%d", &n);
    
    d[0] = 1;
    d[2] = 3;
    
    for(int i = 4 ; i <= n ; i += 2) {
        d[i] = 3 * d[i-2];
        for (int j = 4; j <= i; j += 2) {
            d[i] = d[i] + 2 * d[i - j];
        }
    }
    
    printf("%d", d[n]);
    
    return 0;
}
