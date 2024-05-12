#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>

class Queue {
	private:
		T *data;
		int front;
		int rear;
		int capacity;
		void resize();

	public:
		Queue() :  capacity(10), data(new T[capacity]), front(0), rear(0) {}
		~Queue();
		void enqueue(T element);
		T dequeue();
		T getFront() const;
		int getSize() const;

};

//队列扩容
template<typename T>

void Queue<T>::resize() {
	T *newData = new T[capacity * 2];
	for (int i = 0; i < rear; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity *= 2;
}

//队列销毁
template<typename T>

Queue<T>::~Queue() {
	delete[] data;
}

//队尾入队
template<typename T>

void Queue<T>::enqueue(T element) {
	if (rear == capacity) {
		resize();
	}
	data[rear++] = element;
}

//队头出队
template<typename T>

T Queue<T>::dequeue() {
	if (front == rear) {
		throw std::underflow_error("Queue is empty");
	}

	return data[front++];
}

//获取队头元素
template<typename T>

T Queue<T>::getFront() const {
	if (front == rear) {
		throw std::underflow_error("Queue is empty");
	}
	return data[front];
}

template<typename T>

int Queue<T>::getSize() const {
	return rear - front;
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