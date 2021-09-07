// exercise_28.h
// TODO : change Add Substract free memory.
// TODO : 임시로 static 처리 해둠. 임시 객채로 return 할 수 있도록,
// TODO : operator+와 같은 느낌으로 만들기
#pragma once
#include <iostream>

#ifndef _TESTTEMP_H_
#define _TESTTEMP_H_


// Client should use MakeEmpty method to initialize
// ex)
// SquareMatrix two_by_two;
// two_by_two.MakeEmpty(2)
template<typename T>
class SquareMatrix {
    // buffer size = x_y_lenth_ * x_y_lenth_ * sizeof(T)
    int x_y_lenth_;

    T** ptr_array;

public:
    explicit SquareMatrix() = default;
    // explicit SquareMatrix();

    // SquareMatrix(int lenth, int element) : x_y_lenth(lenth);
    ~SquareMatrix();

    // alike constructor, make n by n empty array
    // using dynamic allocation
    void MakeEmpty(const int n);

    // change index (i+1, j+1) to parameter value 
    void StoreValue(const int i, const int j, T const value);

    // !caution! operand lenth must be same with caller matrix lenth
    // !caution! this method return temporal object. save return value!
    // 내부를 건들이지 않는 임시 객체를 만들어서 return 함.
    // free 과정에서도 오류가 있음.
    // 생성자에서 malloc을 쓰는 것이 익숙한데 method에서 쓰니 힘듬.
    const SquareMatrix Add(const SquareMatrix& matrix) const;

    // !caution! operand lenth must be same with caller matrix lenth
    // !caution! this method return temporal object
    // 내부를 건들이지 않는 임시 객체를 만들어서 return 함.
    // free 과정에서도 오류가 있음. 
    // 생성자에서 malloc을 쓰는 것이 익숙한데 method에서 쓰니 힘듬.
    SquareMatrix Subtract(const SquareMatrix& matrix) const;

    // !caution! operand lenth must be same with caller matrix lenth
    void Copy(const SquareMatrix& matrix);

    // get index 
    auto operator[](const int index) const;
};
#endif



