// exercise_28.cpp

#include "exercise_28.h"

template<typename T>
SquareMatrix<T>::~SquareMatrix()
{
    for (int row_index = 0; row_index < x_y_lenth_; row_index++)
        delete ptr_array[row_index];
    delete [] ptr_array;
};

template<typename T>
void SquareMatrix<T>::MakeEmpty(const int n)
{   
    // (T*)[x_y_lenth_]type cast Ã³·³ ÇØ¼® µÊ.
    x_y_lenth_ = n;
    ptr_array = new T*[x_y_lenth_];

    // assign 0 each value
    for (int row_index = 0; row_index < x_y_lenth_; row_index++)
    {
        ptr_array[row_index] = new T[x_y_lenth_];
        for (int col_index = 0; col_index < x_y_lenth_; col_index++)
            ptr_array[row_index][col_index] = 0;
    }
}

template<typename T>
void SquareMatrix<T>::StoreValue(const int i, const int j, T const value)
{
    ptr_array[i][j] = value;
}

template<typename T>
const SquareMatrix<T> SquareMatrix<T>::Add(const SquareMatrix& matrix) const
{
    SquareMatrix<T> temp_array;
    //SquareMatrix<T>* prt_temp_array = new SquareMatrix<T>;
    //SquareMatrix<T> temp_array = *prt_temp_array;
    temp_array.MakeEmpty(x_y_lenth_);

    for (int row_index = 0; row_index < x_y_lenth_; row_index++)
        for (int col_index = 0; col_index < x_y_lenth_; col_index++)
            temp_array[row_index][col_index] = ptr_array[row_index][col_index] + matrix[row_index][col_index];

    return temp_array;
}


template<typename T>
SquareMatrix<T> SquareMatrix<T>::Subtract(const SquareMatrix& matrix) const
{
    SquareMatrix<T> temp_array;
    temp_array.MakeEmpty(x_y_lenth_);

    // substract each element
    for (int row_index = 0; row_index < x_y_lenth_; row_index++)
        for (int col_index = 0; col_index < x_y_lenth_; col_index++)
            temp_array[row_index][col_index] = ptr_array[row_index][col_index] - matrix[row_index][col_index];

    return temp_array;
}

template<typename T>
void SquareMatrix<T>::Copy(const SquareMatrix& matrix)
{
    (*this).MakeEmpty(matrix.x_y_lenth_);
    
    //copy each element
    for (int row_index = 0; row_index < x_y_lenth_; row_index++)
        for (int col_index = 0; col_index < x_y_lenth_; col_index++)
            ptr_array[row_index][col_index] = matrix.ptr_array[row_index][col_index];
}

template<typename T>
auto SquareMatrix<T>::operator[](const int index) const
{
    return ptr_array[index];
}

