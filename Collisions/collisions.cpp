#include <iostream>
#include <cmath>
using namespace std;

const float BUFF = 0.1;

struct Point
{
    float x, y;
    
    Point(float _x, float _y) : x(_x), y(_y) {}
    
    bool operator<=(Point const & p)
    {
        if (x == p.x) return y <= p.y;
        return x <= p.x;
    }
};

struct Circle
{
    Point pos;
    float r;
};

struct Rectangle
{
    Point lt;
    float w, h;
};

struct Line
{
    Point p1, p2;
    
    Line(Point a, Point b) : p1(a), p2(b) {}
};

struct Vector
{
    float x, y;
    
    Vector(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};


float distance(Point p1, Point p2)
{
    // Pythagorean Theorem
    float distX = p1.x - p2.x;
    float distY = p1.y - p2.y;
    return sqrt(distX * distX + distY * distY);
}

bool pointPoint(Point p1, Point p2)
{
    return (p2.x - BUFF <= p1.x) && (p1.x <= p2.x + BUFF)
        && (p2.y - BUFF <= p1.y) && (p1.y <= p2.y + BUFF);
}

bool pointCircle(Point p, Circle c)
{
    return distance(p, c.pos) <= c.r;
}

bool circleCircle(Circle c1, Circle c2)
{
    return distance(c1.pos, c2.pos) <= c1.r + c2.r;
}

bool pointRectangle(Point p, Rectangle r)
{
    return (r.lt.x <= p.x) && (p.x <= r.lt.x + r.w)
        && (r.lt.y <= p.y) && (p.y <= r.lt.y + r.h);
}

bool rectangleRectangle(Rectangle r1, Rectangle r2)
{
    return (r1.lt.x <= r2.lt.x + r2.w) && (r2.lt.x <= r1.lt.x + r1.w)
        && (r1.lt.y <= r2.lt.y + r2.h) && (r2.lt.y <= r1.lt.y + r2.h);
}

bool circleRectangle(Circle c, Rectangle r)
{
    Point closest = c.pos;
    
    if (c.pos.x < r.lt.x)            closest.x = r.lt.x;
    else if (r.lt.x + r.w < c.pos.x) closest.x = r.lt.x + r.w;
    
    if (c.pos.y < r.lt.y)            closest.y = r.lt.y;
    else if (r.lt.y + r.h < c.pos.y) closest.y = r.lt.y + r.h;
    
    return distance(closest, c.pos) <= c.r;
}

bool linePoint(Line l, Point p)
{
    float lineLen = distance(l.p1, l.p2);
    float dist1 = distance(l.p1, p);
    float dist2 = distance(l.p2, p);
    
    return (lineLen - BUFF <= dist1 + dist2) && (dist1 + dist2 <= lineLen + BUFF);
}

bool lineCircle(Line l, Circle c)
{
    // 1) is either end inside of circle ?
    if (pointCircle(l.p1, c) == true || pointCircle(l.p2, c) == true) return true;
    
    // 2) get the closest point on the line to the circle
    Vector lc (c.pos.x - l.p1.x, c.pos.y - l.p1.y);
    Vector ll (l.p1.x - l.p2.x, l.p1.y - l.p2.y);
    float dot = lc.x * ll.x + lc.y * ll.y;
    
    float lineLen = distance(l.p1, l.p2);
    float projLength = dot / lineLen;
    Vector normalizedLine (ll.x / lineLen, ll.y / lineLen);
    
    // start position + (length * direction)
    Point closest (l.p1.x + (projLength * normalizedLine.x), l.p2.y + (projLength * normalizedLine.y));
    
    // 3) is the closest point on the line ?
    if (linePoint(l, closest) == false) return false;
    
    // 4) then check if they collide
    return distance(closest, c.pos) <= c.r;
}

int ccw(Point a, Point b, Point c)
{
    // Shoelace Formula
    float cross = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
    
    // with right-hand rule
    if (0 < cross)       return 1;  // counter-clock-wise
    else if (cross == 0) return 0;  // parallel
    else                 return -1; // clock-wise
}

bool lineLine(Line a, Line b)
{
    // if ccw is <= 0, they are colliding
    int aab = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2);
    int bba = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);
    
    // if both of them are parallel
    if (aab == 0 && bba == 0)
    {
        // move smaller point to the front
        if (a.p2 <= a.p1) swap(a.p1, a.p2);
        if (b.p2 <= b.p1) swap(b.p1, b.p2);
        
        return a.p1 <= b.p2 && b.p1 <= a.p2;
    }
    
    return aab <= 0 && bba <= 0;
}

bool lineRectangle(Line l, Rectangle r)
{
    bool top    = lineLine(l, Line(Point(r.lt.x, r.lt.y),       Point(r.lt.x + r.w, r.lt.y)));
    bool left   = lineLine(l, Line(Point(r.lt.x, r.lt.y),       Point(r.lt.x, r.lt.y + r.h)));
    bool bottom = lineLine(l, Line(Point(r.lt.x, r.lt.y + r.h), Point(r.lt.x + r.w, r.lt.y + r.h)));
    bool right  = lineLine(l, Line(Point(r.lt.x + r.w, r.lt.y), Point(r.lt.x + r.w, r.lt.y + r.h)));
    
    return (left || right || top || bottom);
}


int main()
{
    
}
