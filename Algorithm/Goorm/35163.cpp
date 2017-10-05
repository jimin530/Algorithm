//
//  35163.cpp
//  Algorithm
//
//  Created by Jimin Kim on 2017. 10. 6..
//  Copyright © 2017년 Jimin Kim. All rights reserved.
//
//  단어 빈도 추출 (1/2)
/*  https://edu.goorm.io/learn/exam/6245/%EC%99%84%EB%A3%8C-2%EC%B0%A8-2015%EB%85%84-%EA%B8%B0%EC%B6%9C-%EB%AC%B8%EC%A0%9C-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-9%EC%9B%94-19%EC%9D%BC/quiz/35163/%EB%8B%A8%EC%96%B4-%EB%B9%88%EB%8F%84-%EC%B6%94%EC%B6%9C-1-2
 */
//

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define LF "\n"

/** 이미 작성된 코드들은 사용하지 않아도 무관합니다.
 ** 필요하다면 수정/삭제하고 스스로 작성하세요.
 */


/** 입력으로 주어진 모든 줄들을 입력받아 벡터에 채워주는 반환해주는 함수 **/
void readAllLines(vector<string> &lines);


int main() {
    ios_base::sync_with_stdio(false);
    
    //모든 줄을 입력받아 준다
    vector<string> lines;
    readAllLines(lines);
    
    return 0;
}


void readAllLines(vector<string> &lines)
{
    lines.clear();
    std::string line;
    while (std::getline(std::cin, line))
    {
        lines.push_back(line);
        // cout << lines[0];
        
    }
}









