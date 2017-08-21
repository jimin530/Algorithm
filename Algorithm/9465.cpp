//
//  9465.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 22..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/9465
//

#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

long long int score[3][1000001] = {0, };
long long int d[1000001][3] = {0, };

//x       o       x
//x       x       o
//= 0     = 1     = 2
int main(void) {
    
    int c = 0;
    scanf("%d", &c);
    
    while(c--) {
        int n = 0;
        scanf(" %d", &n);
        for(int i = 1 ; i <= 2 ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                scanf("%lld", &score[i][j]);
            }
        }
        
        d[0][0] = d[0][1] = d[0][2] = 0;
        
        for(int i = 1 ; i <= n ; i++) {
            d[i][0] = max(d[i-1][0], max((long long int)d[i-1][1], d[i-1][2]));
            d[i][1] = max(d[i-1][0], d[i-1][2]) + score[1][i];
            d[i][2] = max(d[i-1][0], d[i-1][1]) + score[2][i];
        }
        
        long long int result = 0;
        for(int i = 1 ; i <= n ; i++) {
            result = max(max(result, d[i][0]), max(d[i][1], d[i][2]));
        }
        printf("%lld\n", result);
        
    }
    
    return 0;
}
