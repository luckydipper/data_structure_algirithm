#pragma once

//template<typename int_double>
class Point
{
private:
    int x_;
    double y_;

public:
    //constructor
    Point();
    Point(int x, int y);

    //copy constructor. default constructor is shallow copy
    Point(Point& point);

    //print corrdinate
    void get_point() const;

    void set_point(const int x, const int y);

    // const 이후에 set이 불러지지 않는다.
    // 맨 앞의 const는 이번연산이 마지막 변화임을 나타낸다.
    // const객체로 받으면 const member funcion으로만 바꿀 수 있기 때문에,
    // operator+ 이후에 해당줄에서 set_point같은 변화가 생길 때, 오류가 날 것이다.
    const Point operator+(const Point& _point) const;

    // 후진 대입 연산자는 마지막에 연산이 이뤄지기 때문에, 앞에만 const를 붙힌다.
    // 만약 뒤에도 const를 붙히면 ((pt++)++)++이 허용되기 때문이다.
    const Point operator++(int);

};