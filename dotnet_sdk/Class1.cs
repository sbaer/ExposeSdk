using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExposeSdkDotNet
{
  /// <summary>
  /// Used for connecting to the ExposeSdkPlugIn
  /// </summary>
  public class MyPlugInSdk
  {
    static MyPlugInSdk m_thesdk = null;
    bool m_plugin_loaded =false;

    /// <summary>
    /// Will return null if the ExposeSdk plug-in could not be connected to
    /// </summary>
    public static bool SdkTest(bool throwIfNotConnected)
    {
      if( m_thesdk==null )
      {
        m_thesdk = new MyPlugInSdk();
        Guid id = new Guid("07972F93-B8D9-49BB-93F7-8D94CA0F7EAD");
        m_thesdk.m_plugin_loaded = Rhino.PlugIns.PlugIn.LoadPlugIn(id);
      }

      if (m_thesdk.m_plugin_loaded)
        return true;

      if( throwIfNotConnected )
        throw new Exception("ExposeSdk Plug-In could not be loaded");

      return false;
    }
  }

  /// <summary>
  /// 
  /// </summary>
  public class Sample
  {
    readonly double m_x;
    readonly double m_y;
    readonly double m_z;

    /// <summary>
    /// 
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="z"></param>
    public Sample(double x, double y, double z)
    {
      m_x = x;
      m_y = y;
      m_z = z;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    public double Sum()
    {
      MyPlugInSdk.SdkTest(true);
      return UnsafeNativeMethods.Expose_AddThreeNumbers(m_x, m_y, m_z);
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="point"></param>
    /// <returns></returns>
    public Rhino.Geometry.Vector3d VectorTo(Rhino.Geometry.Point3d point)
    {
      MyPlugInSdk.SdkTest(true);
      Rhino.Geometry.Point3d from = new Rhino.Geometry.Point3d(m_x, m_y, m_z);
      Rhino.Geometry.Vector3d rc = new Rhino.Geometry.Vector3d();
      UnsafeNativeMethods.Expose_CreateVector(from, point, ref rc);
      return rc;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="doc"></param>
    /// <param name="redraw"></param>
    /// <returns></returns>
    public bool AddAsPointToDoc(Rhino.RhinoDoc doc, bool redraw)
    {
      MyPlugInSdk.SdkTest(true);
      return UnsafeNativeMethods.Expose_AddPoint(doc.DocumentId, new Rhino.Geometry.Point3d(m_x, m_y, m_z), redraw);
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="curve"></param>
    /// <returns></returns>
    public static double CurveLength(Rhino.Geometry.Curve curve)
    {
      MyPlugInSdk.SdkTest(true);
      IntPtr pCurve = Rhino.Runtime.Interop.NativeGeometryConstPointer(curve);
      return UnsafeNativeMethods.Expose_CurveLength(pCurve);
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"></param>
    public static void SayHello(string name)
    {
      MyPlugInSdk.SdkTest(true);
      UnsafeNativeMethods.Expose_PrependHello(name);
    }

  }
}
