
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    
}
class World {
    Node* StartingNode;
};
class Node {
public:
    bool Player = false;
    bool Wall = false;
    bool Empty = false;
    char type;
    Node* North; Node* South; Node* Left; Node* Down;

    Node(char _type) {
        if (_type == 'W') { Wall = true; }
        if (_type == 'E') { Empty = true; }
        if (_type == 'P') { Player = true; }
        type = _type;
    }
};
void Draw() {};