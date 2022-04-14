#include <iostream>
#include <string>
using namespace std;
typedef struct Node{
	string data;
	Node* llink;
	Node* rlink;
	
	Node() : llink(NULL), rlink(NULL), data(NULL) {};
	Node(string data) : llink(NULL), rlink(NULL), data(data){};
	};
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm

class DblLinkedList {
private:
	Node* head;
public:
	DblLinkedList();
	~DblLinkedList();
	Node* getHead();
	void setHead(Node* willHead);
	void insertNode(DblLinkedList* L, Node* pre, string data);
	void deleteNode(DblLinkedList* L, Node* old);
};
DblLinkedList::DblLinkedList() {
	head = NULL;
}
Node* DblLinkedList::getHead() {
	return head;
}
void DblLinkedList::setHead(Node* willhead) {
	head = willhead;
}
void DblLinkedList::insertNode(DblLinkedList* L, Node* pre, string data){
	Node* newNode = new Node(data);
	newNode->data = data;
	if (L->getHead() == NULL) {
		L->setHead(newNode);
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL){
			Node* post = newNode->rlink;
			post->llink = newNode;
		}

	}
}
void DblLinkedList::deleteNode(DblLinkedList* L, Node* old) {
	if (L->head == old) {
		L->head = NULL;
	}
	else {
		Node* pre = old->llink;
		Node* post = old->rlink;
		if (post!=NULL) {
			pre->rlink = post;
			post->llink = pre;
		}
	}
}
int main() {
	DblLinkedList* L = new DblLinkedList();
	
	Node* pre = NULL;
	L->insertNode(L, pre, "월");

	Node* mon = L->getHead();
	
	L->insertNode(L, mon, "목");
	
	Node* thu = mon->rlink;
	L->insertNode(L, thu, "금");
	
	Node* fri = thu->rlink;
	L->insertNode(L, fri, "토");
	//////////////////////////
	Node* sat = fri->rlink;

	L->insertNode(L, mon, "화");

	Node* tue = mon->rlink;
	L->insertNode(L, tue, "수");

	Node* wed = tue->rlink;

	Node* temp = L->getHead();

	cout << "Double Linked List L = (";
	while (temp != NULL) {
		cout << temp->data;
		temp = temp->rlink;
		if (temp != NULL) {
			cout << ", ";
		}
	}
	cout << ")" << endl;

	L->deleteNode(L, thu);
	L->deleteNode(L, sat);
	
	cout << "Double Linked List Reverse L = (";
	temp = fri;
	while (temp != NULL) {
		cout << temp->data;
		temp = temp->llink;
		if (temp != NULL)
			cout << ", ";
	}
	cout << ")" << endl;

}