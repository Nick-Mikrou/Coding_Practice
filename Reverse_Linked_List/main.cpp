#include <iostream>

using namespace std;

class Node {
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
    private:
        Node* head;

    public:
        LinkedList() noexcept
			:head(nullptr)
		{
			cout << "Default constructor of the class LinkedList for the object   0x:" << this << endl;
		}	// Default Constructor

		LinkedList(const size_t thedata) noexcept
			:Node(thedata),head(this)
		{
			cout << "Constructor of the class LinkedList for the object           0x:" << this << endl;
		}	// Constructor

		void AddNode(const size_t data) noexcept
		{
			Node* temp = new Node(data);
			temp->next = head;
			head = temp;
		}	// Add Node

		void PrintLinkedList() noexcept
		{
			Node* tmp = head;
			while (tmp)
			{
				cout << tmp->data << " -> ";
				tmp = tmp->next;
			}
		}	// Print Linked List

		Node ReverseLinkedList() noexcept
		{
			Node* prev = nullptr;
			while (head)
			{
				Node* tmp = head->next;
				head->next = prev;
				prev = head;
				head = tmp;
			}
			head = prev;
			return *head;
		}

		~LinkedList() noexcept
		{}	//Destructor
}

int main() {

    cout << "Create the list" << endl;
    LinkedList list(13);

    cout << "Add nodes" << endl;
    list.AddNode(45);
    list.AddNode(78);
    list.AddNode(100);
    list.AddNode(32);

    cout << "Before reverse" << endl;
    list.PrintLinkedList();

    cout << "After reverse" << endl;
    list.ReverseLinkedList();
    list.PrintLinkedList();
    
    return 0;
}
