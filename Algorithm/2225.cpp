//
//  2225.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 28..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/2225
//

#include <stdio.h>

long long d[201][201] = {0,};

int main(void) {
    int n, k = 0;
    
    scanf("%d %d", &n, &k);
    
    d[0][0] = 1;
    
    for(int i = 1 ; i <= k ; i++) {
        for(int j = 0 ; j <= n ; j++) {
            for(int l = 0 ; l <= j ; l++) {
                d[i][j] = d[i][j] + d[i-1][j-l];
                d[i][j] %= 1000000000;
            }
        }
    }
    
    printf("%lld", d[k][n]);
    
    return 0;
}
