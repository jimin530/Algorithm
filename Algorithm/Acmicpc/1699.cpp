//
//  1699.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 24..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/1699
//

#include <stdio.h>

int d[100001] = {0,};

int main(void) {
    
    int n = 0;
    scanf("%d", &n);
    
    for(int i = 1 ; i <= n ; i++) {
        d[i] = i;
        for(int j = 1 ; j * j <= i ; j++) {
            if(d[i] >= d[i - j*j] + 1) {
                d[i] = d[i- j*j] + 1;
            }
        }
    }
    
    printf("%d", d[n]);
    
    
    return 0;
}
