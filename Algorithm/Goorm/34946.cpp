//
//  34946.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 3..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  펠린드롬 넘버 만들기
/*  https://edu.goorm.io/learn/exam/6161/%EC%99%84%EB%A3%8C-1%EC%B0%A8-2016%EB%85%84-%EA%B8%B0%EC%B6%9C-%EB%AC%B8%EC%A0%9C-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-9%EC%9B%94-18%EC%9D%BC/quiz/34946/%ED%8E%A0%EB%A6%B0%EB%93%9C%EB%A1%AC-%EB%84%98%EB%B2%84-%EB%A7%8C%EB%93%A4%EA%B8%B0
 */
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

int rev(int x) {
    string tmp = to_string(x);
    vector<char> data(tmp.begin(), tmp.end());
    reverse(data.begin(), data.end());
    char* a = &data[0];
    string re_tmp = a;
    return stoi(re_tmp);
}

bool is_f(int x) {
    string tmp = to_string(x);
    int leng = (int)tmp.length();
    vector<char> data(tmp.begin(), tmp.end());
    int start = 0;
    int end = leng - 1;
    int count = 0;
    while(true) {
        if(start >= end) {
            break;
        }
        else {
            if(data[start] == data[end]) {
                count++;
            }
            start++;
            end--;
        }
    }
    if(count == (leng/2)) {
        return true;
    } else {
        return false;
    }
}

int calc_count = 0;
void calc() {
    if(calc_count > 3 || n >= 10000) {
        printf("%d", -1);
        return;
    }
    if(is_f(n)) {
        printf("%d", n);
        return;
    }
    n = n + rev(n);
    calc_count++;
    calc();
}

int main() {
    scanf("%d", &n);
    
    calc();
    
    return 0;
}
