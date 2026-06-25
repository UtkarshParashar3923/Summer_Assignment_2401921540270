#include <iostream>
using namespace std;

// ================== 1. Interface test + arithmetic + ToTestInt ==================
// C++ me interface = pure virtual class
class test {
public:
    virtual int square(int n) = 0; // pure virtual function
    virtual ~test() {} // virtual destructor
};

class arithmetic : public test {
public:
    int square(int n) override {
        return n * n;
    }
};

class ToTestInt {
    arithmetic obj; // object of arithmetic class
public:
    void testSquare() {
        int num = 5;
        cout << "1. Square of " << num << " = " << obj.square(num) << endl;
    }
};

// ================== 2. Outer class + Inner class ==================
class Outer {
public:
    void display() {
        cout << "2. Outer class display() called" << endl;
    }
    
    class Inner {
    public:
        void display() {
            cout << "   Inner class display() called" << endl;
        }
    };
};

// ================== 3. Point class ==================
class Point {
private:
    int x, y;
public:
    Point() { // default constructor
        x = 0;
        y = 0;
    }
    
    Point(int x, int y) { // parameterized constructor
        this->x = x;
        this->y = y;
    }
    
    void setX(int x) {
        this->x = x;
    }
    
    void setY(int y) {
        this->y = y;
    }
    
    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    void display() {
        cout << "3. Point: (" << x << ", " << y << ")" << endl;
    }
};

// ================== 4. box and box3d ==================
class box {
protected: // so box3d can access
    double length, breadth;
public:
    box() {
        length = breadth = 0;
    }
    
    box(double l, double b) {
        length = l;
        breadth = b;
    }
    
    void setDimension(double l, double b) {
        length = l;
        breadth = b;
    }
    
    double area() {
        return length * breadth;
    }
};

class box3d : public box {
private:
    double height;
public:
    box3d() : box() {
        height = 0;
    }
    
    box3d(double l, double b, double h) : box(l, b) {
        height = h;
    }
    
    void setDimension(double l, double b, double h) {
        box::setDimension(l, b); // call base class method
        height = h;
    }
    
    double volume() {
        return length * breadth * height; // length, breadth inherited from box
    }
    
    void display() {
        cout << "4. Box3D: " << length << " x " << breadth << " x " << height << endl;
        cout << "   Base area = " << area() << endl;
        cout << "   Volume = " << volume() << endl;
    }
};

// ================== Main Function ==================
int main() {
    cout << "===== OOPS Problem of the Week =====\n" << endl;
    
    // 1. Interface test
    ToTestInt tester;
    tester.testSquare();
    cout << endl;
    
    // 2. Outer + Inner class
    Outer out;
    out.display();
    Outer::Inner in; // inner class object
    in.display();
    cout << endl;
    
    // 3. Point class
    Point p1;
    p1.display();
    Point p2(10, 20);
    p2.display();
    p2.setXY(7, 14);
    p2.display();
    cout << endl;
    
    // 4. box and box3d
    box3d b1;
    b1.setDimension(5, 4, 3);
    b1.display();
    
    return 0;
}
