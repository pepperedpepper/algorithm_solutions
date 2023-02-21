#include <iostream>
using namespace std;

class QuadTree
{
private:
    static const int TERMINAL_MAP_SIZE = 1;
    
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
    
    enum ChildType { TL, TR, BL, BR, MAX };
    // TopLeft(TL)    TopRight(TR)
    // BottomLeft(BL) BottomRight(BR)
    
    Pos min, max, center;
    QuadTree* children[MAX];
    bool isActive = false;
    
    void SetPos(Pos _min, Pos _max, ChildType type)
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
            max = _min + halfSize;
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
    QuadTree(int minX, int minY, int maxX, int maxY)
    {
        min.x = minX;
        min.y = minY;
        max.x = maxX;
        max.y = maxY;
        center.x = minX + (maxX - minX) / 2;
        center.y = minY + (maxY - minY) / 2;
    }
    
    QuadTree(Pos _min, Pos _max, ChildType type)
    {
        SetPos(_min, _max, type);
    }
    
    void Build()
    {
        if (DivideByFour())
        {
            for (int i = 0; i < MAX; i++)
                children[i]->Build();
        }
    }
    
    void ActiveIfContains(int x, int y)
    {
        if (CanDivide() == false)
        {
            isActive = true;
            return;
        }
        
        if      (x < center.x  && y < center.y)  children[TL]->ActiveIfContains(x, y);
        else if (x >= center.x && y < center.y)  children[TR]->ActiveIfContains(x, y);
        else if (x < center.x  && y >= center.y) children[BL]->ActiveIfContains(x, y);
        else                                     children[BR]->ActiveIfContains(x, y);
    }
    
    void Print()
    {
        cout << ((isActive == true) ? "TRUE " : "FALSE ");
        cout << "( " << min.x << ", " << min.y << " ) ~ ( " << max.x << ", " << max.y << " ) " << endl;
        
        if (CanDivide())
        {
            for (int i = 0; i < MAX; i++)
                children[i]->Print();
        }
    }
};

int main()
{
    int mapSize = 10;
    
    QuadTree qt(0, 0, mapSize, mapSize);
    qt.Build();
    qt.ActiveIfContains(2, 2);
    qt.Print();
}
