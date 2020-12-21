#include "stdafx.h"

#include <iostream>

#include "monDocument.h"

using namespace std;

MonDocument::MonDocument( const char* fn ) : Document(fn) { }

void MonDocument::Open()   { 
	cout << "   MonDocument: Open()" << endl; 
}

void MonDocument::Close()  { 
	cout << "   MonDocument: Close()" << endl; 
}
