//
//  11053.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 23..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/11055
//

#include <stdio.h>

int d[1001] = {0,};
int a[1001] = {0,};

int main(void) {
    
    int n = 0;
    int max = 0;
    scanf("%d", &n);
    
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        d[i] = a[i];
        if(i==1) {
            max = a[1];
        }
        for(int j = 1 ; j < i ; j++) {
            if(a[j] < a[i] && d[j] + a[i] > d[i]) {
                d[i] = d[j] + a[i];
                if(d[i]>=max) {
                    max = d[i];
                }
            }
        }
    }
    
    printf("%d", max);
    
    return 0;
}
