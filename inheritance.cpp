#include <iostream>
#include <string>
using namespace std;

//-----------------------
// BASE CLASS (Parent)
//-----------------------
class Shape {
    protected:
      //'protected' is like private, but derived classes can acces it.
      string color;

    public:
      //Constructor for the base class
      Shape(string c) {
        color = c;
        cout << "Shape constructor called." << endl;
      }

    //A method that all shapes share
    void displayColor() {
        cout << "this shape's color is: " << color << endl;
    }
};

//-------------------------
//DERIVED CLASS (Child)
//The syntax ':public Shape' means "Circle inherits frome shape"
//-------------------------
class Circle : public Shape {
    private:
       double radius;

    public:
       //Constructor: Must call the base class constructor
       Circle(string c, double r) : Shape(c) {
        radius = r;
        cout << "Circle constructor called." << endl;
       }

    void displayCircleInfo() {
        //We can use 'color' here because it is protected in the base class!
        cout << "Thus circle is " << color << " and has a radius of "<< radius << endl;
    }
};

//Another derived class
class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(string c, double w, double h) : Shape(c) {
    width = w;
    height = h;
    cout << "Rectangle constructor called." << endl;
    }

void displayRectangleInfo() {
    cout << "This rectangle is " << color << " and is " << width << "x" << height << endl;
    }
};

int main(){
    cout << "--- Creating a Circle ---" << endl;
    Circle myCircle("Red", 5.0);
    myCircle.displayColor(); //inherit method from Shape
    myCircle.displayCircleInfo(); //unique method from Circle

    cout <<"\n--- Creating a Rectangle ---" << endl;
    Rectangle myRect("Blue", 4.0, 6.0);
    myRect.displayColor(); //inherit method from shape
    myRect.displayRectangleInfo(); //unique method from rectangle

    return 0;
}
