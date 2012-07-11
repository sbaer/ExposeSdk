// !!!DO NOT EDIT THIS FILE BY HAND!!!
// Create this file by running MethodGen.exe in the rhinocommon directory
// MethodGen.exe parses the cpp files in rhcommon_c to create C# callable
// function declarations

using System;
using System.Runtime.InteropServices;
using Rhino;
using Rhino.Geometry;
using Rhino.Geometry.Intersect;
using Rhino.Collections;
using Rhino.Display;

// Atuomatically generated function declarations for calling into
// the support 'C' DLL (rhcommon_c.dll).
internal partial class UnsafeNativeMethods
{
  private UnsafeNativeMethods(){}
  #region exported_functions.cpp
  //double Expose_AddThreeNumbers( double x, double y, double z )
  [DllImport(Import.lib, CallingConvention=CallingConvention.Cdecl )]
  internal static extern double Expose_AddThreeNumbers(double x, double y, double z);

  //bool Expose_CreateVector( ON_3DPOINT_STRUCT from, ON_3DPOINT_STRUCT to, ON_3dVector* result )
  [DllImport(Import.lib, CallingConvention=CallingConvention.Cdecl )]
  [return: MarshalAs(UnmanagedType.U1)]
  internal static extern bool Expose_CreateVector(Point3d from, Point3d to, ref Vector3d result);

  //double Expose_CurveLength( const ON_Curve* pConstCurve )
  [DllImport(Import.lib, CallingConvention=CallingConvention.Cdecl )]
  internal static extern double Expose_CurveLength(IntPtr pConstCurve);

  //bool Expose_AddPoint( int doc_id, ON_3DPOINT_STRUCT point, bool redraw )
  [DllImport(Import.lib, CallingConvention=CallingConvention.Cdecl )]
  [return: MarshalAs(UnmanagedType.U1)]
  internal static extern bool Expose_AddPoint(int doc_id, Point3d point, [MarshalAs(UnmanagedType.U1)]bool redraw);

  //void Expose_PrependHello( const RHMONO_STRING* str )
  [DllImport(Import.lib, CallingConvention=CallingConvention.Cdecl )]
  internal static extern void Expose_PrependHello([MarshalAs(UnmanagedType.LPWStr)]string str);
  #endregion


}