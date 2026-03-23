// AlchemyWorkshop.h

#pragma once

#include "PotionRecipe.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
    vector<PotionRecipe> recipes;   // 레시피 목록 정의

public:
    // 매개변수 정의
    void addRecipe(const string& name, const vector<string>& ingredients);  // 레시피 추가 함수 정의(name: 물약 이름, ingredients: 재료 목록 > 레시피 생성 후 목록에 추가)
    void displayAllRecipes() const; // 전체 레시피 출력 함수 정의(저장된 모든 레시피 정보 출력)
    PotionRecipe searchRecipeByName(const string& name) const; // 물약 이름 검색 함수 정의(name: 물약 이름 > 동일한 이름의 레시피 반환)
    vector<PotionRecipe> searchRecipeByIngredient(const string& ingredient) const; // 재료 검색 함수 정의(ingredient: 재료 이름 > 해당 재료가 포함된 모든 레시피 반환)
};