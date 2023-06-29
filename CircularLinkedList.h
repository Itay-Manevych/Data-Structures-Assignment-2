#pragma once

#include <iostream>
#include <time.h> // in order to randomize rand()
using namespace std;

template <class T>
class CircularLinkedList {
private:
	class Node {
	private:
		Node* next;
		Node* prev;
		T value;
		friend class CircularLinkedList<T>;
	public:
		// Constructors
		Node() {
			SetNext(nullptr);
		}

		Node(T val, Node* _next = nullptr, Node* _prev = nullptr) {
			SetNext(_next);
			SetPrev(_prev);
			SetValue(val);
		}

		Node(Node* copy) {
			SetNext(copy->GetNext());
			SetValue(copy->GetValue());
			SetValue(copy->GetValue());
		}

		// Getters and Setters
		int GetValue() const { return value; }
		Node* GetNext() const { return next; }
		Node* GetPrev() const { return prev; }

		void SetNext(Node* new_next) { next = new_next; }
		void SetPrev(Node* new_prev) { prev = new_prev; }
		void SetValue(T new_val) { value = new_val; }
	};

	Node* head;
public:

	CircularLinkedList() {
		int n = rand() % (100) + 1; // making a random number between 1 and 100
		if (n == 1) { return; }

		srand(time(NULL));

		this->head = new Node(rand() % 2, nullptr, nullptr);

		while (true) {
			n = rand() % (100) + 1;
			if (n == 1) {
				return;
			}
			Node* new_node = new Node(rand() % 2);
			if (this->head->GetNext() == nullptr) {
				this->head->SetNext(new_node);
				this->head->SetPrev(new_node);
				new_node->SetNext(this->head);
				new_node->SetPrev(this->head);
			}
			else {
				new_node->SetPrev(this->head->GetPrev());
				new_node->SetNext(this->head);
				this->head->GetPrev()->SetNext(new_node);
				this->head->SetPrev(new_node);
			}
		}
	}

	~CircularLinkedList() {
		int list_length = GetLength(this); 
		while (list_length != 0) {
			if (list_length == 1) {
				delete this->head;
				this->head = nullptr;
				return;
			}
			Node* temp_head_next = this->head->GetNext();
			Node* temp_head_prev = this->head->GetPrev();

			delete this->head;

			this->head = temp_head_next;
			this->head->SetPrev(temp_head_prev);
			temp_head_prev->SetNext(this->head);

			list_length = GetLength(this);
		}
	}

	void PrintList() {
		if (this->head == nullptr) {
			cout << "Empty List!";
			return;
		}

		if (this->head->GetNext() == nullptr || this->head->GetNext() == this->head) {
			cout << this->head->GetValue() << "\n";
			return;
		}

		Node* iterator = new Node(this->head);
		while (iterator->GetNext() != this->head) {
			cout << iterator->GetValue() << "->";
			iterator = iterator->GetNext();
			if (iterator->GetNext() == this->head)
				cout << iterator->GetValue() << "\n";
		}
	}

	int GetLength(CircularLinkedList<T>* list) { // Time complexity O(n^2)

		if (list == nullptr) // pointer is null
			return 0;

		if (list->head == nullptr) // list is empty
			return 0;
		
		if (list->head->GetNext() == nullptr) // only head in list
			return 1;

		list->head->SetValue(1);

		int steps = 1;
		while (list->head->GetValue() != 0) {
			int temp_steps = steps;
			while (temp_steps != 0) { // go steps times forward
				list->head->GetNext()->SetValue(0);
				list->head = list->head->GetNext();
				temp_steps--;
			}
			while (temp_steps != steps) { // go steps times backwards 
				list->head = list->head->GetPrev();
				temp_steps++;
			}
			steps++;
		}
		return steps - 1;
	}

};

