// Le bloc ifdef suivant est la façon standard de créer des macros qui facilitent l'exportation
// à partir d'une DLL plus simple. Tous les fichiers contenus dans cette DLL sont compilés avec le symbole ROOTFINDER_EXPORTS
// défini sur la ligne de commande. Ce symbole ne doit pas être défini pour un projet
// qui utilise cette DLL. Ainsi, les autres projets dont les fichiers sources comprennent ce fichier considèrent les fonctions
// ROOTFINDER_API comme étant importées à partir d'une DLL, tandis que cette DLL considère les symboles
// définis avec cette macro comme étant exportés.


#ifdef ROOTFINDER_EXPORTS
#define ROOTFINDER_API __declspec(dllexport)
#else
#define ROOTFINDER_API __declspec(dllimport)
#endif

#include <string>
#include <string>
using namespace std;

// Cette classe est exportée à partir de la dll
class ROOTFINDER_API CRootFinder {
public:
	CRootFinder(void);
	double SquareRoot(double v);

	// Fait une addition de deux doubles.
	double Addition(double p1, double p2);

	/// Make one line if the pKeyWord is found in the file pBasePath\pRelativePath.
	/// The search uses byte to deal with any type of files.
	string GetLine(string pHeading, string pKeyWord, string pBasePath, string pRelativePath, string pChecksum);

	// read a file into memory http://www.cplusplus.com/reference/istream/istream/read/
	// and return le number of characters read
	int GetNumberOfCharactersOfFile(string pFileName);


	int GetNumberOfCharactersOfFile(string pBasePath, string pRelativePath);
	
};

extern ROOTFINDER_API int nRootFinder;

ROOTFINDER_API int fnRootFinder(void);
