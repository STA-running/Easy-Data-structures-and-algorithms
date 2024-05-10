#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>

class Stack {
	private:
		struct Node {
			T data;
			Node *next;
			Node(T d) : data(d), next(NULL) {};
		};

		Node *head;
		int size;

	public:
		Stack() : head(NULL), size(0) {};
		~Stack();
		void push(T element);
		T pop();
		T top() const;
		int getSize() const;
};


//栈的销毁
template<typename T>

Stack<T>::~Stack() {
	while (head != NULL) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

//入栈
template<typename T>

void Stack<T>::push(T element) {
	Node *newNode = new Node(element);
	newNode->next = head;
	head = newNode;
	size++;
}

//出栈
template<typename T>

T Stack<T>::pop() {
	if (head == NULL) {
		throw std::underflow_error("Stack is empty");
	}
	T result = head->data;
	Node *temp = head;
	head = head->next;
	delete temp;
	--size;
	return result;
}

//获取栈顶元素
template<typename T>

T Stack<T>::top() const {
	if (head == NULL) {
		throw std::underflow_error("Stack is empty");
	}
	return head->data;
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