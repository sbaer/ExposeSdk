#include "stdafx.h"

// V4 docs do not have runtime serial sumbers. Keep a small
// list (~8) of docs with an incrementing serial number
struct CTrackedDoc
{
  CRhinoDoc* m_pDoc;
  int m_serial_number;
};
static int m_nextdoc_serial_number = 1;
static ON_SimpleArray<CTrackedDoc> m_all_docs;



CRhinoDoc* RhDocFromId( int doc_id )
{
#if defined(RHINO_V5SR)
  // GetDocument should be fixed, but I need to chat with Dale Lear first about this
  CRhinoDoc* pDoc = RhinoApp().GetDocument((unsigned int)doc_id);
  INT_PTR p = (INT_PTR)pDoc;
  if( p<1000 )
    pDoc = NULL;
  return pDoc;
#else
  for( int i=0; i<m_all_docs.Count(); i++ )
  {
    CTrackedDoc td = m_all_docs[i];
    if( td.m_serial_number==doc_id )
      return td.m_pDoc;
  }
  return RhinoApp().ActiveDoc();
#endif
}

int RhIdFromDoc( CRhinoDoc* pDoc )
{
  if( NULL==pDoc )
    return 0;
#if defined(RHINO_V5SR)
  return (int)(pDoc->m_runtime_doc_serial_number);
#else
  for( int i=0; i<m_all_docs.Count(); i++ )
  {
    CTrackedDoc tracked = m_all_docs[i];
    if( tracked.m_pDoc == pDoc )
      return tracked.m_serial_number;
  }
  //didn't find a doc in the list
  CTrackedDoc td;
  td.m_pDoc = pDoc;
  td.m_serial_number = m_nextdoc_serial_number++;
  m_all_docs.Append(td);
  if( m_all_docs.Count()>8 )
    m_all_docs.Remove(0);

  return td.m_serial_number;
#endif
}

void CopyToPlaneStruct(ON_PLANE_STRUCT& ps, const ON_Plane& plane)
{
  memcpy(&ps, &plane, sizeof(ON_PLANE_STRUCT));
}

ON_Plane FromPlaneStruct(const ON_PLANE_STRUCT& ps)
{
  ON_Plane plane;
  memcpy(&plane, &ps, sizeof(ON_PLANE_STRUCT));
  plane.UpdateEquation();
  return plane;
}

void CopyToCircleStruct(ON_CIRCLE_STRUCT& cs, const ON_Circle& circle)
{
  memcpy(&cs, &circle, sizeof(ON_CIRCLE_STRUCT));
}

ON_Circle FromCircleStruct(const ON_CIRCLE_STRUCT& cs)
{
  ON_Circle circle;
  memcpy(&circle, &cs, sizeof(ON_CIRCLE_STRUCT));
  circle.plane.UpdateEquation();
  return circle;
}

unsigned int ARGB_to_ABGR( unsigned int argb )
{
  // ON_Color defines alpha=0 as opaque where System.Drawing.Color defines alpha=255 as opaque
  // This function is for converting from System.Drawing.Color to ON_Color
  unsigned int alpha = (argb & 0xff000000)>>24;
  alpha = (255-alpha);
  unsigned int abgr = (alpha)<<24 | (argb & 0x000000ff)<<16 | (argb & 0x0000ff00) | (argb & 0x00ff0000)>>16;
  return abgr;
}
unsigned int ABGR_to_ARGB( unsigned int abgr )
{
  // ON_Color defines alpha=0 as opaque where System.Drawing.Color defines alpha=255 as opaque
  // This function is for converting from ON_Color to System.Drawing.Color
  unsigned int alpha = (abgr & 0xff000000)>>24;
  alpha = (255-alpha);
  unsigned int argb = (alpha)<<24 | (abgr & 0x000000ff)<<16 | (abgr & 0x0000ff00) | (abgr & 0x00ff0000)>>16;
  return argb;
}



///////////// StringHolder

CRhCmnStringHolder::CRhCmnStringHolder()
{
#if defined(__APPLE__)
  m_macString = NULL;
#endif
}

CRhCmnStringHolder::~CRhCmnStringHolder()
{
#if defined(__APPLE__)
  if( NULL!=m_macString )
    free(m_macString);
#endif
}

void CRhCmnStringHolder::Set(const ON_wString& s)
{
#if defined(__APPLE__)
  if( NULL!=m_macString )
  {
    free(m_macString);
    m_macString = NULL;
  }
  
  const wchar_t* inStr = s.Array();
  if( inStr != NULL )
  {
    int strLen = s.Length();
    m_macString = (UniChar*) calloc (sizeof(UniChar), strLen+1);
    for (int i=0; i<strLen; i++)
      m_macString[i] = inStr[i];
  }
#else
  m_winString = s;
#endif
}

const RHMONO_STRING* CRhCmnStringHolder::Array() const
{
#if defined(__APPLE__)
  return m_macString;
#else
  return m_winString.Array();
#endif
}

