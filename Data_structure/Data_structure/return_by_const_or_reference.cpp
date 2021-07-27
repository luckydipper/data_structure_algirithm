// To use Korean, we need to use Unicode.
// In linux 
// 해당 객체를 return 할지 새로운 객체를 return 할 지.
// 잘 찾기.


// We user Literal like L"literal"

#include <iostream>
#include <string>


class Coordinate2D
{
    int x_;
    int y_;
public:
    Coordinate2D(int const x, int const y);
    int& access_x() { return x_; };
    int get_x() { return x_; };


    
    //
    void get_stat() const;

    // 굳이 이렇게 해서 private객체를 실제로 return할 필요 없음.
    //Coordinate2D& set_point(int x, int y);
    void set_point(int x, int y);
    
    // operand, operator
    Coordinate2D& operator+(const Coordinate2D& operand);
    // 두개를 더해서 새로운 객체를 만듬.
    /*const Coordinate2D operator+(const Coordinate2D& arg) const;*/
    /*const Coordinate2D operator++(int);*/
    Coordinate2D operator++(int);
};

void Coordinate2D::set_point(int x, int y)
{
    x_ = x;
    y_ = y;
}

void Coordinate2D::get_stat() const
{
    std::cout << x_ << ',' << y_ << std::endl;
}

Coordinate2D::Coordinate2D(int x, int y) : x_(x), y_(y) {};

//l value를 return함.
Coordinate2D& Coordinate2D::operator+(const Coordinate2D& operand)
{
    x_ = x_ + operand.x_;
    y_ = y_ + operand.y_;
    return *this;
}
 //reference를 return하는 경우 임시 객체가 return되는 것이 아니고, shallow copy되기 때문에
 //private에 있는 변수가 오염 될 수 있음.


// 오류나면 원래 있던 변수들이 더렵혀져서 이상해 질 수 있으므로,
// 임시 객체를 넘겨줌.임시 객체 복사해서 써!
//const Coordinate2D Coordinate2D::operator+(const Coordinate2D& arg) const
//{
//    auto added_x = x_ + arg.x_;
//    auto added_y = y_ + arg.y_;
//    Coordinate2D pt(added_x, added_y);
//    return pt;
//}


//const Coordinate2D Coordinate2D::operator++(int)
//{
//    Coordinate2D pt(++x_, ++y_);
//    return pt;
//}

Coordinate2D Coordinate2D::operator++(int)
{
    Coordinate2D pt(++x_, ++y_);
    return pt;
}


//w_main
int main(int arg, char* chars[])
{

    int x = 1, y = 2;
    Coordinate2D point_2d1(x, y);
    Coordinate2D point_2d2(10, 20);
    const Coordinate2D point_2d4(0, 1);
    //point_2d4++;
    //Coordinate2D& ptr = point_2d1++; // reference가 아닌데 reference로 받음. 함수의 return 값은 임시 값이므로 끝나면 사라져야 함.
    
    bool controller;
    std::cout << "True or False\n";
    std::cin >> controller;

    if (controller)
        point_2d1.set_point(8, 6);

    Coordinate2D point_2d3 = (point_2d1 + point_2d1).operator+(point_2d1);
    


    // append와 같이 받지 않아도 바뀜!
    // point_2d1 + point_2d2 + point_2d2;

    point_2d1.get_stat();
    point_2d1++;
    point_2d1.get_stat();
    point_2d1++;
    point_2d1.get_stat();
    &point_2d1++;

    
    //const를 제거하면 l-value이기 때문에 가능 것 아닌가?
    //point_2d1++ = point_2d2;
    (((point_2d1++)++)++)++;
    point_2d1++; //이걸 보면, 실제론 reference로 하는게 아닌가?

    std::cout <<&(point_2d1 + point_2d2); //= point_2d1; //reference를 return한 것이 아니기 때문에 대입이 안되야 정상 아님?
    //point_2d1 + point_2d1 = point_2d1;
    //point_2d3.get_stat();
    
    //(point_2d1 + point_2d1).get_stat();
    //point_2d1.get_stat();
    
    //std::wstring ws1 = L"hello 한국어";

    //std::wcout << ws1;
    //
    //std::wcin >> ws1;

    //std::wcout << ws1;
    //std::cout << "한국어asfd";
    point_2d1.access_x() = 3; //reference 이기에 가능 L value를 return함,
    // point_2d1.get_x() = 6;  r-value이기 때문에 불가능.
    int asdf = point_2d1.access_x();
}