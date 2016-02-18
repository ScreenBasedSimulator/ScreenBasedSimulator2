/*****************************************************************************
**
**        THIS MATERIAL MAY BE REPRODUCED BY OR FOR THE U.S. GOVERNMENT
**  PURSUANT TO THE COPYRIGHT LICENSE UNDER THE CLAUSE AT DFARS 252.227-7014.
**  COPYRIGHT(C)2015, APPLIED RESEARCH ASSOCIATES, INC., ALL RIGHTS RESERVED.
**
*****************************************************************************/
package mil.tatrc.physiology.datamodel.doxygen;

/**
 * Captures the description elements for a particular data type
 */
public class Description
{
  /** Fully qualified reference to the base class name (if this is an extension type) */
  public String base = "";
  /** Description from doxygen text */
  public String desc = "";
  /** Fully qualified reference type */
  public String ref = "";
  /** minOccurs and maxOccurs */
  public String minMaxOccurs = "";
  
  @Override
  public String toString()
  {
    if (base.length() > 0 || ref.length() > 0 || minMaxOccurs.length() > 0)
    {
      String extendsText = "";
      String refText = "";
      String minMaxOccursText = "";
      
      if (base.length() > 0)
      {
        extendsText = "<br/>(Extends @ref "+base+")";
      }
      if (ref.length() > 0)
      {
        refText = "<br/>(Type @ref "+ref+")";
      }
      if (minMaxOccurs.length() > 0)
      {
        minMaxOccursText = "<br/>("+minMaxOccurs+")";
      }
      
      return desc+refText+extendsText+minMaxOccursText;
    }
    return desc;
  }
}
