//
//  2011.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 28..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/2011
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    
    char secret[5001];
    int secretSize;
    int d[5010] = {};
    d[0] = 1;
    d[1] = 1;
    
    scanf("%s", secret);
    secretSize = (int)strlen(secret);
    
    for (int i = 2; i <= secretSize; i++)
    {
        int now = i - 1;
        if (secret[now] > '0')
            d[i] = d[i - 1] % 1000000;
        
        int x = (secret[now- 1]-'0') * 10 + secret[now]-'0';
        
        if (10 <= x && x <= 26)
            d[i] = (d[i] + d[i - 2]) % 1000000;
    }
    
    printf("%d\n", d[secretSize]);
    
    return 0;
    
}
