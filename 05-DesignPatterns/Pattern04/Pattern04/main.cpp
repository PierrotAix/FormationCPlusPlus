// Pattern04.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class Color {
public:
	virtual void accept(class Visitor*) = 0;
};

class Red : public Color {
public:
	void accept(Visitor*); 	// virtuelle 
	void eye() { cout << "Red::eye\n"; }
};

class Blu : public Color {
public:
	void accept(Visitor*);	// virtuelle 
	void sky() { cout << "Blu::sky\n"; }
};

class Visitor {

public:
	virtual void visit(Red*) = 0;
	virtual void visit(Blu*) = 0;
};

class CountVisitor : public Visitor {
private:
	int m_num_red;
	int m_num_blu;

public:
	CountVisitor() {
		m_num_red = 0;
		m_num_blu = 0;
	}

	void visit(Red*) { ++m_num_red; } // virtuelle 

	void visit(Blu*) { ++m_num_blu; } // virtuelle 

	void report_num() {
		cout << "Rapport final: Reds " << m_num_red << ", Blus " << m_num_blu << '\n';
	}
};

class CallVisitor : public Visitor {
public:
	void visit(Red* r) { // virtuelle 
		r->eye();
	}
	void visit(Blu* b) { // virtuelle 
		b->sky();
	}
};

void Red::accept(Visitor* v) { v->visit(this); }
void Blu::accept(Visitor* v) { v->visit(this); }

int main(void) {
	Color* set[] = { new Red, new Blu, new Blu, new Red, new Red, 0 };

	// transmettre à chaque objet du tableau set un objet CountVisitor
	// et un objet CallVisitor

	// appeler report_num sur l'objet CountVisitor
}




