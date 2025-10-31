#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <windows.h>

template<typename TInfo>
class TDeque 
{
private:
	struct TDequeItem {
		TInfo Info; 
		TDequeItem* next; 
		TDequeItem* prev; 
	};
	TDequeItem* front;
	TDequeItem* rear;
	int size; 
	void Erase(); 
	void Clone(const TDeque<TInfo>&);
	void DeleteItem(TDequeItem*); 
public:
	TDeque(); 
	TDeque(const TDeque&); 
	~TDeque(); 
	void InsFront(TInfo);
	void InsRear(TInfo); 
	bool DelFront(TInfo&); 
	bool DelRear(TInfo&); 
	const TDeque& operator = (const TDeque<TInfo>&);
	const TInfo& GetByIndex(size_t)const; 
	void SetByIndex(TInfo, size_t); 
	void Browse(void(*func)(TInfo&));
	void Browse(void(*func)(TInfo)) const;
	void* PtrByIndex(size_t)const;
	bool IsEmpty() const;
	void Print() const;
	void InputElements(int);
};

void IncrementInt(int&);

template<typename TInfo>
TDeque<TInfo>::TDeque() : front(nullptr), rear(nullptr), size(0) {}

template<typename TInfo>
TDeque<TInfo>::TDeque(const TDeque& other) : front(nullptr), rear(nullptr), size(0) {
	Clone(other);
}

template<typename TInfo>
void TDeque<TInfo>::Clone(const TDeque<TInfo>& other) {
	TDequeItem* current = other.front;
	while (current != nullptr) {
		InsRear(current->Info);
		current = current->next;
	}
}

template<typename TInfo>
void TDeque<TInfo>::InsRear(TInfo Info) {
	TDequeItem* newItem = new TDequeItem;
	newItem->Info = Info;
	newItem->next = nullptr;
	newItem->prev = nullptr;
	if (IsEmpty()) {
		front = rear = newItem;
	}
	else {
		newItem->prev = rear;
		rear->next = newItem;
		rear = newItem;
	}
	size++;
}

template<typename TInfo>
bool TDeque<TInfo>::IsEmpty() const {
	return front == nullptr;
}

template<typename TInfo>
TDeque<TInfo>::~TDeque() {
	Erase();
}

template<typename TInfo>
void TDeque<TInfo>::Erase() {
	while (front != nullptr) {
		TDequeItem* temp = front;
		front = front->next;
		delete temp;
	}
	rear = nullptr;
	size = 0;
}

template<typename TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem* itemToDelete) {
	if (itemToDelete == nullptr) {
		return;
	}
	if (itemToDelete->prev != nullptr) {
		itemToDelete->prev->next = itemToDelete->next;
	}
	else {
		front = itemToDelete->next;
	}
	if (itemToDelete->next != nullptr) {
		itemToDelete->next->prev = itemToDelete->prev;
	}
	else {
		rear = itemToDelete->prev;
	}
	delete itemToDelete;
	size--;
}

template<typename TInfo>
void TDeque<TInfo>::InsFront(TInfo Info) {
	TDequeItem* newItem = new TDequeItem;
	newItem->Info = Info;
	if (IsEmpty()) {
		front = rear = newItem;
	}
	else {
		newItem->next = front;
		front->prev = newItem;
		front = newItem;
	}
	size++;
}

template<typename TInfo>
bool TDeque<TInfo>::DelFront(TInfo& Info) {
	if (IsEmpty()) {
		return false;
	}
	Info = front->Info;
	TDequeItem* temp = front;
	if (front == rear) {
		front = rear = nullptr;
	}
	else {
		front = front->next;
		front->prev = nullptr;
	}
	delete temp;
	size--;
	return true;
}

template<typename TInfo>
bool TDeque<TInfo>::DelRear(TInfo& Info) {
	if (IsEmpty()) {
		return false;  
	}
	Info = rear->Info;
	TDequeItem* temp = rear;
	if (front == rear) {
		front = rear = nullptr;
	}
	else {
		rear = rear->prev;
		rear->next = nullptr; 
	}
	delete temp;  
	size--;      
	return true;  
}

template<typename TInfo>
const TDeque<TInfo>& TDeque<TInfo>::operator=(const TDeque<TInfo>& other) {
	if (this != &other) {
		Clone(other);
	}
	return *this;
}

template<typename TInfo>
const TInfo& TDeque<TInfo>::GetByIndex(size_t index) const {
	if (index >= size) {
		throw std::out_of_range("Индекс вне диапазона");
	}
	TDequeItem* current = front;
	for (size_t i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->Info;
}

template<typename TInfo>
void TDeque<TInfo>::SetByIndex(TInfo value, size_t index) {
	if (index >= size) {
		throw std::out_of_range("Индекс вне диапазона");
	}
	TDequeItem* current = front;
	for (size_t i = 0; i < index; ++i) {
		current = current->next;
	}
	current->Info = value;
}

template<typename TInfo>
void TDeque<TInfo>::Browse(void(*func)(TInfo&)) {
	TDequeItem* current = front;
	while (current != nullptr) {
		func(current->Info); 
		current = current->next;
	}
}

template<typename TInfo>
void TDeque<TInfo>::Browse(void(*func)(TInfo)) const {
	TDequeItem* current = front;
	while (current != nullptr) {
		func(current->Info); 
		current = current->next;
	}
}

template<typename TInfo>
void* TDeque<TInfo>::PtrByIndex(size_t index) const {
	if (index >= size) {
		throw std::out_of_range("Индекс вне диапазона дека");
	}
	TDequeItem* current = front;
	for (size_t i = 0; i < index; ++i) {
		current = current->next;
	}
	return static_cast<void*>(&(current->Info));
}

template<typename TInfo>
void TDeque<TInfo>::InputElements(int count) {
	std::cout << "Введите " << count << " элементов:\n";
	for (int i = 0; i < count; ++i) {
		TInfo val;
		std::cin >> val;
		InsRear(val);
	}
}

template<typename TInfo>
void TDeque<TInfo>::Print() const {
	if (IsEmpty()) {
		std::cout << "пусто";
		return;
	}
	for (TDequeItem* current = front; current != nullptr; current = current->next) {
		std::cout << current->Info << " ";
	}
}

template<typename T>
void Print(T value) {
	std::cout << value << " ";
}

void IncrementInt(int& value) {
	value += 1;
}

#endif