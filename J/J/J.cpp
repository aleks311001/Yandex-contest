#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <assert.h>

class CDeque {
public:
	CDeque()
		: deque(NULL), size(0), realSize(0), back(1), front(0)
	{}
	~CDeque() {
		delete[] deque;
	}

	void push_back(double x);
	void push_front(double x);
	void pop_back();
	void pop_front();
	double getAt(int n) const;
	double operator[](int n) const {
		return getAt(n);
	}
	void printDeque();

private:
	static const int MINIMAL_SIZE;
	static const double COEFFICIENT;
	int size;
	int realSize;
	double* deque;
	int back;
	int front;
	void newDeque(int newSize);
	void checkNewDeque();
};

const int CDeque::MINIMAL_SIZE = 4;
const double CDeque::COEFFICIENT = 2.0;

int main()
{
	/*CDeque deq;
	deq.push_back(9);
	deq.push_back(8);
	deq.push_front(7);
	deq.push_front(6);
	deq.push_back(5);
	deq.push_front(4);
	deq.push_front(3);
	deq.push_back(2);
	deq.push_back(1);
	deq.pop_back();
	deq.pop_back();
	deq.pop_front();
	deq.pop_front();

	deq.printDeque();*/
    return 0;
}

void CDeque::printDeque() {
	for (int i = 0; i < realSize; ++i)
		printf("[%d]=%lg | ", i, deque[(i + front + 1) % size]);
	printf("\nfront = %d, back = %d", front, back);
}

void CDeque::newDeque(int newSize) {
	newSize = std::max(static_cast<const int>(newSize), MINIMAL_SIZE);
	if (size == newSize)
		return;

	double* newDeq = new double[newSize];
	for (int i = 0; i < realSize; i++)
		newDeq[i] = deque[(front + i + 1) % size];
	delete[] deque;
	
	deque = newDeq;
	size = newSize;
	front = size - 1;
	back = realSize;
}

void CDeque::checkNewDeque() {
	if (size == realSize) {
		newDeque(static_cast<int>(std::ceil(COEFFICIENT * size)));
		return;
	}
	if (realSize * COEFFICIENT * COEFFICIENT < size)
		newDeque(static_cast<int>(std::floor(size / COEFFICIENT)));
}

double CDeque::getAt(int n) const {
	assert(n >= 0 && n < realSize && deque != 0);
	return deque[(front + n + 1) % size];
}

void CDeque::push_back(double x) {
	checkNewDeque();
	assert(back >= 0 && back < size && realSize <= size && realSize == (size + back - front - 1) % size);
	deque[back] = x;
	back = (back + 1) % size;
	++realSize;
}

void CDeque::push_front(double x) {
	checkNewDeque();
	assert(front >= 0 && front < size && realSize <= size && realSize == (size + back - front - 1) % size);
	deque[front] = x;
	front = (size + front - 1) % size;
	++realSize;
}

void CDeque::pop_back() {
	assert(realSize > 0 && realSize == (size + back - front - 1) % size);
	back = (size + back - 1) % size;
	--realSize;
	checkNewDeque();
}

void CDeque::pop_front() {
	assert(realSize > 0 && realSize == (size + back - front - 1) % size);
	front = (front + 1) % size;
	--realSize;
	checkNewDeque();
}