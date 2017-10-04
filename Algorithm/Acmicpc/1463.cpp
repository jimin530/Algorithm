//
//  1463.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 19..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/1463
//

#include <stdio.h>

int d[1000001] = {0, };

int calc(int value) {
    
    if(value == 1) {
        return 0;
    }
    if(d[value] > 0) {
        return d[value];
    }
    
    d[value] = calc(value - 1) + 1;
    
    if(value % 2 == 0) {
        int tmp = calc(value / 2) + 1;
        if(d[value] > tmp) {
            d[value] = tmp;
        }
    }
    
    if(value % 3 == 0) {
        int tmp = calc(value / 3) + 1;
        if(d[value] > tmp) {
            d[value] = tmp;
        }
    }
    
    return d[value];
}

int f_calc(int value) {
    
    d[1] = 0;
    
    for(int i = 2 ; i<=value ; i++) {
        d[i] = d[i-1] + 1;
        if(i % 2 == 0 && d[i] > d[i / 2] +1) {
            d[i] = d[i/2] + 1;
        }
        if(i % 3 == 0 && d[i] > d[i / 3] +1) {
            d[i] = d[i / 3] + 1;
        }
    }
    
    return d[value];
}

int main(void) {
    
    int value = 0;
    
    scanf("%d", &value);
    
    printf("%d", calc(value));
    // printf("%d", f_calc(value));
    
    return 0;
}
