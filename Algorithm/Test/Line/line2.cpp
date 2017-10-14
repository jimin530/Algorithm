//
//  line2.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 14..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    long long  cnt = 0;
    long long int tmp = 0;
    for(long long int i = 1 ; i*i <= n ; i++) {
        if(i*i == n) {
            tmp = 1;
            break;
        }
        if(n % i == 0) {
            cnt++;
        }
    }
    cnt = cnt*2;
    printf("%lld\n", cnt + tmp);
    return 0;
}
