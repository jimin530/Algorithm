//
//  2579.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 24..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/2579
//

#include <stdio.h>

int d[301] = {0, };
int a[301] = {0, };

int main(void) {
    
    int n = 0;
    scanf("%d", &n);
    
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    
    d[1] = a[1];
    d[2] = d[1] + a[2];
    
    for(int i = 3 ; i <= n ; i++) {
        d[i] = d[i-3] + a[i-1] + a[i];
        if(d[i] < d[i-2] + a[i]) {
            d[i] = d[i-2] + a[i];
        }
    }
    
    printf("%d", d[n]);
    
    return 0;
}
