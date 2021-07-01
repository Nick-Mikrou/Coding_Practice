#include <iostream>

using namespace std;

class Node
{
	public:
		size_t data;
		Node* next;

		Node() noexcept
			:data(0),next(nullptr)
		{
			cout << "Default Constructor of the class Node for the object 0x:" << this << endl;
		}	// Default Constructor

		Node(const size_t thedata) noexcept
			:data(thedata),next(nullptr)
		{
			cout << "Constructor of the class Node for the object 0x:" << this << endl;
		}	// Constructor

		~Node() noexcept
		{}	// Destructor
};

class LinkedList : public Node {

}

int main() {



    return 0;
}
