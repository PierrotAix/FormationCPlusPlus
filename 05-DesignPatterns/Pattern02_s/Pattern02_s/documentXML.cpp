#include "stdafx.h"

#include <iostream>

#include "documentXML.h"

using namespace std;

DocumentXML::DocumentXML(const char* fn) : Document(fn) { }

void DocumentXML::Open() {
	cout << "   DocumentXML: Open()" << endl;
}

void DocumentXML::Close() {
	cout << "   DocumentXML: Close()" << endl;
}
