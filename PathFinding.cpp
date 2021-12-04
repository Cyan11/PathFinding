#include <iostream>
#include <random>
#include <cstdlib>

char notLine[] = "_______________________________________\n";
char line[] = "|.....................................|\n";

char grid[10][41];

//Eu tinha botado a função de lista q agnt criou mas nn precisa ent ignora
class Element {
public:
	Node* data;
	Element* next;
	Element* previous;

};
class List {
public:
	Element* Last;
	Element* Start;
	int Size = 0;
	void Create() {
		Last = 0;
		Start = 0;
		Size = 0;
	}
	void AddToList(Node* _data)
	{
		Element* element = new Element();
		element->data = _data;
		Size++;
		if (Last == NULL)
		{
			Start = element;
			Last = Start;
		}
		else
		{
			Last->next = element;
			element->previous = Last;
			Last = element;
		}
	}
	Element* GetElement(int index) {
		Element* current = new Element();
		for (size_t i = 0; i < index; i++)
		{
			if (current == NULL) {
				current = Start;
			}
			else {
				current = current->next;
			}
		}
		return current;
	}
	Node* ReplaceNode(Node* data, int index) {
		Element* current = new Element();
		if (index == 0) {
			current->data = data;
			return data;
		}
		if (index << Size / 2)
		{
			current = Start;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
		}
		else
		{
			current = Last;
			index = Size - index;
			for (int i = 0; i < index; i++)
			{
				current = current->previous;
			}
		}
		current->data = data;
		return data;
	}
	Node* ReplaceNodeByData(Node* TargetData, Node* newData) {
		Element* current = new Element();
		current = Start;
		if (current->data == TargetData) {
			current->data = newData;
			return current->data;
		}
		while (current != NULL) {
			if (current->data == TargetData) {
				current->data = newData;
				return current->data;
			}
			current = current->next;
		}
	}
	void PrintList() {
		Element* current = Start;
		while (current->next != NULL) {
			current = current->next;
			std::cout << current->data << std::endl;
		}
		std::cout << std::endl;
	}

};

Node* neighbors[8];

class Node {
public:
    int x, y;
    bool isValid = false;
    Node* _next;

    Node(int xPos,int yPos){
        x = xPos; y = yPos; 
		if (grid[x][y] == '.') { isValid = true; }
    }
};
float hScore(Node* n, Node* goal) {
    return sqrt((n->x - goal->x) ^ 2 + (n->y - goal->y) ^ 2);
};
float gScore(Node* n, Node* start) {
    return sqrt((n->x - start->x) ^ 2 + (n->y - start->y) ^ 2);
}
float fScore(Node* n, Node* start, Node* goal) {
    if (!n->isValid) { return 1000000; }
    return hScore(n, goal) + gScore(n, start);
}
float aStar(Node* start, Node* goal) {

	fillNeighbors(start);
	std::cout << fScore(neighbors[7], start, goal);

}
void fillNeighbors(Node* n)
{
	for (int i = 0; i < 8; i++) {
		free(neighbors[i]);
	}

	neighbors[0] = new Node(n->x - 1, n->y - 1);
	neighbors[1] = new Node(n->x, n->y - 1);
	neighbors[2] = new Node(n->x + 1, n->y - 1);
	neighbors[3] = new Node(n->x - 1, n->y);
	neighbors[4] = new Node(n->x + 1, n->y);
	neighbors[5] = new Node(n->x - 1, n->y + 1);
	neighbors[6] = new Node(n->x, n->y + 1);
	neighbors[7] = new Node(n->x + 1, n->y + 1);
	
}
void makeGrid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 41; j++)
        {
            if (i != 0 && i != 9)
            {
                grid[i][j] = line[j];
            }
            else
            {
                grid[i][j] = notLine[j];
            }
        }
    }
}
void printGrid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 41; j++)
        {
            std::cout << grid[i][j];
        }
    }
}
void MakeObstacles(int maxObstacleAmount, int ObstacleAmount = 0) 
{
    int x = rand() % 38 + 1;
    int y = rand() % 8 + 1;
    grid[y][x] = '*';
    ObstacleAmount++;
    if (ObstacleAmount <= maxObstacleAmount) {
        MakeObstacles(maxObstacleAmount, ObstacleAmount);
    }
};

void DoGrid() {
    makeGrid();
    MakeObstacles(10);
    printGrid();
};
void MakeStartEnd() {

};


int main()
{
    srand((int)time(0));

    for (size_t i = 0; i < 30; i++)
    {
        DoGrid();
    }
	Node* nStart = new Node(1, 1);
	Node* nEnd = new Node(8, 37);
	aStar(nStart, nEnd);
}
