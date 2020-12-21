#ifndef MONDOCUMENT_H
#define MONDOCUMENT_H

#include "document.h"

class DocumentXML : public Document {
public:
	DocumentXML(const char* fn);

	void Open();

	void Close();
};
#endif
