#ifndef COMPILEOPTIONSBASE_H
#define COMPILEOPTIONSBASE_H

#include "settings.h"

/** Build configuration enum */
enum BuildConfiguration
{
	bcFromCompiler = 0, /**< Use compiler's build configuration */
	bcRelease, /**< "Release" build configuration */
	bcDebug /**< "Debug" build configuration */
};

/**
  * This is a base class for all classes needing compilation parameters. It
  * offers functions to get/set the following:\n
  * \li Compiler options
  * \li Linker options
  * \li Compiler include dirs
  * \li Linker include dirs
  * \li Custom commands to be executed before/after build
  * \li The settings modification status
  * \n\n
  * These settings are used by the compiler plugins to construct the necessary
  * compilation commands.
  */
class DLLIMPORT CompileOptionsBase
{
	public:
		CompileOptionsBase();
		virtual ~CompileOptionsBase();
		
		virtual void SetBuildConfiguration(const BuildConfiguration& bc);
		virtual const BuildConfiguration& GetBuildConfiguration();
		virtual void SetLinkerOptions(const wxArrayString& linkerOpts);
		virtual const wxArrayString& GetLinkerOptions();
		virtual void SetCompilerOptions(const wxArrayString& compilerOpts);
		virtual const wxArrayString& GetCompilerOptions();
		virtual void SetIncludeDirs(const wxArrayString& includeDirs);
		virtual const wxArrayString& GetIncludeDirs();
		virtual void SetLibDirs(const wxArrayString& libDirs);
		virtual const wxArrayString& GetLibDirs();
		virtual void SetCommandsBeforeBuild(const wxArrayString& commands);
		virtual const wxArrayString& GetCommandsBeforeBuild();
		virtual void SetCommandsAfterBuild(const wxArrayString& commands);
		virtual const wxArrayString& GetCommandsAfterBuild();
		virtual bool GetModified();
		virtual void SetModified(bool modified);
        virtual void AddLinkerOption(const wxString& option);
        virtual void AddCompilerOption(const wxString& option);
        virtual void AddIncludeDir(const wxString& option);
        virtual void AddLibDir(const wxString& option);
		virtual void AddCommandsBeforeBuild(const wxString& command);
		virtual void AddCommandsAfterBuild(const wxString& command);
		virtual bool GetCpp();
		virtual void SetCpp(bool cpp);
	protected:
		BuildConfiguration m_BuildConfiguration;
		wxArrayString m_LinkerOptions;
		wxArrayString m_CompilerOptions;
		wxArrayString m_IncludeDirs;
		wxArrayString m_LibDirs;
		wxArrayString m_CmdsBefore;
		wxArrayString m_CmdsAfter;
		bool m_Modified;
		bool m_Cpp;
	private:
};

#endif // COMPILEOPTIONSBASE_H

