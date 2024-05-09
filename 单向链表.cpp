#include <iostream>
#include <stdexcept>
using namespace std;
typedef int eleType;

struct ListNode {
	eleType data;
	ListNode *next;
	ListNode(eleType x) : data(x), next(NULL) {}
};

class LinkedList {
	private:
		ListNode *head;
		int size;

	public:
		LinkedList() : head(NULL), size(0) {}
		~LinkedList();
		void insert(int i, eleType value);//插入
		void remove(int i);//删
		ListNode *find(eleType value);//用值查
		ListNode *get(int i);//用下标查
		void update(int i, eleType value);//改
		void print();//打印
};

//销毁链表
LinkedList::~LinkedList() {
	ListNode *curr = head;
	while (curr != NULL) {
		ListNode *temp = curr;
		curr = curr->next;
		delete temp;//删除地址上的东西
	}
}

//单向链表的元素插入
void LinkedList::insert(int i, eleType value) {
	if (i < 0 || i > size) {
		throw std::out_of_range("Invalid position");
	}
	ListNode *newNode = new ListNode(value);
	if (i == 0) {
		newNode->next = head;
		head = newNode;
	} else {
		ListNode *curr = head;
		for (int j = 0; j < i - 1; j++) {
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
	size++;
}

//单向链表的元素删除
void LinkedList::remove(int i) {
	if (i < 0 || i >= size) {
		throw std::out_of_range("Invalid position");
	}
	if (i == 0) {
		ListNode *temp = head;
		head = head->next;
		delete temp;
	} else {
		ListNode *curr = head;
		for (int j = 0; j < i - 1; j++) {
			curr = curr->next;
			//因为不是双向链表
			//所以需要用for遍历到需要删除的节点的前面一位
		}
		ListNode *temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
	size--;
}

//单向链表的元素查找
ListNode *LinkedList::find(eleType value) {
	ListNode *curr = head;
	while (curr != NULL && curr->data != value) {
		curr = curr->next;
	}
	return curr;
}

//单向链表的元素索引
ListNode *LinkedList::get(int i) {
	if (i < 0 || i > 0) {
		throw std::out_of_range("Invalid position");
	}
	ListNode *curr = head;
	for (int j = 0; j < i; j++) {
		curr = curr->next;
	}
	return curr;
}

//单向链表的元素修改
void LinkedList::update(int i, eleType value) {
	if (i < 0 || i > size) {
		throw std::out_of_range("Invalid position");
	}
	get(i)->data = value;
}

void LinkedList::print() {
	ListNode *curr = head;
	while (curr != NULL) {
		std::cout << curr->data << ' ';
		curr = curr->next;
	}
	std::cout << std::endl;
}

int main() {

}