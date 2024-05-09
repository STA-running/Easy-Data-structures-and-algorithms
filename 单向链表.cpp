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
		void insert(int i, eleType value);//����
		void remove(int i);//ɾ
		ListNode *find(eleType value);//��ֵ��
		ListNode *get(int i);//���±��
		void update(int i, eleType value);//��
		void print();//��ӡ
};

//��������
LinkedList::~LinkedList() {
	ListNode *curr = head;
	while (curr != NULL) {
		ListNode *temp = curr;
		curr = curr->next;
		delete temp;//ɾ����ַ�ϵĶ���
	}
}

//���������Ԫ�ز���
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

//���������Ԫ��ɾ��
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
			//��Ϊ����˫������
			//������Ҫ��for��������Ҫɾ���Ľڵ��ǰ��һλ
		}
		ListNode *temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
	size--;
}

//���������Ԫ�ز���
ListNode *LinkedList::find(eleType value) {
	ListNode *curr = head;
	while (curr != NULL && curr->data != value) {
		curr = curr->next;
	}
	return curr;
}

//���������Ԫ������
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

//���������Ԫ���޸�
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