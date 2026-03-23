// AlchermyWorkshop.cpp

#include <iostream>
#include "AlchemyWorkshop.h"

// addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
void AlchemyWorkshop::addRecipe(const string& name, const vector<string>& ingredients) {
    recipes.push_back(PotionRecipe(name, ingredients)); // push_back 사용(새로운 레시피를 vector의 맨 뒤에 추가하기 위해 사용)
    cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << endl;
}

// 모든 레시피 출력 메서드
void AlchemyWorkshop::displayAllRecipes() const {
    if (recipes.empty()) {  // empty() 사용(vector가 비어있는지 확인하기 위해 사용)
        cout << "아직 등록된 레시피가 없습니다." << endl;
        return;
    }

    cout << "\n--- [ 전체 레시피 목록 ] ---" << endl;
    for (size_t i = 0; i < recipes.size(); ++i) {   // size() 사용(vector의 전체 크기만큼 반복하기 위해 사용)
        cout << "- 물약 이름: " << recipes[i].potionName << endl;
        cout << "  > 필요 재료: ";

        // 재료 vector 목록을 순회하며 출력
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
            cout << recipes[i].ingredients[j];  // 마지막 재료가 아니면 쉼표로 구분
            if (j < recipes[i].ingredients.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    cout << "---------------------------\n";


}

// 이름 검색 함수 구현(name: 물약 이름 → vector 순회 후 일치하는 객체 반환)
PotionRecipe AlchemyWorkshop::searchRecipeByName(const string& name) const
{
    for (size_t i = 0; i < recipes.size(); ++i)
    {
        if (recipes[i].potionName == name)  // 문자열 비교(같은 이름인지 확인)
        {
            return recipes[i];  // 찾으면 바로 반환
        }
    }
}

// 재료 검색 함수 구현(ingredient: 재료 이름 → 포함된 모든 레시피를 vector로 반환)
vector<PotionRecipe> AlchemyWorkshop::searchRecipeByIngredient(const string& ingredient) const
{
    vector<PotionRecipe> result; // 결과 저장용

    for (size_t i = 0; i < recipes.size(); ++i)
    {
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j)
        {
            if (recipes[i].ingredients[j] == ingredient)    // 재료 비교(입력한 재료와 같은지 확인)
            {
                result.push_back(recipes[i]);   // 조건 맞으면 추가
                break;  // 같은 레시피 중복 추가 방지
            }
        }
    }

    return result;
}