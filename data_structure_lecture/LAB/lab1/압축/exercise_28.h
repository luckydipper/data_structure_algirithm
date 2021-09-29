// exercise_28.h
// TODO : Add Substract 메모리 해제 문제 해결
// TODO : operator+와 같은 느낌으로, 임시 객체를 return하도록 만들기
#pragma once
#include <iostream>

#ifndef _TESTTEMP_H_
#define _TESTTEMP_H_


// 객체를 만든 후, 반드시 MakeEmpty(생성자 대신)으로 초기화해야합니다.
template<typename T>
class SquareMatrix {
    int x_y_lenth_;
    T** ptr_array;

public:
    explicit SquareMatrix() = default;

    ~SquareMatrix();

    // alike constructor, make n by n empty array
    // using dynamic allocation.
    void MakeEmpty(const int n);

    // change index (i+1, j+1) to parameter value.
    void StoreValue(const int i, const int j, T const value);

    // !caution! operand lenth must be same with caller matrix lenth
    // !caution! this method return temporal object. save return value!
    // !caution! free 과정에 오류가 있음.
    // operator+과 똑같게 구현하고 싶음.
    const SquareMatrix Add(const SquareMatrix& matrix) const;

    // !caution! operand lenth must be same with caller matrix lenth
    // !caution! this method return temporal object. save return value!
    // !caution! free 과정에 오류가 있음.
    // operator-과 똑같게 구현하고 싶음.
    const SquareMatrix Subtract(const SquareMatrix& matrix) const;

    // !caution! operand length must be same with caller matrix lenth
    void Copy(const SquareMatrix& matrix);

    // Get index value. 
    // 2차원 배열이라 pointer type이 올 수도, T type이 올 수도 있어서, auto 반환.
    auto operator[](const int index) const;
};
#endif



