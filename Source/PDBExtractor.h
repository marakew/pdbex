#pragma once
#include "PDBSymbolSorterBase.h"
#include "PDBHeaderReconstructor.h"
#include "PDBSymbolVisitor.h"
#include "UdtFieldDefinition.h"

#include <memory>
#include <string>

class PDBExtractor
{
public:
	struct Settings
	{
		PDBHeaderReconstructor::Settings PdbHeaderReconstructorSettings;
		UdtFieldDefinition::Settings UdtFieldDefinitionSettings;

		std::string SymbolName;
		std::string PdbPath;

		const char* OutputFilename = nullptr;

		bool PrintReferencedTypes = true;
		bool PrintHeader = true;
		bool PrintDeclarations = true;
		bool PrintDefinitions = true;
		bool PrintFunctions = false;
		bool PrintPragmaPack = true;
		bool Sort = false;
	};

	int Run(int argc, char** argv);

private:
	void PrintUsage();
	void ParseParameters(int argc, char** argv);
	void OpenPDBFile();
	void PrintPDBHeader();
	void PrintPDBDeclarations();
	void PrintPDBDefinitions();
	void PrintPDBFunctions();
	void DumpAllSymbols();
	void DumpOneSymbol();
	void DumpAllSymbolsOneByOne();
	void CloseOpenFiles();

private:
	PDB m_PDB;
	Settings m_Settings;

	std::unique_ptr<PDBSymbolSorterBase> m_SymbolSorter;
	std::unique_ptr<PDBHeaderReconstructor> m_HeaderReconstructor;
	std::unique_ptr<PDBSymbolVisitor<UdtFieldDefinition>> m_SymbolVisitor;
};
