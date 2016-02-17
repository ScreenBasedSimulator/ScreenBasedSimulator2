/*
 *        THIS MATERIAL MAY BE REPRODUCED BY OR FOR THE U.S. GOVERNMENT
 *  PURSUANT TO THE COPYRIGHT LICENSE UNDER THE CLAUSE AT DFARS 252.227-7013.
 *  COPYRIGHT (C) 2008, APPLIED RESEARCH ASSOCIATES, INC., ALL RIGHTS RESERVED.
 */

package mil.tatrc.physiology.utilities;

import java.io.Serializable;

/**
 * The <code>Pair</code> contains two objects, paired together
 */
public class Pair<L,R> implements Serializable
{
  private L l;
  private R r;
  
  public Pair(L l, R r)
  { 
    this.l = l;
    this.r = r;   
  }
  
  @Override
  public boolean equals(Object o)
  {
    if (o == null || o.getClass() != getClass())
    {
      return false;
    }
    else
    {
      @SuppressWarnings("unchecked")
      Pair<L,R> in = (Pair<L,R>)o;
      if (!this.getL().equals(in.getL()) || !this.getR().equals(in.getR()))
      {
        return false;
      }
    }
      
    return true;
  }
  
  @Override
  public int hashCode()
  {
    int hash = 5;
    hash = 11 * hash + this.l.hashCode();
    hash = 11 * hash + this.r.hashCode();
    return hash; 
  }
 
  public L getL()
  {
    return this.l;
  }
 
  public void setL(L l) 
  {
    this.l = l;
  }
  
  public R getR() 
  {
    return this.r;
  }
  
  public void setR(R r) 
  {
    this.r = r;
  } 
  
  public String toString()
  { 
    return "(" + 
      (l==null  ? "null" : l.toString()) + ", " + 
      (r==null ? "null" : r.toString()) + ")"; 
  }
  
  /**
   * Check if both parts of the pair are set (non-null)
   * 
   * @return
   */
  public boolean isPaired()
  {
    return l != null && r != null;
  }
}

