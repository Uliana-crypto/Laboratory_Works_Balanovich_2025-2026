#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <windows.h>

template<typename T>
class MyStack {
private:
	const size_t size;
	size_t top;
	T* arr;
public:
	MyStack(size_t size = 100);
	MyStack(const MyStack&);
	MyStack(MyStack&&);
	MyStack<T>& operator=(const MyStack<T>&);
	MyStack<T>& operator = (MyStack<T>&&);
	~MyStack();
	T Peek();
	void Push(T);
	void Pop();
	bool CheckBalancedBrackets(const std::string&);
	MyStack<T> SortTrainAlternating(MyStack<T>&);
	bool IsEmpty();
	bool IsFull();
};

template<typename T>
MyStack<T>::MyStack(size_t size) : size(size), top(0){
	if (size < 1) {
		throw std::invalid_argument("Stack size must be at least 1");
	}
	arr = new T[size];
}

template<typename T>
MyStack<T>::MyStack(const MyStack& rhs) : size(rhs.size), arr(new T[rhs.size]), top(rhs.top) {
	for (size_t i = 0; i < rhs.top; ++i) {
		arr[i] = rhs.arr[i];
	}
}

template<typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& rhs) {
	if (this != &rhs) {
		delete[] arr;

		arr = new T[rhs.size];
		top = rhs.top;

		for (size_t i = 0; i < rhs.top; ++i) {
			arr[i] = rhs.arr[i];
		}
	}
	return *this;
}

template<typename T>
MyStack<T>& MyStack<T>::operator=(MyStack<T>&& rhs) {
	if (this != &rhs) {
		delete[] arr;

		arr = rhs.arr;
		top = rhs.top;

		rhs.top = 0;
		rhs.arr = nullptr;
	}
	return *this;
}

template<typename T>
MyStack<T>::MyStack(MyStack&& rhs) : size(rhs.size), arr(rhs.arr), top(rhs.top){
	rhs.top = 0;
	rhs.arr = nullptr;
}

template<typename T>
bool MyStack<T>::IsEmpty() {
	return top == 0;
}

template<typename T>
bool MyStack<T>::IsFull() {
	return top == size;
}

template<typename T>
T MyStack<T>::Peek() {
	if (IsEmpty()) {
		throw std::logic_error("Stack is full");
	}
	return arr[top - 1];
}

template<typename T>
void MyStack<T>::Pop() {
	if (IsEmpty()) {
		throw std::logic_error("Stack is full");
	}
	--top;
}

template<typename T>
void MyStack<T>::Push(T value) {
	if (IsFull()) {
		throw std::logic_error("Stack is full");
	}
	arr[top] = value;
	++top;
}

template<typename T>
MyStack<T>::~MyStack() {
	delete[] arr;
	arr = nullptr;
}

template<typename T>
bool MyStack<T>::CheckBalancedBrackets(const std::string& input) {
	MyStack<char> stack;
	for (char ch : input) {
		if (ch == '[' || ch == '{' || ch == '(') {
			stack.Push(ch);
		}
		else if(ch == ')' || ch == ']' || ch == '}'){
			if (stack.IsEmpty()) {
				return false;
			}
			char top = stack.Peek();
			if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
				return false;
			}
			stack.Pop();
		}
	}
	return stack.IsEmpty();
}

template<typename T>
MyStack<T> MyStack<T>::SortTrainAlternating(MyStack<T>& input) {
	MyStack<T> white;
	MyStack<T> black;

	while (!input.IsEmpty()) {
		T value = input.Peek();
		input.Pop();
		if (value == "белый") {
			white.Push(value);
		}
		else if (value == "чёрный") {
			black.Push(value);
		}
	}

	MyStack<T> result;
	while (!white.IsEmpty() || !black.IsEmpty()) {
		if (!white.IsEmpty()) {
			result.Push(white.Peek());
			white.Pop();
		}
		if (!black.IsEmpty()) {
			result.Push(black.Peek());
			black.Pop();
		}
	}

	MyStack<T> reversed;
	while (!result.IsEmpty()) {
		reversed.Push(result.Peek());
		result.Pop();
	}
	return reversed;
}


#endif // HEADER_H