//
//  34948.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 3..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  단어 찾아내기
/*  https://edu.goorm.io/learn/exam/6161/%EC%99%84%EB%A3%8C-1%EC%B0%A8-2016%EB%85%84-%EA%B8%B0%EC%B6%9C-%EB%AC%B8%EC%A0%9C-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-9%EC%9B%94-18%EC%9D%BC/quiz/34948/%EB%8B%A8%EC%96%B4-%EC%B0%BE%EC%95%84%EB%82%B4%EA%B8%B0
 */
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

char a[11][21];
int start = 0;
char mo[5] ={'a', 'e', 'i', 'o', 'u'};

int result_first = 0;
int result_second = 0;

bool isMo(char c) {
    for(int i = 0 ; i < 5 ; i++) {
        if(c == mo[i]) {
            return true;
        }
    }
    return false;
}

void getOne(char c[]) {
    int leng = (int)strlen(c);
    int conti_leng1 = 0;
    int conti_leng2 = 0;
    
    bool isFirst = false;
    bool isSecond = false;
    
    for(int i = 0 ; i < leng ; i++) {
        if(isMo(c[i])) {
            conti_leng1++;
            conti_leng2 = 0;
            if(conti_leng1 == 2 && !isFirst) {
                result_first++;
                isFirst = true;
            }
        } else {
            conti_leng2 ++;
            conti_leng1 = 0;
            if(conti_leng2 == 3 && !isSecond) {
                result_second++;
                isSecond = true;
            }
        }
    }
}

int main() {
    string s;
    getline(cin, s);
    vector<char> v(s.begin(), s.end());
    int second = 0;
    for(int i = 0 ; i < v.size() ; i++) {
        if(v[i] == ' ') {
            start++;
            second = 0;
            continue;
        } else {
            a[start][second] = v[i];
            second++;
        }
    }
    
    for(int i = 0 ; i <= start ; i++) {
        getOne(a[i]);
    }
    printf("%d\n%d", result_first, result_second);
    
    return 0;
}
