#include "stdafx.h"

#include "application.h"
#include <iostream>

using namespace std;

Application::Application() : _index(0) { 
	cout << "Application: anonyme" << endl; 
}

Application::Application(const string& n) : name(n),_index(0) { 
	cout << "Application: "<<name << endl; 
}

	
void Application::NewDocument( const char* name )  {
		cout << "Application: NewDocument " <<name<< endl;
		_docs[_index] = CreateDocument( name );
		_docs[_index++]->Open(); 
}
	
void Application::OpenDocument()  {cout<<"ouverture du document: "<<endl; }

void Application::ReportDocs(){ };
