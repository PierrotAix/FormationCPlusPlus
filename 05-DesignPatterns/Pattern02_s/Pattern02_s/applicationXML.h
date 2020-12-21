#ifndef APPLICATIONXML_H
#define APPLICATIONXML_H

#include <iostream>
#include "Application.h"
#include "documentXML.h"

using namespace std;

/* Customization of framework defined by client */
class ApplicationXML : public Application {

public:
	ApplicationXML();

	ApplicationXML(const string& n);

	Document* CreateDocument(const char* fn);

};
#endif
