//
//  9095.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 19..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/9095
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int fac(int value) {
//    if(value <= 1) {
//        return 1;
//    }
//    else {
//        return value * fac(value-1);
//    }
//}
//
//int calc(int value) {
//    int count = 0;
//    int x, y, z = 0;
//    for(x = 0 ; x <= value ; x++) {
//        for(y = 0 ; y <= value / 2 + 1 ; y++) {
//            for(z = 0 ; z <= value / 3 + 1 ; z++) {
//                if(x + 2 * y + 3 * z == value) {
//                    count = count + (fac(x + y +z) / fac(x) / fac(y) / fac(z));
//                }
//            }
//        }
//    }
//    return count;
//}

int d[11];

int main(void) {
    
//    int n = 0;
//    int result[99999];
//    
//    scanf("%d", &n);
//    
//    for(int i = 0 ; i < n ; i ++) {
//        scanf("%d", &result[i]);
//    }
//    
//    for(int i = 0 ; i < n ; i ++) {
//        printf("%d\n", calc(result[i]));
//    }

    
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    
    for(int i = 3 ; i <= 11 ; i++) {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    
    int t;
    int n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
    
    return 0;
}
