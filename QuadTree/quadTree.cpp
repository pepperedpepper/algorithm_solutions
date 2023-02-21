#include <iostream>
using namespace std;


struct Pos
{
    float x, y;
    
    Pos operator+(const Pos p)
    {
        return {x + p.x, y + p.y};
    }
    
    Pos operator-(const Pos p)
    {
        return {x - p.x, y - p.y};
    }
    
    Pos operator/(int dv)
    {
        return {x / dv, y / dv};
    }
};


class QuadTree
{
private:
    static const int TERMINAL_MAP_SIZE = 1;

    enum ChildType { TL, TR, BL, BR, MAX };
    // TopLeft(TL)    TopRight(TR)
    // BottomLeft(BL) BottomRight(BR)
    
    Pos min, max, center;
    QuadTree* children[MAX];
    bool isActive = false;
    
    void SetPosition(Pos _min, Pos _max, ChildType type)
    {
        Pos halfSize = {(_max - _min) / 2};
        
        if (type == TL)
        {
            min = _min;
            max = _min + halfSize;
        }
        else if (type == TR)
        {
            min = {_min.x + halfSize.x , _min.y};
            max = {_max.x, _max.y - halfSize.y};
        }
        else if (type == BL)
        {
            min = {_min.x, _min.y + halfSize.y};
            max = {_max.x - halfSize.x, _max.y};
        }
        else if (type == BR)
        {
            min = _min + halfSize;
            max = _max;
        }
        
        center.x = min.x + (max.x - min.x) / 2;
        center.y = min.y + (max.y - min.y) / 2;
    }
    
    bool CheckCollision(Pos _min, Pos _max)
    {
        return (min.x <= _max.x) && (_min.x <= max.x) && (min.y <= _max.y) && (_min.y <= max.y);
    }

    bool CanDivide()
    {
        return ((max.x - min.x) / 2 >= TERMINAL_MAP_SIZE && (max.y - min.y) / 2 >= TERMINAL_MAP_SIZE);
    }
    
    bool DivideByFour()
    {
        if (CanDivide() == false) return false;

        for (int i = 0; i < MAX; i++)
            children[i] = new QuadTree(min, max, (ChildType)i);

        return true;
    }
    
public:
    QuadTree(Pos _min, Pos _max) : min(_min), max(_max), center(min + (max - min) / 2) {};
    QuadTree(Pos _min, Pos _max, ChildType type)
    {
        SetPosition(_min, _max, type);
    }
    
    void Build()
    {
        if (DivideByFour())
        {
            for (int i = 0; i < MAX; i++)
                children[i]->Build();
        }
    }
    
    void ActiveChildByPosition(float x, float y)
    {
        if (x < min.x || y < min.y || x > max.x || y > max.y)
        {
            cout << "The position is beyond the map" << endl;
            return;
        }
        
        if (CanDivide() == false)
        {
            isActive = true;
            return;
        }
        
        if      (x < center.x  && y < center.y) children[TL]->ActiveChildByPosition(x, y);
        else if (x > center.x && y < center.y)  children[TR]->ActiveChildByPosition(x, y);
        else if (x < center.x  && y > center.y) children[BL]->ActiveChildByPosition(x, y);
        else                                    children[BR]->ActiveChildByPosition(x, y);
    }
    
    void ActiveChildrenByBoundary(Pos _min, Pos _max)
    {
        if (CanDivide() == false)
        {
            isActive = true;
            return;
        }
        
        for (int i = 0; i < MAX; i++)
            if (children[i]->CheckCollision(_min, _max))
                children[i]->ActiveChildrenByBoundary(_min, _max);
    }
    
    void PrintActivatedChild()
    {
        if (isActive)
        {
            cout << "( " << min.x << ", " << min.y << " ) ~ ( " << max.x << ", " << max.y << " ) " << " : " << max.x - min.x << ", " << max.y - min.y << endl;
        }
        
        if (CanDivide())
        {
            for (int i = 0; i < MAX; i++)
                children[i]->PrintActivatedChild();
        }
    }
};

int main()
{
    Pos min = {0, 0};
    Pos max = {10, 10};
    
    QuadTree qt(min, max);
    qt.Build();
    
    Pos myMin = {2, 2};
    Pos myMax = {5, 5};
    
    qt.ActiveChildrenByBoundary(myMin, myMax);
    qt.PrintActivatedChild();
}
