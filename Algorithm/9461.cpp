//
//  9461.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 28..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/9461
//

#include <stdio.h>

long long d[101] = { 1, 1, 1, 1, 2, 2, };

int main(void) {
    
    int num = 0;
    
    scanf("%d",&num);
    
    for (int i = 6; i <= 100; i++) {
        d[i] = d[i - 1] + d[i - 5];
    }
    
    while (num--){
        int n = 0;
        scanf("%d", &n);
        printf("%lld\n", d[n]);
    }
    
    return 0;
}
