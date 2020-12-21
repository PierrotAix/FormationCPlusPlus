#ifndef MONAPPLICATION_H
#define MONAPPLICATION_H

#include <iostream>
#include "Application.h"

using namespace std;

/* Customization of framework defined by client */
class MonApplication : public Application {

  public:
	MonApplication();

	MonApplication(const string& n);
	
	Document* CreateDocument( const char* fn );

};
#endif
