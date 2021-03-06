#include <cstdlib>
#include <iostream>

using namespace std;


template<typename T>
class PriorityQueue
{
	typedef struct Node
	{
		T field; //wartosc 
		int key; // klucz
		Node *nextNode; 
	} *nodePointer;

	nodePointer front; //wskaznik na nastepny element
	nodePointer back; // wskaznik na poprzedni element
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue &pque);
	~PriorityQueue();
	void enqueue(const T& newElement, int priority);
	void dequeue();
	void Print();
private:
	bool Empty();
	void pushBack(const T& newElement, int priority);
	void pushFront(const T& newElement, int priority);
	void pushFirstNode(const T& newElement, int priority);
	void pushInside(const T& newElement, int priority);
	
};


template<typename T>
PriorityQueue<T>::PriorityQueue()
{
	this->front = NULL;
	this->back = NULL;
}

template<typename T>
bool PriorityQueue<T>::Empty()
{
	if(this->front == NULL && this->back == NULL) return true;
	else return false;
}

template<typename T>
void PriorityQueue<T>::Print()
{
	if(Empty())
	{
		cout << "Priority queue is empty " <<endl;
	}
	else
	{
		nodePointer temporary = back;
		while(temporary!=NULL)
		{
			cout << "Wartość: " << temporary->field << "   Priority: " << temporary->key <<endl;
			temporary = temporary->nextNode;
		}
		cout << endl;
	}
}


template<typename T>
void PriorityQueue<T>::pushFront(const T& newElement, int priority)
{
	nodePointer adder = new Node;           //
	adder->key = priority;           		//inicjalizowanie obiektu node
	adder->field = newElement;              //
	adder->nextNode = NULL; 
	
	front->nextNode = adder;               
	front = adder;
	cout << "Enqueued element "<< newElement << " with priority " << priority << endl;
}

template<typename T>
void PriorityQueue<T>::pushBack(const T& newElement, int priority)
{
	nodePointer adder = new Node;              //
	adder->key = priority;             		   // creating new node to be added
	adder->field = newElement;                //

	adder->nextNode = back;                   // setting next node as beginner
	back = adder;                             // reseting back
	cout << "Enqueued element "<< newElement << " with priority " << priority << endl;
}

template<typename T>
void PriorityQueue<T>::pushFirstNode(const T& newElement, int priority)
{
	nodePointer adder = new Node;
	adder->key = priority;
	adder->field = newElement;
	adder->nextNode = NULL;
	front = adder;                             //    
	back = adder;                              // setting first node as back and front
	cout << "Enqueued element "<< newElement << " with priority " << priority <<endl;
}


template<typename T>
void PriorityQueue<T>::pushInside(const T& newElement, int priority)
{                                   
	nodePointer scroller = back;
	nodePointer save = back;       // 'save' to remember last suitable scroller
	while(scroller != front && scroller->key < priority)
	{
		save = scroller;                 // try to find a new place so that priority matches
		scroller = scroller->nextNode;
	}
	nodePointer toPush = new Node;
	toPush->key = priority;
	toPush->field = newElement;
	toPush->nextNode = scroller;
	save->nextNode = toPush;
	cout << "Enqueued element "<< newElement << " with priority " << priority << endl;
}


template<typename T>
void PriorityQueue<T>::enqueue(const T& newElement, int priority)
{
	if(Empty())
	{
		pushFirstNode(newElement,priority);
	}
	else
	{
		if(front->key < priority)
		{
			pushFront(newElement,priority);
		}
		else
		{
			if(back->key > priority)
			{
				pushBack(newElement,priority);
			}
			else  
			{
				pushInside(newElement,priority);
			}
		}
	}	

}


template<typename T>
void PriorityQueue<T>::dequeue()
{
	if(Empty())
	{
		cout << "Priority queue is empty" <<endl;
	}
	else
	{
		if(back == front)
		{
			cout << "Dequeued element " << front->field << " with priority " << front->key << endl;
			free(front);
			front = NULL;
			back = NULL;
		}
		else
		{
			nodePointer temporary = back;
			nodePointer save = back;
			while(temporary != front)
			{
				save = temporary;
				temporary=temporary->nextNode;
			}
			cout << "Dequeued element " << front->field << " with priority " << front->key << endl;
			front = save;
			front->nextNode = NULL;
			delete temporary;
		}
	}
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	while(back != NULL)
	{
		nodePointer temporary = back;
		back = back->nextNode;
		delete temporary;
	}
}


template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &pque)
{

	if(pque.front == NULL)
	{
		back = NULL;
		front = NULL;
	}
	else
	{
		back = NULL;
		front = NULL;
		nodePointer temp = pque.back;

		while(temp != NULL)
		{
			enqueue(temp->field,temp->key);
			temp = temp->nextNode;
		}
	}
}

