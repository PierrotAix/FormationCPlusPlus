// Pattern02.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include "MonApplication.h"
#include "applicationXML.h"

int main() {

	Application* app = nullptr;
	Document* doc = nullptr;
	
	app = new MonApplication("Standard");
	doc = app->CreateDocument("alpha");
	doc->Open();
	doc->Close();

	app = new ApplicationXML("XML");
	doc = app->CreateDocument("gamma");
	doc->Open();
	doc->Close();

	return 0;
}

