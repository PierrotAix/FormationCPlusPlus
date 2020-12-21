#include "stdafx.h"

#include "applicationXML.h"
#include "documentXML.h"


using namespace std;

ApplicationXML::ApplicationXML() {
	cout << "Application XML" << endl;
}

ApplicationXML::ApplicationXML(const string& n) :Application(n) {
	cout << "Application XML" << endl;
}

Document* ApplicationXML::CreateDocument(const char* fn) {
	cout << "   ApplicationXML: CreateDocument()" << endl;
	return new DocumentXML(fn);
}
