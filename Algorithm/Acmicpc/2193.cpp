//
//  2193.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 20..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/2193
//

#include <stdio.h>

long long d[91] ={0,};

int main(void) {
    
    int n = 0;
    
    scanf("%d", &n);
    
    d[1] = 1;
    d[2] = 1;
    
    for(int i = 3 ; i <= n ; i++) {
        d[i] = d[i-1] + d[i-2];
    }
    
    printf("%lld", d[n]);
    
    return 0;
}
