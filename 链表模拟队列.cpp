#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>

class Queue {
	private:
		struct Node {
			T data;
			Node *next;
			Node(T d) : data(d), next(NULL) {}
		};

		Node *front;
		Node *rear;
		int size;

	public:
		Queue() : front(NULL), rear(NULL), size(0) {};
		~Queue();
		void enqueue(T element);
		T dequeue();
		T getFront() const;
		int getSize() const;
};

//删除列表
template<typename T>

Queue<T>::~Queue() {
	while (front) {
		Node *temp = front;
		front = front->next;
		delete temp;
	}
}

//队尾入队
template<typename T>

void Queue<T>::enqueue(T element) {
	if (rear == NULL) {
		rear = new Node(element);
		front = rear;
	} else {
		rear->next = new Node(element);
		rear = rear->next;
	}
	size++;
}

//队头出队
template<typename T>

T Queue<T>::dequeue() {
	if (front == NULL) {
		throw std::underflow_error("Queue is empty");
	}
	T element = front->data;
	Node *temp = front;
	front = front->next;
	delete temp;
	size--;
	if (size == 0)
		rear = NULL;
	return element;
}

template<typename T>

T Queue<T>::getFront() const {
	if (front == NULL) {
		throw std::underflow_error("Queue is empty");
	}
	return front->data;
}

//获取队列长度
template<typename T>

int Queue<T>::getSize() const {
	return size;
}

int main() {
	Queue<int>q;
	q.enqueue(3);
	q.enqueue(1145);
	cout << q.getFront() << '\n';
	q.enqueue(5);
	cout << q.getFront() << '\n';
	q.dequeue();
	cout << q.getFront() << '\n';
	cout << q.getSize() << '\n';
	return 0;
}