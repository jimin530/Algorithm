//
//  1912.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 24..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/1912
//

#include <stdio.h>

int d[1000001] = { 0 , };
int a[1000001] = { 0 , };

int main(void) {

    int n = 0;
    scanf("%d", &n);
    
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        d[i] = a[i];
        
        if(d[i-1] + a[i] > d[i]) {
            d[i] = d[i-1] + a[i];
        }
    }
    
    int max = d[1];
    
    for(int i = 2 ; i <= n ; i++) {
        if(d[i] >= max) {
            max = d[i];
        }
    }
    
    printf("%d", max);
    
    return 0;
}
