//
//  10870.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 4..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  피보나치 수 5
//  https://www.acmicpc.net/problem/11870
//

#include <stdio.h>

int calc(int value) {
    if(value == 0) {
        return 0;
    }
    else if(value == 1) {
        return 1;
    }
    else {
        return calc(value-1) + calc(value-2);
    }
}

int main(void) {
    int value = 0;
    
    scanf("%d", &value);
    
    printf("%d\n", calc(value));
    
    return 0;
}
