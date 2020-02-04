#include <utility>
#include "Inventory.h"

// Allow the compiler to define the remaining
// comparison operators
using namespace std;

//------------------------------------------------------------------------------
Inventory::Node::Node()
    :data(Item(0, "Air"), 0)
{
    this->next = nullptr;
}

//------------------------------------------------------------------------------
Inventory::Node::Node(ItemStack s)
    :data(s)
{
    this->next = nullptr;
}

//------------------------------------------------------------------------------
Inventory::Inventory()
{
    this->head     = nullptr;
    this->tail     = nullptr;
    this->slots    = 10;
    this->occupied = 0;
}

//------------------------------------------------------------------------------
Inventory::Inventory(int n)
{
    this->head     = nullptr;
    this->tail     = nullptr;
    this->slots    = n;
    this->occupied = 0;
}

//------------------------------------------------------------------------------
Inventory::Inventory(const Inventory &src)
{
	head = nullptr;
	tail = nullptr;
	occupied = 0;

	Node* srcIt = src.head;

    	while (srcIt != nullptr) {
       		this->addItems(srcIt->data);

        	srcIt = srcIt->next;
    	}	
}

//------------------------------------------------------------------------------
Inventory::~Inventory()
{

	Node *this_iterator = nullptr;
	Node *to_delete = nullptr;

	this_iterator = this->head;


	while(this_iterator != nullptr){
		to_delete = this_iterator;

        	// move to next node
        	this_iterator = this_iterator->next;

        	// delete the current node
        	delete to_delete;

       	 	to_delete = nullptr;
	}

	head  = nullptr;
    	tail  = nullptr;
   	occupied = 0;	
}	

//------------------------------------------------------------------------------
bool Inventory::isFull() const
{
    // @todo implement this function
    //
    // If this is more than one line
    // in the form "return (boolean expression);"
    // you are overthinking the problem
	return false;
}

//------------------------------------------------------------------------------
void Inventory::display(std::ostream &outs) const
{
    outs << " -Used " << occupied << " of " << slots << " slots" << "\n";

    Node* it = head;
    while(it != nullptr){
        outs << "  " << it->data << "\n";
	
        it = it->next;
    }
}

//------------------------------------------------------------------------------
Inventory& Inventory::operator=(Inventory rhs)
{
    std::swap(*this, rhs);
    return *this;
}

//------------------------------------------------------------------------------
void swap(Inventory& lhs, Inventory& rhs)
{
    using std::swap;

    swap(lhs.head, rhs.head);
    swap(lhs.tail, rhs.tail);
    swap(lhs.slots, rhs.slots);
    swap(lhs.occupied, rhs.occupied);
}

//------------------------------------------------------------------------------
Inventory::Node* Inventory::findMatchingItemStackNode(const ItemStack& itemStack)
{
    // @todo implement this function
	return nullptr;
}

//------------------------------------------------------------------------------
void Inventory::mergeStacks(ItemStack& lhs, const ItemStack& rhs)
{
    // Update lhs... remember rhs is read only
}

//------------------------------------------------------------------------------
void Inventory::addItemStackNoCheck(ItemStack itemStack)
{
    // @todo implement this function
	Node *new_node = nullptr;
	
	new_node = new Node(itemStack);

    	// Setup the new node
    	new_node->next = (this->head);
    	this->head = new_node;

	this->occupied++;

	new_node = nullptr;

}
