/*****************************************************************************
**
**        THIS MATERIAL MAY BE REPRODUCED BY OR FOR THE U.S. GOVERNMENT
**  PURSUANT TO THE COPYRIGHT LICENSE UNDER THE CLAUSE AT DFARS 252.227-7014.
**  COPYRIGHT(C)2015, APPLIED RESEARCH ASSOCIATES, INC., ALL RIGHTS RESERVED.
**
*****************************************************************************/
package mil.tatrc.physiology.datamodel.doxygen;

import java.util.HashSet;

/**
 * XSD elements that can carry documentation
 */
public enum XSDType
{
  SCHEMA("schema"),
  ELEMENT("element"),
  COMPLEXTYPE("complexType"),
  SIMPLETYPE("simpleType"),
  ATTRIBUTE("attribute"),
  ENUMERATION("enumeration");
  
  private String xsdTypeName;
  private static HashSet<String> typeNames = new HashSet<String>();
  
  private XSDType(String typeName)
  {
    xsdTypeName = typeName;
  }
  
  public String getTypeName()
  {
    return xsdTypeName;
  }
  
  /**
   * Returns true if the XSD element type is a documentable type
   * @param typeName
   * @return
   */
  public static boolean isDocType(String typeName)
  {
    if (typeNames.isEmpty())
    {
      for (XSDType type : values())
      {
        typeNames.add(type.getTypeName());
      }
    }
    return typeNames.contains(typeName);
  }
}
