#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>

class Document {
public:
	Document( const char* fn );
	virtual void Open()  = 0;
	virtual void Close() = 0;
	char* GetName();
private:
	char  name[20];
};

#endif
