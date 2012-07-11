using System;
using Rhino.Geometry;
using System.Runtime.InteropServices;
//
// good marshalling webpage
// http://msdn.microsoft.com/en-us/library/aa288468(VS.71).aspx
//
//

class Import
{
  public const string lib = "ExposeSdk.rhp";
  private Import() { }
}

// 19 Dec. 2010 S. Baer
// Giulio saw a significant performance increase by marking this class with the
// SuppressUnmanagedCodeSecurity attribute. See MSDN for details
[System.Security.SuppressUnmanagedCodeSecurity]
internal partial class UnsafeNativeMethods
{
  // Add native methods here that are not part of the Auto-generation process
}
