#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


//class의 member variable만 underscore 사용.
typedef struct coordinate_2D {
	int x_;
	int y_;
} coordinate_2D;


void SetCoordinate(coordinate_2D* p_coodinate, int const set_x, int const set_y)
{
	p_coodinate->x_ = set_x;
	p_coodinate->y_ = set_y;
}

void PrintCoordinate(coordinate_2D* const p_coordinate)
{
	printf("x coordinate : %d \n", p_coordinate->x_);
	printf("y coordinate : %d \n", p_coordinate->y_);
}

bool IsSameCoordinate(coordinate_2D* const p1_coordinate, coordinate_2D* const p2_coordinate)
{
    if (p1_coordinate->x_ != p2_coordinate->x_)
        return false;

    if (p1_coordinate->y_ != p2_coordinate->y_)
        return false;

    return true;
}


int main()
{
    

    return 0;
}