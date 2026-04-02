#ifndef POINT_H
#define POINT_H

class Point{
private:
    double x, y;
public:
    Point(double x, double y) : x(x), y(y) {}
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

#endif // POINT_H
