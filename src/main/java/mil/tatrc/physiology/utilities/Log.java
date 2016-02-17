/**************************************************************************************
Copyright 2015 Applied Research Associates, Inc.
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the License
at:
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under
the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
**************************************************************************************/

package mil.tatrc.physiology.utilities;

import java.io.File;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import org.apache.log4j.Appender;
import org.apache.log4j.FileAppender;
import org.apache.log4j.Layout;
import org.apache.log4j.Level;
import org.apache.log4j.Logger;
import org.apache.log4j.PatternLayout;
import org.apache.log4j.PropertyConfigurator;

/**
 * @author abray
 *
 */
public class Log
{
  static
  {
    String toLog = System.getProperty("physiology.log4j");
    if((toLog==null||"true".equals(toLog)))
    {
      File f = new File("./Physiology.log4j");
      if(f.exists())
      {
        PropertyConfigurator.configure("./Physiology.log4j");
      }
      else
      {
        f = new File("./log4j.properties").getAbsoluteFile();
        if(f.exists())
        {
          PropertyConfigurator.configure(f.getAbsolutePath());
        }
      }
    }
    else if("log4cpp".equals(toLog))
    	output2Log4j = false;
  }

  public static boolean setLog4jConfiguration(String configFile)
  {
    File f = new File(configFile);
    if(!f.exists())
    {
      System.err.println("Log4j configuration file "+configFile+" does not exist");
      return false;
    }
    PropertyConfigurator.configure(configFile);
    return true;
  }
  
  /**
   * Disable or Enable logging to the log4j
   * If Disabled, logging will propagate to 
   * the listeners and not to log4j
   * as configured in the configuration file
   * (No log files, console, etc)
   * @param b
   */
  public static void outputToLog4j(boolean b)
  {
    output2Log4j=b;
  }

  private static String currentLoggerName;
  private static Set<String> ignoreClasses=new HashSet<String>(); 
  private static Map<String,Logger> loggers = new HashMap<String,Logger>();
  private static boolean output2Log4j = true;

  /** Key is the thread ID you want this listener to listen to*/
  private static Map<String,Set<LogListener>> appenders=new HashMap<String,Set<LogListener>>(); 

  private static Logger get()
  {
    if(loggers.isEmpty())
    {
      ignoreClasses.add("Log");
      ignoreClasses.add("TimingProfile");
    }
    currentLoggerName = CurrentClass.getTrimmedName(ignoreClasses);
    currentLoggerName = currentLoggerName.substring(0, currentLoggerName.indexOf("::"));
    Logger logger = loggers.get(currentLoggerName);
    if(logger == null)
    {
      logger=Logger.getLogger(currentLoggerName);
      loggers.put(currentLoggerName, logger);
    }
    return logger;
  }

  public static Logger get(String name)
  {
    if(loggers.isEmpty())
    {
      ignoreClasses.add("Log");
    }
    Logger logger = loggers.get(name);
    if(logger == null)
    {
      logger=Logger.getLogger(name);
      loggers.put(name, logger);
    }
    return logger;
  }

  public static void setFileName(String name)
  {
    Appender file = Logger.getRootLogger().getAppender("LogFile");
    if(file!=null&&(file instanceof FileAppender))
    {
      ((FileAppender)file).setFile(name);
    }
    else
    {
      // No file appender, so make one
      file=new FileAppender();
      Layout layout = new PatternLayout("%-5p %c %x - %m%n");
      file.setLayout(layout);
      ((FileAppender)file).setAppend(false);
      ((FileAppender)file).setFile(name);
      ((FileAppender)file).activateOptions();
      Logger.getRootLogger().addAppender(file);
    }
    ((FileAppender)file).activateOptions();
  }
  
  public static void deleteLogFile()
  {
    Appender file = Logger.getRootLogger().getAppender("LogFile");
    if(file!=null&&(file instanceof FileAppender))
    {
      String fileName = ((FileAppender)file).getFile();
      setFileName("NuCSCore.log");// set back to generic log name
      FileUtils.delete(fileName);
    }    
  }


  public static void addAppender(LogListener appender)
  {
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners = appenders.get(tName);
    if(listeners==null)
    {
      listeners = new HashSet<LogListener>();
      appenders.put(tName, listeners);
    }
    listeners.add(appender);
  }

  public static void addAppender(String threadName, LogListener appender)
  {
    Set<LogListener> listeners = appenders.get(threadName);
    if(listeners==null)
    {
      listeners = new HashSet<LogListener>();
      appenders.put(threadName, listeners);
    }
    listeners.add(appender);
  }

  public static void removeAppender(LogListener appender)
  {
    Set<LogListener> listeners;
    for(String tName : appenders.keySet())
    {
      listeners=appenders.get(tName);
      if(listeners!=null)
        listeners.remove(appender);
    }  
  }
  
  public static void clearAppenders()
  {
    appenders.clear();
  }

  protected static String getOrigin()
  {
    return CurrentClass.getTrimmedName(ignoreClasses);
  }

  public static Level getLevel()
  {
    return Logger.getRootLogger().getLevel();
  }
  
