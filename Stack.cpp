#include<pch.h> 
#include<iostream> 
#include<string>

using namespace std;

class Stack {
private:
	int top; //index of top of the stack
	int arr[10]; //array used for stack with size 10

public:
	Stack() {
		top = -1; // first position in array is 0 so we want to start from -1 not from 0 to make sure we get that 0 position
		for (int i = 0; i < 10; i++) {
			arr[i] = 0;
		}
	}

	bool isEmpty() {
		if (top == -1) // if top is equal -1 return stack is empty
			return true;
		else
			return false;
	}
	bool isFull() {
		if (top == 9) //if top is equal 9 return stack is full
			return true;
		else
			return false;
	}

	void push(int val) { //want to push integer into stack so function won't return anything that's why it's void 
		if (isFull()) {
			cout << "stack is full" << endl; // if stack is full print that is full and forbbiden pushing
		}
		else {
			top++; // increment top to next index
			arr[top] = val; //assign arr[next index] to value we have entered
		}
	}

	int pop() { // check specific stack value
		if (isEmpty()) {
			cout << "stack is empty" << endl; // if stack is empty print that is empty and forbbiden showing
			return 0;
		}
		else {
			int popValue = arr[top]; //
			arr[top] = 0;
			top--;
			return popValue;
		}
	}

	int count() { //count stack number of elements
		return (top + 1);
	}

	int peek(int pos) { //check stack on index position
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return 0;
		}
		else {
			return arr[pos];
		}
	}

	void change(int pos, int val) { //give new value to position
		arr[pos] = val;
		cout << "value changed at location " << pos << endl;
	}

	void display() { //show all of the stack values
		cout << "All values in the Stack are " << endl;
		for (int i = 9; i >= 0; i--) {
			cout << arr[i] << endl;
		}
	}
};

int main() {
	Stack s1; //initialize stack using OOP
	int option, postion, value;

	do {
		cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. Push()" << endl;
		cout << "2. Pop()" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. isFull()" << endl;
		cout << "5. Peek()" << endl;
		cout << "6. Count()" << endl;
		cout << "7. Change()" << endl;
		cout << "8. Display()" << endl;
		cout << "9. Clear Screen" << endl << endl;

		cin >> option;
		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Enter value to push " << endl;
			cin >> value;
			s1.push(value);
			break;
		case 2:
			cout << "Pop Function Called - Poped Value: " << s1.pop() << endl;
			break;
		case 3:
			if (s1.isEmpty())
				cout << "Stack is Empty" << endl;
			else
				cout << "Stack is not Empty" << endl;
			break;
		case 4:
			if (s1.isFull())
				cout << "Stack is Full" << endl;
			else
				cout << "Stack is not Full" << endl;
			break;
		case 5:
			cout << "Enter position of item you want to peek: " << endl;
			cin >> postion;
			cout << "Peek Function Called - Value at position " << postion << " is " << s1.peek(postion) << endl;
			break;
		case 6:
			cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
			break;
		case 7:
			cout << "Change Function Called - " << endl;
			cout << "Enter position of item you want to change : ";
			cin >> postion;
			cout << endl;
			cout << "Enter value of item you want to change : ";
			cin >> value;
			s1.change(postion, value);
			break;
		case 8:
			cout << "Display Function Called - " << endl;
			s1.display();
			break;
		case 9:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
}