/////////////////////////////////////////////////////////////////////////////
// cmdExposeSdk.cpp : command file
//

#include "StdAfx.h"
#include "ExposeSdkPlugIn.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN ExposeSdk command
//

#pragma region ExposeSdk command


// Do NOT put the definition of class CCommandExposeSdk in a header
// file.  There is only ONE instance of a CCommandExposeSdk class
// and that instance is the static theExposeSdkCommand that appears
// immediately below the class definition.

class CCommandExposeSdk : public CRhinoCommand
{
public:
  // The one and only instance of CCommandExposeSdk is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandExposeSdk::CCommandExposeSdk()
  // is called exactly once when static theExposeSdkCommand is created.
	CCommandExposeSdk() {}

  // CCommandExposeSdk::~CCommandExposeSdk()
  // is called exactly once when static theExposeSdkCommand is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CCommandExposeSdk() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
		// {DD6415F0-BA5E-47B4-9C74-FF2CBB988FE1}
    static const GUID ExposeSdkCommand_UUID =
    { 0xDD6415F0, 0xBA5E, 0x47B4, { 0x9C, 0x74, 0xFF, 0x2C, 0xBB, 0x98, 0x8F, 0xE1 } };
    return ExposeSdkCommand_UUID;
	}

  // Returns the English command name.
	const wchar_t* EnglishCommandName() { return L"ExposeSdk"; }

  // Returns the localized command name.
	const wchar_t* LocalCommandName() const { return L"ExposeSdk"; }

  // Rhino calls RunCommand to run the command.
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandExposeSdk object.  
// Do NOT create any other instance of a CCommandExposeSdk class.
static class CCommandExposeSdk theExposeSdkCommand;

CRhinoCommand::result CCommandExposeSdk::RunCommand( const CRhinoCommandContext& context )
{
  // CCommandExposeSdk::RunCommand() is called when the user runs the "ExposeSdk"
  // command or the "ExposeSdk" command is run by a history operation.

  // TODO: Add command code here.

  // Rhino command that display a dialog box interface should also support
  // a command-line, or scriptable interface.

  ON_wString wStr;
  wStr.Format( L"The \"%s\" command is under construction.\n", EnglishCommandName() );
  if( context.IsInteractive() )
    RhinoMessageBox( wStr, PlugIn()->PlugInName(), MB_OK );
  else
	  RhinoApp().Print( wStr );

  // TODO: Return one of the following values:
  //   CRhinoCommand::success:  The command worked.
  //   CRhinoCommand::failure:  The command failed because of invalid input, inability
  //                            to compute the desired result, or some other reason
  //                            computation reason.
  //   CRhinoCommand::cancel:   The user interactively canceled the command 
  //                            (by pressing ESCAPE, clicking a CANCEL button, etc.)
  //                            in a Get operation, dialog, time consuming computation, etc.

  return CRhinoCommand::success;
}

#pragma endregion

//
// END ExposeSdk command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
