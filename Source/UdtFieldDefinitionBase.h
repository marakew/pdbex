#pragma once
#include "PDB.h"

#include <string>

class UdtFieldDefinitionBase
{
public:
	virtual	void VisitBaseType(const SYMBOL* Symbol) {}

	virtual void VisitTypedefTypeBegin(const SYMBOL* Symbol) {}
	virtual	void VisitTypedefTypeEnd(const SYMBOL* Symbol) {}

	virtual	void VisitEnumType(const SYMBOL* Symbol) {}
	virtual	void VisitUdtType(const SYMBOL* Symbol) {}

	virtual void VisitPointerTypeBegin(const SYMBOL* Symbol) {}
	virtual	void VisitPointerTypeEnd(const SYMBOL* Symbol) {}

	virtual	void VisitArrayTypeBegin(const SYMBOL* Symbol) {}
	virtual	void VisitArrayTypeEnd(const SYMBOL* Symbol) {}

	virtual	void VisitFunctionTypeBegin(const SYMBOL* Symbol) {}
	virtual	void VisitFunctionTypeEnd(const SYMBOL* Symbol) {}

	virtual	void VisitFunctionArgTypeBegin(const SYMBOL* Symbol) {}
	virtual void VisitFunctionArgTypeEnd(const SYMBOL* Symbol) {}

	virtual	void SetMemberName(const CHAR* MemberName) {}

	virtual	std::string GetPrintableDefinition() const { return std::string(); }
};
