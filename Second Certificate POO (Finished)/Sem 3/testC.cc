#include <iostream>
#include <string>
#include <math.h>
using namespace std;


class Figure {
public:
    Figure() { cout << "F "; }
};

class Line : public virtual Figure {
private:
    double length;
public:
    Line(double length1) : length(length1) { cout << "L "; }
};

class Square : public virtual Figure {
private:
    double side;
public:
    Square(double side1) : side(side1) { cout << "S "; }
};

class Parallelepiped : public Square, public Line {
public:
    Parallelepiped(double baseSide, double height): 
        Line(height), Square(baseSide) { cout << "P "; }
};
int main(){
	
	
Parallelepiped p(1,2);
	
	return 0;
	
	}
