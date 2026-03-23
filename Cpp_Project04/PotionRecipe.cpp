// PotionRecipe.cpp

#include "PotionRecipe.h"

// 생성자 구현(name: 물약 이름, ingredients: 재료 목록 > 멤버 변수 초기화)
PotionRecipe::PotionRecipe(const string& name, const vector<string>& ingredients)
    : potionName(name), ingredients(ingredients) {

}