  public static void setLevel(Level level)
  {
    Logger.getRootLogger().setLevel(level);
  }
  
  protected static int getLogLevel()
  {
  	return Level.INFO.toInt();
  }

  public static boolean isFatal()
  {
    return Level.FATAL.isGreaterOrEqual(getLevel());
  }

  public static boolean isError()
  {
    return Level.ERROR.isGreaterOrEqual(getLevel());
  }

  public static boolean isWarn()
  {
    return Level.WARN.isGreaterOrEqual(getLevel());
  }

  public static boolean isInfo()
  {
    return Level.INFO.isGreaterOrEqual(getLevel());
  }

  public static boolean isDebug()
  {
    return Level.DEBUG.isGreaterOrEqual(getLevel());
  }

  public static boolean isTrace()
  {
    return Level.TRACE.isGreaterOrEqual(getLevel());
  }

  private Log()
  {

  }

  public static void ignoreClass(String name)
  {
    ignoreClasses.add(name);
  }

  public static void trace(String msg)
  {
    if(!isTrace())return;
    if(output2Log4j)get().trace(getOrigin()+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.trace(msg,currentLoggerName);
    }
  }

  public static void trace(String msg, String origin)
  {
    if(!isTrace())return;
    if(output2Log4j)get().trace(origin+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.trace(msg,origin);
    }
  }

  public static void trace(String msg, Throwable t)
  {
    if(!isTrace())return;
    if(output2Log4j)get().trace(getOrigin()+"::"+msg, t);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.trace(msg,t);
    }
  }

  public static void debug(String msg)
  {
    if(!isDebug())return;
    if(output2Log4j)get().debug(getOrigin()+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.debug(msg,currentLoggerName);
    }
  }

  public static void debug(String msg, String origin)
  {
    if(!isDebug())return;
    if(output2Log4j)get().debug(origin+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.debug(msg,origin);
    }
  }

  public static void debug(String msg, Throwable t)
  {
    if(!isDebug())return;
    if(output2Log4j)get().debug(getOrigin()+"::"+msg,t);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.debug(msg,t);
    }
  }

  public static void info(String msg)
  {
    if(!isInfo())return;
    if(output2Log4j)get().info(getOrigin()+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.info(msg,currentLoggerName);
    }
  }

  public static void info(String msg, String origin)
  {
    if(!isInfo())return;
    if(output2Log4j)get().info(origin+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.info(msg,origin);
    }
  }

  public static void info(String msg, Throwable t)
  {
    if(!isInfo())return;
    if(output2Log4j)get().info(getOrigin()+"::"+msg,t);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.info(msg,t);
    }
  }

  public static void warn (String msg)
  {
    if(!isWarn())return;
    if(output2Log4j)get().warn(getOrigin()+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.warn(msg,currentLoggerName);
    }
  }

  public static void warn(String msg, String origin)
  {
    if(!isWarn())return;
    if(output2Log4j)get().warn(origin+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.warn(msg,origin);
    }
  }

  public static void warn(String msg, Throwable t)
  {
    if(!isWarn())return;
    if(output2Log4j)get().warn(getOrigin()+"::"+msg, t);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.warn(msg,t);
    }
  }

  public static void error(String msg)
  {
    if(!isError())return;
    if(output2Log4j)get().error(getOrigin()+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.error(msg,currentLoggerName);
    }
  }

  public static void error(String msg, String origin)
  {
    if(!isError())return;
    if(output2Log4j)get().error(origin+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.error(msg,origin);
    }
  }

  public static void error(String msg, Throwable t)
  {
    if(!isError())return;
    if(output2Log4j)get().error(getOrigin()+"::"+msg,t);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.error(msg,t);
    }
  }

  public static void error(Throwable t)
  {
    if(!isError())return;
    if(output2Log4j)get().error(getOrigin(),t);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.error(t);
    }
  }

  public static void fatal(String msg)
  {
    if(!isFatal())return;
    if(output2Log4j)get().fatal(getOrigin()+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.fatal(msg,currentLoggerName);
    }
  }

  public static void fatal(String msg, String origin)
  {
    if(!isFatal())return;
    if(output2Log4j)get().fatal(origin+"::"+msg);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.fatal(msg,origin);
    }
  }

  public static void fatal(String msg, Throwable t)
  {
    if(!isFatal())return;
    if(output2Log4j)get().fatal(getOrigin()+"::"+msg, t);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.fatal(msg,t);
    }
  }

  public static void fatal(Throwable t)
  {
    if(!isFatal())return;
    if(output2Log4j)get().fatal(getOrigin(),t);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.fatal(t);
    }
  }

  public static void progress(String status, float percent)
  {
    if(output2Log4j)get().info(status+" - "+percent+"%");
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.progress(status,"",percent);
    }
  }

  public static void progress(String status, String info, float percent)
  {
    if(output2Log4j)get().info(status+" - "+percent+"% - "+info);
    String tName = Thread.currentThread().getName();
    Set<LogListener> listeners=appenders.get(tName);
    if(listeners!=null)
    {
      for(LogListener a : listeners)
        a.progress(status,info,percent);
    }
  }
}
