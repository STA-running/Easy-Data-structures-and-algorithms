#include <iostream>
using namespace std;
template<typename T>

class Stack {
	private:
		T *data;
		int size;
		int capacity;
		void resize();

	public:
		Stack() : data(new T[10]), size(0), capacity(10) {}
		~Stack();
		void push(T element);
		T pop();
		T top() const;
		int getSize() const;
};

//ջ������
template<typename T>

void Stack<T>::resize() {
	int newCapacity = capacity * 2;
	T *newData = new T[newCapacity];
	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity = newCapacity;
}

//ջ������
template<typename T>

Stack<T>::~Stack() {
	delete[] data;
}

//��ջ
template<typename T>

void Stack<T>::push(T element) {
	if (size == capacity) {
		resize();
	}
	data[size++] = element;
}

//��ջ
template<typename T>

T Stack<T>::pop() {
	if (size == 0) {
		throw std::underflow_error("Stack is empty");
	}
	return data[--size];
}

//��ȡջ��Ԫ��
template<typename T>

T Stack<T>::top() const {
	if (size == 0) {
		throw std::underflow_error("Stack is empty");
	}
	return data[size - 1];
}

template<typename T>

int Stack<T>::getSize() const {
	return size;
}

int main() {
	Stack<int> st;
	st.push(4);
	st.push(114);
	st.push(114514);
	cout << st.top() << '\n';
	st.push(12);
	cout << st.top() << '\n';
	st.pop();
	st.pop();
	cout << st.top() << '\n';
	cout << st.getSize() << '\n';
	return 0;
}