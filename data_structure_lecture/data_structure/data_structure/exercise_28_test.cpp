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
    square2.StoreValue(0, 0, 9);
    SquareMatrix<int> square4;
    square4.Copy(square2);

    // 임시 객체로 만드는 방법을 연구하는 중.
    // 함수에서 local variable을 return 해도 const면 유지 될 줄 알았는데 ,
    // free가 안 됨...
    // SquareMatrix<int> square3 = square1.Add(square2);
}