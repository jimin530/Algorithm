//
//  2156.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 22..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/2156
//

#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

long long d[10001] = {0,};
long long a[10001] = {0,};

int main(void) {
    
    int n = 0;
    
    scanf("%d", &n);
    
    for(int i = 1 ; i <= n ; i++) {
        scanf("%lld", &a[i]);
    }
    
    d[1] = a[1];
    d[2] = a[1] + a[2];
    
    for (int i = 3; i <= n; i++){
        // 0번째
        d[i] = d[i-1];
        // 1번째
        if (d[i] < d[i-2] + a[i]) {
            d[i] = d[i-2] + a[i];
        }
        // 2번째
        if (d[i] < d[i-3] + a[i] + a[i-1]) {
            d[i] = d[i-3] + a[i] + a[i-1];
        }
    }
    
    printf("%lld\n", d[n]);
    
    return 0;
}

