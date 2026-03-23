// PotionRecipe.h

#pragma once

#include <vector>
#include <string>

using namespace std;

// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe {
public:
    string potionName;          // 물약 이름 정의
    vector<string> ingredients; // 재료 목록 정의(여러개 저장하기위해 vector 사용)

    PotionRecipe(const string& name, const vector<string>& ingredients);    // 생성자 정의(name: 물약 이름, ingredients: 재료 목록 > 멤버 변수 초기화)
};