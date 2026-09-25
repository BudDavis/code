#include <iostream>
#include <string>
class listItem
{
	public:
	listItem* next;
	std::string id;
	listItem(listItem*& tail,std::string id_="unspecified");
};
listItem::listItem(listItem*& tail,std::string id_)
{
	id = id_;
	next = nullptr;
	listItem* temp = tail;
	if (tail)
	{
		tail = this;
		temp->next = this;
	}
	else
	{
		tail = this;
	}
}

int main(int argc, char* argv[])
{
	listItem* head = nullptr;
	listItem* tail = nullptr;
	head = new listItem(tail,"one");
	new listItem(tail,"two");
	new listItem(tail);
	auto print = [head]()
	{
		// this function prints out the ID of
		// every node in the list, starting with the head.
		listItem* currentNode = head;
		std::string S;
		while (currentNode)
		{
			S = S + currentNode->id + " ";
			currentNode = currentNode->next;
		}
		return S;
	};
	std::cout << print()  << std::endl;
	return 0;
}
