#include <iostream>
#include <cstdlib>
#include <string>


template <typename T>
class LinkedList
{
	private:
		T value;
		LinkedList<T>* next;

	public:
		LinkedList(); 
		~LinkedList();
		void push(T);
		void pop();
		bool is_empty();
		size_t length();
		T operator[](int);
		template <typename S>
		friend std::ostream& operator<<(std::ostream&, LinkedList<S>&);
		/* friend is used to declare a non-member function with a
		 * permission to access this class' private attribues.
		 * Note, I need to use the template with a different
		 * identifier (not T; S in this case) otherwise it
		 * 'shadows' the identifier (T in this case) of the
		 * class
		 */
};

template <typename T>
LinkedList<T>::LinkedList()
{
	/* the parent node does not store a value, so empty list's
	 * 'value' field is garbage; obj[0] is therefore the first
	 * child's value, not parent's value. Such implementation
	 * ensures consistency in allocation/deallocation. Also,
	 * this->next == NULL guarantees that the list is empty,
	 * which wouldn't be the case if the first element was
	 * stored in the parent node.
	 */
	this->next = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	LinkedList<T>* right = this->next;
	LinkedList<T>* left = this;
	while (right != NULL){
		left = right;
		right = right->next;
		delete left;
	}
	this->next = NULL;
}

template <typename T>
void LinkedList<T>::push(T value)
{
	LinkedList<T>* curr = this;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new LinkedList<T>;
	curr->next->value = value;
	curr->next->next = NULL;
}

template <typename T>
void LinkedList<T>::pop()
{
	if(this->next == NULL)
		throw std::range_error("popping off an empty list");
	LinkedList<T>* curr = this;
	while(curr->next->next != NULL)
		curr = curr->next;
	delete curr->next;
	curr->next = NULL;
}

template <typename T>
bool LinkedList<T>::is_empty()
{
	if(this->next == NULL)
		return true;
	return false;
}

template <typename T>
size_t LinkedList<T>::length()
{
	if(this->next == NULL)
		return 0;
	LinkedList<T>* curr = this;
	size_t curr_index = 0;
	while (curr->next != NULL){
		curr_index++;
		curr = curr->next;
	}
	return curr_index;
}

template <typename T>
T LinkedList<T>::operator[](int index)
{
	if(this->next == NULL)
		throw std::range_error("cannot access an empty list");
	LinkedList<T>* curr = this;
	int curr_index = 0;
	while (curr->next != NULL){
		if (index == curr_index++)
			return curr->next->value;
		curr = curr->next;
	}
	throw std::range_error("index out of bounds");
}

template <typename T>
std::ostream& operator<<(std::ostream& os, LinkedList<T>& ll)
{
	LinkedList<T>* curr = &ll;
	os << "[ ";
	while (curr->next != NULL){
		os << curr->next->value << ", ";
		curr = curr->next;
	}
	os << "]";
	return os;
}
