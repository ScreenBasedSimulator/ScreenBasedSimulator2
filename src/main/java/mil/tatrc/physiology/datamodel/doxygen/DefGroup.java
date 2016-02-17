/*****************************************************************************
**
**        THIS MATERIAL MAY BE REPRODUCED BY OR FOR THE U.S. GOVERNMENT
**  PURSUANT TO THE COPYRIGHT LICENSE UNDER THE CLAUSE AT DFARS 252.227-7014.
**  COPYRIGHT(C)2015, APPLIED RESEARCH ASSOCIATES, INC., ALL RIGHTS RESERVED.
**
*****************************************************************************/
package mil.tatrc.physiology.datamodel.doxygen;

/**
 * 
 */
public class DefGroup
{
  public String fullName;
  public String bareName;
  public String printableName;
  
  @Override
  public String toString()
  {
    return "@defgroup "+fullName+" "+printableName;
  }
}
