// Pattern02.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"

#include "MonApplication.h"

int main() {
	MonApplication  monApp("GDF");

	monApp.NewDocument("alpha");
	monApp.NewDocument("beta");
	monApp.ReportDocs();

	return 0;
}

