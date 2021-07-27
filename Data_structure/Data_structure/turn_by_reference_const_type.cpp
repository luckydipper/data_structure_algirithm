// 이 page에서는 cpp의 return 방식에 관하여 정리하고 실습함.

#include "turn_by_reference_const_type.hpp"
#include <iostream>

Point::Point() :x_(0), y_(0) { };


Point::Point(int x, int y) : x_(x), y_(y) { };

// 기본은 shallow copy만 지원하기 때문에, deepcopy는 따로 작성
Point::Point(Point& pt)
{
    std::cout << "Copy constructor called" << std::endl;
    //*this = new Point(pt.x_, pt.y_);
}


void Point::get_point() const
{
    std::cout <<"x: " << x_ <<", y: "<< y_ << std::endl;
}


//const는 부를 수 있어, const 제한이 빡세서
//const에서는 그냥 친구들 못불러.
void Point::set_point(const int x, const int y)
{
    std::cout << "Give me x value" << std::endl;
    x_ = x;
    std::cout << "Give me y value" << std::endl;
    y_ = y;
}

const Point Point::operator+(const Point& _point) const
{
    Point pt;
    pt.x_ = this->x_ + _point.x_;
    pt.y_ = this->y_ + _point.y_;

    // debug mode로 돌릴 시, 이 값을 복사해서 줌.
    // 그러므로 복사 생성자를 호출함.
    return pt;
}

const Point Point::operator++(int)
{
    Point pt(++x_, ++y_);
    return pt;
}



