// Pattern05.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include <iostream>
using namespace std;


class RealImage {
	int m_id;

public:
	RealImage(int i) {
		m_id = i;
		cout << " construction RealImage: " << m_id << endl;
	}
	~RealImage() {
		cout << " destruction RealImage: " << m_id << endl;
	}
	void draw() {
		cout << " drawing RealImage " << m_id << endl;
	}
};

class Image {
	RealImage* m_the_real_thing;
	int m_id;
	static int s_next;

public:
	Image() {
		m_the_real_thing = 0;
		m_id = s_next++; // Initialis� � null m_the_real_thing = 0;
	}

	~Image() {
		delete m_the_real_thing;
	}

	void draw() {
		// A COMPLETER
	}
};

int Image::s_next = 1;

int main(void) {
	Image images[5];
	for (int i; true; ) {
		cout << "numero d'Image[1-5](0 pour sortir): ";
		cin >> i;
		if (i>5) continue;
		if (i == 0) break;
		images[i - 1].draw();
	}
}
