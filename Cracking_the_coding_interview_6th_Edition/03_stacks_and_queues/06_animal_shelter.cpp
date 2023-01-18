#include <iostream>
#include <queue>
using namespace std;

// 3.6 Animal Shelter :
// An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis.
// People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
// or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type).
// They cannot select which specific animal they would like.
// Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat.
// You may use the built-in LinkedList data structure.

enum AnimalType
{
    Dog, Cat
};

class AnimalShelter
{
private:
    queue<int> dogs;
    queue<int> cats;
    int curArrivalTime;
    
public:
    AnimalShelter()
    {
        curArrivalTime = 0;
    }
    
    void enqueue(AnimalType type)
    {
        if (type == Dog)
        {
            cout << "enqueued Dog : " << curArrivalTime << endl;
            dogs.push(curArrivalTime++);
        }
        else
        {
            cout << "enqueued Cat : " << curArrivalTime << endl;
            cats.push(curArrivalTime++);
        }
    }
    
    void dequeueAny()
    {
        if (dogs.empty() == true)
        {
            dequeueCat();
            return;
        }
        else if (cats.empty() == true)
        {
            dequeueDog();
            return;
        }
        
        if (dogs.front() < cats.front())
            dequeueDog();
        else
            dequeueCat();
    }
    
    void dequeueDog()
    {
        if (dogs.empty() == true) return;
        
        cout << "dequeued Dog : " << dogs.front() << endl;
        dogs.pop();
    }
    
    void dequeueCat()
    {
        if (cats.empty() == true) return;
        
        cout << "dequeued Cat : " << cats.front() << endl;
        cats.pop();
    }
};



int main()
{
    AnimalShelter as;
    
    as.enqueue(Cat);
    as.enqueue(Cat);
    as.enqueue(Dog);
    as.enqueue(Cat);
    as.enqueue(Dog);
    
    as.dequeueDog();
    as.dequeueCat();
    
}
