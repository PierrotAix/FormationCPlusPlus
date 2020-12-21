#include "stdafx.h"

#include "monApplication.h"
#include "monDocument.h"

MonApplication::MonApplication() { 
	//cout << "MonApplication: GDF" << endl; 
}

MonApplication::MonApplication(const string& n):Application(n){
}

Document* MonApplication::CreateDocument( const char* fn ) {
	cout << "   MonApplication: CreateDocument()" << endl;
	return new MonDocument( fn );
}
