#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct node {
	unsigned int power;
	double coefficient;
	node* next;
};

typedef node* node_ptr;

node_ptr create_term();
node_ptr create_term(unsigned int, double);
void add_term(node_ptr&, node_ptr);
void delete_polynomial(node_ptr&);
node_ptr sum(node_ptr, node_ptr);
node_ptr product(node_ptr, node_ptr);
void print(node_ptr);

int main(void) {
	node_ptr principal_polynomial = NULL, secondary_polynomial = NULL, resultant_polynomial = NULL;
	char choice; int n;

	cout << "--> Polynomial World <--";

	while (true) {
		cout << "\n1. Add polynomial terms to principal polynomial\n2. Add polynomial to principal polynomial\n3. Multiply polynomial by principal polynomial\n4. Clear principal polynomial\n5. Print principal polynomial\nAny other key to exit..." << endl;

		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			cout << "Enter number of terms to add: ";
			cin >> n;
			for (int i = 0; i < n; i++) add_term(principal_polynomial, create_term());
			break;

		case '2':
			cout << "Enter number of terms of secondary polynomial: ";
			cin >> n;

			for (int i = 0; i < n; i++) add_term(secondary_polynomial, create_term());

			resultant_polynomial = sum(principal_polynomial, secondary_polynomial);

			cout << endl << "Result: ";
			print(resultant_polynomial);

			delete_polynomial(secondary_polynomial);
			delete_polynomial(resultant_polynomial);
			break;

		case '3':
			cout << "Enter number of terms of secondary polynomial: ";
			cin >> n;

			for (int i = 0; i < n; i++) add_term(secondary_polynomial, create_term());

			resultant_polynomial = product(principal_polynomial, secondary_polynomial);

			cout << endl << "Result: ";
			print(resultant_polynomial);

			delete_polynomial(secondary_polynomial);
			delete_polynomial(resultant_polynomial);
			break;

		case '4':
			delete_polynomial(principal_polynomial);
			break;

		case '5':
			print(principal_polynomial);
			break;

		default:
			return 0;
		}
	}
	return 0;
}

node_ptr create_term() {
	node_ptr term = new node;
	cout << endl << "Enter coefficient: ";
	cin >> term->coefficient;

	cout << "Enter power: ";
	cin >> term->power;

	term->next = NULL;

	return term;
}

node_ptr create_term(unsigned int power, double coefficient) {
	node_ptr term = new node;

	term->power = power;
	term->coefficient = coefficient;
	term->next = NULL;

	return term;
}

void add_term(node_ptr& head, node_ptr term) {
	if (head == NULL) {
		head = term;
	}
	else if (head->power == term->power) {
		head->coefficient += term->coefficient;
		delete term;
		if (head->coefficient == 0) {
			node_ptr p = head;
			head = head->next;
			delete p;
		}
	}
	else if (head->power > term->power) {
		term->next = head;
		head = term;
	}
	else {
		add_term(head->next, term);
	}
}

void delete_polynomial(node_ptr& head) {
	node_ptr p;
	while (head != NULL) {
		p = head;
		head = head->next;
		delete p;
	}
}

node_ptr sum(node_ptr poly1, node_ptr poly2) {
	node_ptr poly_res = NULL;

	while (poly1 != NULL && poly2 != NULL) {
		if (poly1->power < poly2->power) {
			add_term(poly_res, create_term(poly1->power, poly1->coefficient));
			poly1 = poly1->next;
		}
		else if (poly1->power > poly2->power) {
			add_term(poly_res, create_term(poly2->power, poly2->coefficient));
			poly2 = poly2->next;
		}
		else {
			node_ptr term = create_term(poly1->power, poly1->coefficient + poly2->coefficient);
			if (term->coefficient) {
				add_term(poly_res, term);
			}
			else {
				delete term;
			}
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
	}

	while (poly1 != NULL) {
		add_term(poly_res, create_term(poly1->power, poly1->coefficient));
		poly1 = poly1->next;
	}

	while (poly2 != NULL) {
		add_term(poly_res, create_term(poly2->power, poly2->coefficient));
		poly2 = poly2->next;
	}

	return poly_res;
}

node_ptr product(node_ptr poly1, node_ptr poly2) {
	node_ptr p = poly2;
	node_ptr poly_res = NULL;

	if (poly1 == NULL) return poly2;
	if (poly2 == NULL) return poly1;

	while (poly1 != NULL) {
		poly2 = p;
		while (poly2 != NULL) {
			add_term(poly_res, create_term(poly1->power + poly2->power, poly1->coefficient * poly2->coefficient));
			poly2 = poly2->next;
		}
		poly1 = poly1->next;
	}

	return poly_res;
}

void print(node_ptr head) {
	cout << endl;

	if (head == NULL) cout << "Empty polynomial...";

	while (head != NULL) {
		cout << head->coefficient << "x^" << head->power;
		if (head->next != NULL) cout << " + ";
		head = head->next;
	}
	cout << endl;
}
