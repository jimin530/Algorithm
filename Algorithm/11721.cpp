//
//  11721.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 7. 31..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  열 개씩 끊어 출력하기
//  https://www.acmicpc.net/problem/11721
//

#include <stdio.h>

int main(void) {
    
    char value[11];
    
    while(scanf("%10s", value) != EOF)
        printf("%s\n", value);
    
    return 0;
}
