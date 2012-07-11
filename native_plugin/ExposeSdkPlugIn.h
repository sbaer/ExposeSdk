/////////////////////////////////////////////////////////////////////////////
// ExposeSdkPlugIn.h : main header file for the ExposeSdk plug-in
//

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CExposeSdkPlugIn
// See ExposeSdkPlugIn.cpp for the implementation of this class
//

class CExposeSdkPlugIn : public CRhinoUtilityPlugIn
{
public:
  CExposeSdkPlugIn();
  ~CExposeSdkPlugIn();

  // Required overrides
  const wchar_t* PlugInName() const;
  const wchar_t* PlugInVersion() const;
  GUID PlugInID() const;
  BOOL OnLoadPlugIn();
  void OnUnloadPlugIn();

  // Online help overrides
  BOOL AddToPlugInHelpMenu() const;
  BOOL OnDisplayPlugInHelp( HWND hWnd ) const;

private:
  ON_wString m_plugin_version;

  // TODO: Add additional class information here
};

CExposeSdkPlugIn& ExposeSdkPlugIn();



