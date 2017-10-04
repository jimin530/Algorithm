//
//  11727.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 19..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/11727
//

#include <stdio.h>

int d[1001] = { 0 , };

int calc(int n) {
    
    d[0] = 1;
    d[1] = 1;
    
    for(int i = 2 ; i <= n ; i++) {
        d[i] = d[i-1] + 2 * d[i-2];
        d[i] %= 10007;
    }
    
    return d[n];
}

int main(void) {
    
    int n = 0;
    scanf("%d", &n);
    
    printf("%d", calc(n));
    
    return 0;
}
