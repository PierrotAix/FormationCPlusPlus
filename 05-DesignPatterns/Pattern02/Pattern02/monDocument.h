#ifndef MONDOCUMENT_H
#define MONDOCUMENT_H

#include "document.h"

class MonDocument : public Document {
public:
	MonDocument( const char* fn );
	
	void Open();

	void Close();
};
#endif
