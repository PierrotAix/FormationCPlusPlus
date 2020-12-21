#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
using namespace std;
#include "document.h"

/* Framework declaration */
class Application {
  private:
	int        _index;
	Document*  _docs[10];

protected:
	string name;
  
  public:
	Application();

	Application(const string& n); 
	
	void NewDocument( const char* name );
	
	void OpenDocument();
	
	void ReportDocs();
	
	virtual Document* CreateDocument( const char* ) = 0;

};

#endif
