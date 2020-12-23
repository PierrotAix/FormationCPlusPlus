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

// Cette classe est exportée à partir de la dll
class ROOTFINDER_API CRootFinder {
public:
	CRootFinder(void);
	double SquareRoot(double v);
	// TODO: ajoutez ici vos méthodes.
};

extern ROOTFINDER_API int nRootFinder;

ROOTFINDER_API int fnRootFinder(void);
