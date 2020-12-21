#include "stdafx.h"

#include <cstring>

#include "Document.h"

Document::Document( const char* fn ) { strcpy( name, fn ); }

char* Document::GetName(){ return name; }
