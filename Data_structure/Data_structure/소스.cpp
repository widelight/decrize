#include <iostream>
#include <string>
using namespace std;

class DblNode {
private:
	string* data;
public:
	DblNode* llink;
	DblNode* rlink;
	DblNode();
	DblNode(string data);
	string getData();
	void setData(string data);

};

DblNode::DblNode() {
	data = NULL;
	llink = NULL;
	rlink = NULL;
}
DblNode::DblNode(string data) {
	*(this->data) = data;
	llink = NULL;
	rlink = NULL;
}
string DblNode::getData() {
	return *data;
}
void DblNode::setData(string data) {
	*(this->data) = data;
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm

class DblLinkedList {
private:
	DblNode* head;
public:
	DblLinkedList();
	DblNode* getHead();	
	void insertNode(DblLinkedList* L, DblNode* pre, string data);
	void deleteNode(DblLinkedList* L, DblNode* old);
};
DblLinkedList::DblLinkedList() {
	head = NULL;
}
DblNode* DblLinkedList::getHead() {
	return head;
}
void DblLinkedList::insertNode(DblLinkedList* L, DblNode* pre, string data){
	DblNode newNode(data);
	if (L->head == NULL) {
		L->head = &newNode;
	}
	else {
		newNode.rlink = pre->rlink;
		pre->rlink = &newNode;
		newNode.llink = pre;
		if (newNode.rlink != NULL){
			DblNode* post = newNode.rlink;
			post->llink = &newNode;
			post->rlink = NULL;
		}

	}
}
void DblLinkedList::deleteNode(DblLinkedList* L, DblNode* old) {
	if (L->head == old) {
		L->head = NULL;
	}
	else {
		DblNode* pre = old->llink;
		DblNode* post = old->rlink;
		old->llink = post->llink;
		pre->rlink = old->rlink;
	}
}
int main() {
	DblLinkedList* L = new DblLinkedList();
	DblNode* pre = NULL;
	L->insertNode(L, pre, "월");

	DblNode* mon = (L->getHead());
	L->insertNode(L, mon, "화");	
	DblNode* tue = mon->rlink;
	L->insertNode(L, tue, "수");
	DblNode* wed = tue->rlink;
	L->insertNode(L, wed, "목");
	DblNode* thu = wed->rlink;
	L->insertNode(L, thu, "금");
	DblNode* fri = thu->rlink;
	L->insertNode(L, fri, "토");
	DblNode* sat = fri->rlink;

	DblNode* temp = L->getHead();
	
	cout << "Double Linked List L = (";
	while (temp != NULL) {
		cout << temp->getData();
		pre = temp; temp = temp->rlink;
		if (temp != NULL) {
			cout << ", ";
		}
	}
	cout << ")" << endl;


}