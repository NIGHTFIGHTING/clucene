/*------------------------------------------------------------------------------
* Copyright (C) 2003-2006 Ben van Klinken and the CLucene Team
* 
* Distributable under the terms of either the Apache License (Version 2.0) or 
* the GNU Lesser General Public License, as specified in the COPYING file.
------------------------------------------------------------------------------*/
#ifndef _lucene_store_MMap_
#define _lucene_store_MMap_

#include "IndexInput.h"

CL_NS_DEF(store)

	class MMapIndexInput: public IndexInput{
		class Internal;
		Internal* _internal;

		MMapIndexInput(const MMapIndexInput& clone);
	public:
		MMapIndexInput(const char* path);
		~MMapIndexInput();
		IndexInput* clone() const;

		inline uint8_t readByte();
		int32_t readVInt();
		void readBytes(uint8_t* b, const int32_t len);
		void close();
		int64_t getFilePointer() const;
		void seek(const int64_t pos);
		int64_t length() const;

		const char* getObjectName(){ return MMapIndexInput::getClassName(); }
		static const char* getClassName(){ return "MMapIndexInput"; }			
	};
CL_NS_END
#endif
