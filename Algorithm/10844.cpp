//
//  10844.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 21..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/10844
//

#include <stdio.h>

int d[101][11] = {0,};

int main(void) {
    
    int n = 0;
    
    scanf("%d", &n);
    
    for(int i = 1 ; i <= 9 ; i++) {
        d[1][i] = 1;
    }
    for(int i = 2 ; i <= n ; i++) {
        for(int j = 0 ; j <= 9 ; j++) {
            d[i][j] = 0;
            if(j-1 >= 0) {
                d[i][j] = d[i][j] + d[i-1][j-1];
            }
            if(j+1 <= 9) {
                d[i][j] = d[i][j] + d[i-1][j+1];
            }
            d[i][j] %= 1000000000;
        }
    }
    
    long long int count = 0;
    
    for(int i = 0 ; i <= 9 ; i++) {
        count += d[n][i];
    }
    count %= 1000000000;
    
    printf("%lld", count);
    
    return 0;
}
