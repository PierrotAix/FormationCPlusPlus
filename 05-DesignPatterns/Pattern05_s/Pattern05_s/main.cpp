// Pattern05_s.cpp : définit le point d'entrée pour l'application console.
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
		m_id = s_next++; // Initialisé à null m_the_real_thing = 0;
	}

	~Image() {
		delete m_the_real_thing;
	}

	void draw() {
		// création de l'objet réel au premier appel
		if (m_the_real_thing == 0) {
			m_the_real_thing = new RealImage(m_id);
		}
		m_the_real_thing->draw();// l'appel est relayé
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
