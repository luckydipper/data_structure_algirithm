// exercise_28_test.cpp
// 
#include <iostream>
#include "exercise_28.h"
#include "exercise_28.cpp"
#include <cstdlib>

int main() {
    SquareMatrix<int> square1;
    SquareMatrix<int> square2;
    square1.MakeEmpty(8);
    square2.MakeEmpty(8);
    
    square1.StoreValue(0, 0, 9);
    square2.Copy(square1);

    SquareMatrix<int> square3;
    square3.MakeEmpty(8);

    // operator+ 처럼 구현하고 싶음!
    // 임시 객체로 만드는 방법을 공부 중.
    // 함수에서 local variable을 return 해도 const면 유지 될 줄 알았는데...
    // 객체를 return 과정에서 소멸자 두번 호출. Add와 subtract는 보완해야합니다!
    //square3 = square2.Add(square1); // 이 줄을 주석처리 하면 실행 됩니다!
}