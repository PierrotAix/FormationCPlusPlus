#include "stdafx.h"

#include "monApplication.h"
#include "monDocument.h"

MonApplication::MonApplication() { 
	cout << "MonApplication" << endl; 
}

MonApplication::MonApplication(const string& n):Application(n){
	cout << "MonApplication" << endl;
}

Document* MonApplication::CreateDocument( const char* fn ) {
	cout << "   MonApplication: CreateDocument()" << endl;
	return new MonDocument( fn );
}
