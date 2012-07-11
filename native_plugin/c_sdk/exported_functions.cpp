#include "stdafx.h"
#include "../rhcommon_c/rhcommon_c_api.h"

// All of the functions in this file are decorated with RH_C_FUNCTION which means
// that they are exported "C" style functions.  The methodgen application is run
// on the directory that this file is in to generate a AutoNativeMethods.cs file.

// Sample 1 - A basic function
RH_C_FUNCTION double Expose_AddThreeNumbers( double x, double y, double z )
{
  double rc = x+y+z;
  return rc;
}

// Sample 2 - Use simple opennurbs types
RH_C_FUNCTION bool Expose_CreateVector( ON_3DPOINT_STRUCT from, ON_3DPOINT_STRUCT to, ON_3dVector* result )
{
  bool rc = false;
  if( result )
  {
    ON_3dPoint _from(from.val);
    ON_3dPoint _to(to.val);
    *result = _to - _from;
    rc = true;
  }
  return rc;
}

// Sample 3 - Use OpenNURBS geometry
RH_C_FUNCTION double Expose_CurveLength( const ON_Curve* pConstCurve )
{
  double rc = 0;
  if( pConstCurve )
    pConstCurve->GetLength(&rc);
  return rc;
}

// Sample 4 - Work with the CRhinoDoc
RH_C_FUNCTION bool Expose_AddPoint( int doc_id, ON_3DPOINT_STRUCT point, bool redraw )
{
  CRhinoDoc* doc = RhDocFromId(doc_id);
  if( NULL==doc )
    return false;
  doc->AddPointObject(ON_3dPoint(point.val));
  if( redraw )
    doc->Redraw();
  return true;
}

// Sample 5 - Work with strings
RH_C_FUNCTION void Expose_PrependHello( const RHMONO_STRING* str )
{
  INPUTSTRINGCOERCE( _str, str);
  if( _str )
  {
    RhinoApp().Print(L"Hello ");
    RhinoApp().Print(_str);
    RhinoApp().Print(L"\n");
  }
}

