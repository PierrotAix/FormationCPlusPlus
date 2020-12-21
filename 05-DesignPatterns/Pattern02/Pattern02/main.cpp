// Pattern02.cpp : définit le point d'entrée pour l'application console.
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

