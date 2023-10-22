#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool on_segment(Point p1, Point p2, Point p3)
{
    int x1 = min(p1.x, p2.x);
    int x2 = max(p1.x, p2.x);
    int y1 = min(p1.y, p2.y);
    int y2 = max(p1.y, p2.y);
    if ((x1 <= p3.x && x2 >= p3.x) && (y1 <= p3.y && y2 >= p3.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int direction(Point p1, Point p2, Point p3)
{
    //finding determinent 
    return ((p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x));
}

bool segment_intersect(Point p1, Point p2, Point p3, Point p4)
{
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);

    if ((d1 * d2) < 0 && (d3 * d4) < 0)
    {
        return true;
    }
    else if (d1 == 0 && on_segment(p3, p4, p1))
    {
        return true;
    }
    else if (d2 == 0 && on_segment(p3, p4, p2))
    {
        return true;
    }
    else if (d3 == 0 && on_segment(p1, p2, p3))
    {
        return true;
    }
    else if (d4 == 0 && on_segment(p1, p2, p4))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Point p1(1, 1);
    Point p2(3, 3);
    Point p3(5, 5);
    Point p4(8, 8);

    if (segment_intersect(p1, p2, p3, p4))
    {
        cout << "Segments are intersecting" << endl;
    }
    else
    {
        cout << "Segments are not intersecting" << endl;
    }

    return 0;
}