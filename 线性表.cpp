#include <iostream>
using namespace std;
typedef  int eleType;

struct SequentialList {
	eleType *elements;
	int size;
	int capacity;
};

//初始化
void initializeList(SequentialList *list, int capacity) {
	list->elements = new eleType[capacity];
	list->size = 0;
	list->capacity = capacity;
}

//销毁
void destroyList(SequentialList *list) {
	delete[] list->elements;
}

//判断是否为空
bool isEmpty(SequentialList *list) {
	return list->size == 0;
}

//获取线性表大小
int size(SequentialList *list) {
	return list->size;
}

//线性表的元素插入
void insert(SequentialList *list, int index, eleType element) {
	if (index < 0 || index > list->size) { //抛出异常
		throw std::invalid_argument("Invalid index\n");
	}

	//扩容
	if (list->size == list->capacity) {
		int newCapacity = list-> capacity * 2;
		eleType *newElements = new eleType[newCapacity];
		for (int i = 0; i < list->size; i++) {
			newElements[i] = list->elements[i];
		}
		delete[] list->elements;
		list->elements = newElements;
		list->capacity = newCapacity;
	}

	for (int i = list->size; i > index; i--) { //往后移动
		list->elements[i] = list->elements[i - 1];
	}
	list->elements[index] = element;
	list->size++;
}

//元素删除
void deleteElement(SequentialList *list, int index) {
	if (index < 0 || index >= list->size) {
		throw std::invalid_argument("Invalid index");
	}

	for (int i = index; i < list->size - 1 ; i++) {
		list->elements[i] = list->elements[i + 1];
	}
	list->size--;
}

//查找
int findElements(SequentialList *list, eleType element) {
	for (int i = 0; i < list->size; i++) {
		if (list->elements[i] == element) {
			return i;
		}
	}
	return -1;
}

//元素修改
void updateElement(SequentialList *list, int index, eleType value) {
	if (index < 0 || index >= list->size) {
		throw std::invalid_argument("Invalid index");
	}
	list->elements[index] = value;
}

//获得元素
eleType getElements(SequentialList *list, int index) {
	if (index < 0 || index > list->size) {
		throw std::invalid_argument("Invalid index");
	}
	return list->elements[index];
}

void print(SequentialList *list) {
	for (int i = 0; i < list->size; i++) {
		cout << getElements(list, i) << ' ';
	}
	cout << '\n';
}


int main() {
	SequentialList mylist;
	initializeList(&mylist, 10);

	for (int i = 0; i < 10; i++) {
		insert(&mylist, i, i * 10);
	}

	cout << "Size: " << size(&mylist) << endl;
	cout << "Is empty: " << isEmpty(&mylist) << '\n';

	print(&mylist);

	deleteElement(&mylist, 5);
	updateElement(&mylist, 1, 114514);

	int idx = findElements(&mylist, 114514);
	updateElement(&mylist, idx, 1145);

	cout << "size: " << size(&mylist) << '\n';
	cout << "Is Empty: " << isEmpty(&mylist) << '\n';
	print(&mylist);

	destroyList(&mylist);
	return 0;
}