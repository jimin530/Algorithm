//
//  11053.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 8. 23..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  문제
//  https://www.acmicpc.net/problem/11054
//

#include <stdio.h>

int a[1001];
int d[1001];
int d2[1001];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1; i<=n; i++) {
        d[i] = 1;
        for (int j=1; j<i; j++) {
            if (a[j] < a[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
            }
        }
    }
    for (int i=n; i>=1; i--) {
        d2[i] = 1;
        for (int j=i+1; j<=n; j++) {
            if (a[i] > a[j] && d2[j]+1 > d2[i]) {
                d2[i] = d2[j]+1;
            }
        }
    }
    int max = 0;
    for (int i=1; i<=n; i++) {
        if (max < d[i]+d2[i]-1) {
            max = d[i]+d2[i]-1;
        }
    }
    
    printf("%d\n", max);
    return 0;
}
