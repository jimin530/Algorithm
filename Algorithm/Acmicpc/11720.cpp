//
//  11720.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 7. 31..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  숫자의 합
//  https://www.acmicpc.net/problem/11720
//

#include <stdio.h>

int main(void) {
    
    int count = 0;
    int value = 0;
    int sum = 0;
    
    scanf("%d", &count);
    
    while(count--) {
        scanf("%1d", &value);
        sum += value;
        value = 0;
    }
    
    printf("%d", sum);
    
    return 0;
}
