#include <queuea/queuea.hpp>

#include <iostream>

int main() {
	QueueA n;
	for (int i = 0; i < 21; i++) {
		n.push(i);
	}

	n.pop();
	n.pop();
	for (int i = 0; i < 21; i++) {
		n.push(i);
	}

	QueueA m;
	n.pop();
	n.pop();
	n.pop();
	n.pop();
	m = n;
	m.pop();
	for (int i = 0; i < 21; i++) {
		m.push(i);
	}
	std::cout << n.is_empty() << " " << n.size() << std::endl;
	std::cout << m.is_empty() << " " << m.size() << std::endl;

}