// Main.cpp

#include <iostream>
#include "AlchemyWorkshop.h"

int main(void) {
    // AlchemyWorkshop 객체 생성(레시피 추가, 출력, 검색 기능을 사용하기 위해 객체 생성)
    AlchemyWorkshop myWorkshop;

    // while문 사용(종료를 선택하기 전까지 메뉴를 반복해서 사용하기 위함)
    while (true) {
        cout << "⚗️ 연금술 공방 관리 시스템" << endl;
        cout << "1. 레시피 추가" << endl;
        cout << "2. 모든 레시피 출력" << endl;
        cout << "3. 물약 이름 검색" << endl;
        cout << "4. 재료 검색" << endl;
        cout << "5. 종료" << endl;
        cout << "선택: ";

        int choice; // 메뉴 번호 저장 변수 정의
        cin >> choice;  // 메뉴 번호 입력받기

        if (cin.fail()) {
            cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            string name;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            // 여러 재료를 입력받기 위한 로직
            vector<string> ingredients_input;
            string ingredient;
            cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << endl;

            while (true) {
                cout << "재료 입력: ";
                getline(cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else {
                cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << endl;
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3) {
            string name;
            cout << "검색할 물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            PotionRecipe result = myWorkshop.searchRecipeByName(name);

            cout << "\n--- [ 물약 이름 검색 결과 ] ---" << endl;
            cout << "- 물약 이름: " << result.potionName << endl;
            cout << "  > 필요 재료: ";

            for (size_t i = 0; i < result.ingredients.size(); ++i) {
                cout << result.ingredients[i];
                if (i < result.ingredients.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
            cout << "-----------------------------" << endl;
        }
        else if (choice == 4) {
            string ingredient;
            cout << "검색할 재료 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, ingredient);

            vector<PotionRecipe> results = myWorkshop.searchRecipeByIngredient(ingredient);

            if (results.empty()) {
                cout << "해당 재료가 포함된 레시피가 없습니다.\n";
            }
            else {
                cout << "\n[검색 결과]\n";
                for (size_t i = 0; i < results.size(); ++i) {
                    cout << "- 물약 이름: " << results[i].potionName << endl;
                    cout << "  > 필요 재료: ";

                    for (size_t j = 0; j < results[i].ingredients.size(); ++j) {
                        cout << results[i].ingredients[j];
                        if (j < results[i].ingredients.size() - 1) {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                    cout << "-----------------------------" << endl;
                }
            }
        }
        else if (choice == 5) {
            cout << "공방 문을 닫습니다..." << endl;
            break;

        }
        else {
            cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}