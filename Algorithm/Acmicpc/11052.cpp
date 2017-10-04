//
//  11052.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 20..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/11052
//

#include <stdio.h>
#include <math.h>

int a[1001];
int d[1001] = {0 ,};

int main(void) {
    
    int n = 0;
    
    scanf("%d", &n);
    
    for(int i = 1 ; i <= n ; i ++) {
        scanf("%d", &a[i]);
    }
    
    d[0] = 0;
    
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1; j <= i ; j++) {
            d[i] = (int) fmax(d[i], d[i-j] + a[j]);
        }
    }
    
    printf("%d", d[n]);
    
    return 0;
}
