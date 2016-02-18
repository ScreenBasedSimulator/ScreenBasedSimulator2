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

package mil.tatrc.physiology.biogears.verification;

import java.io.File;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.List;
import java.util.Map;

import mil.tatrc.physiology.utilities.FileUtils;
import mil.tatrc.physiology.utilities.Log;
import mil.tatrc.physiology.utilities.StringUtils;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartUtilities;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.LogarithmicAxis;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.axis.ValueAxis;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.xy.XYItemRenderer;
import org.jfree.chart.renderer.xy.XYLineAndShapeRenderer;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

import java.awt.BasicStroke;
import java.awt.Font;
import java.awt.Color;
import java.awt.Paint;

/**
 * @author abray
 *
 */

public class ScenarioPlotTool
{
  //font size for tick labels and legend
  public static Font smallFont = new Font("SansSerif", Font.PLAIN, 15);
  //font size for X,Y axis title and plot title
  public static Font largeFont = new Font("SansSerif", Font.PLAIN, 22);  
  //width of lines
  public static float lineWidth = 2.0f;
  //color of expected data
  public static Paint expectedLineColor = Color.BLACK;
  //color of computed data
  public static Paint computedLineColor = Color.RED;

  public static void main(String[] args)
  {
    if(args.length<1)
    {
      Log.fatal("Expected inputs : [results file path] [result in results file NOT to plot] ");
      return;
    }
    File f = new File(args[0]);
    if(!f.exists())
    {
      Log.fatal("Input file cannot be found");
      return;
    }
    String reportDir = "./graph_results/"+f.getName();
    reportDir=reportDir.substring(0,reportDir.lastIndexOf("."))+"/";  
    ScenarioPlotTool t = new ScenarioPlotTool();
    t.graphResults(args[0],reportDir);
  }

  public boolean graphResults(String resultsFile, String graphLocation)
  {
    try
    {
      File f = new File(resultsFile);
      if(!f.exists())
      {
        Log.fatal("Input file cannot be found");
        return false;
      }

      File dir = new File(graphLocation);
      if(dir.exists() && dir.isDirectory())
      {
        for(String g : dir.list())
          if(g.endsWith(".jpg"))
            FileUtils.delete(g);
      }      
      Thread.sleep(250);
      FileUtils.createDirectory(graphLocation);

      ScenarioResult result = new ScenarioResult(resultsFile);

      Map<String, List<Double>> data = result.readAll();
      for(String header : data.keySet())
      {
        if(header.equals("Time(s)"))
          continue;
        createGraph(graphLocation, Color.white, header + "_vs_Time","Time",header,createTruncatedXYSeries(header,data.get("Time(s)"),data.get(header)));
      }
    }
    catch(Exception ex)
    {
      Log.error("Unable to graph results file "+resultsFile);
      return false;
    }
    return true;
  }

  public void createGraph(String toDir, Paint color, String title, String XAxisLabel, String YAxisLabel, XYSeries...xyData)
  {
    new File(toDir).mkdir();
    
    Log.info("Creating Graph "+toDir+title);
    double resMin0	  = 1.e6;
    double resMax0   = -1.e6;
    double resMin1	  = 1.e6;
    double resMax1   = -1.e6;

    XYSeriesCollection dataSet = new XYSeriesCollection();
    for(XYSeries data : xyData)
      dataSet.addSeries(data);

    JFreeChart chart = ChartFactory.createXYLineChart(
        title ,					 // chart title
        XAxisLabel,				 // x axis label
        YAxisLabel,				 // y axis label
        dataSet,                   // data
        PlotOrientation.VERTICAL,  // orientation
        true,                      // include legend
        true,                      // tooltips
        false                      // urls
        );

    XYPlot plot = (XYPlot) chart.getPlot();

    if(title.contains("Residual"))
    {
      // Make plot symmetric about x axis
      resMax0 = xyData[0].getMaxY();
      resMin0 = xyData[0].getMinY();
      if (Math.abs(xyData[0].getMinY()) > Math.abs(xyData[0].getMaxY()))  resMax0 = Math.abs(resMin0);
      if (Math.abs(xyData[0].getMaxY()) > Math.abs(xyData[0].getMinY()))  resMin0 = -1.0*Math.abs(resMax0);
      if((resMin0==0.0) && (resMax0==0.0))
      {
        resMin0 = -0.00001;
        resMax0 =  0.00001;
      }    	
      ValueAxis yAxis = plot.getRangeAxis();
      yAxis.setRange(resMin0 + 0.05*resMin0, resMax0 + 0.05*resMax0);//5% buffer so we can see top and bottom clearly
    }
    else if(title.contains("Error"))
    {
      // Make plot symmetric about x axis
      resMax0 = xyData[0].getMaxY();
      resMin0 = xyData[0].getMinY();
      if((resMin0==0.0) && (resMax0==0.0))
      {
        resMin0 = -0.00001;
        resMax0 =  0.00001;
      }
      if(resMin0>=0.0) resMin0 = -0.01;
      ValueAxis yAxis = plot.getRangeAxis();
      yAxis.setRange(resMin0 + 0.05*resMin0, resMax0 + 0.05*resMax0);//5% buffer so we can see top and bottom clearly

      /*
    	yAxis.setTickLabelPaint(new Color(1,0,0));
    	yAxis.setTickMarkPaint(new Color(1,0,0));
    	yAxis.setAxisLinePaint(new Color(1,0,0));
    	yAxis.setLabelPaint(new Color(1,0,0));

    	ValueAxis xAxis = plot.getDomainAxis();
    	xAxis.setTickLabelPaint(new Color(1,0,0));
    	xAxis.setTickMarkPaint(new Color(1,0,0));
    	yAxis.setAxisLinePaint(new Color(1,0,0));
    	yAxis.setLabelPaint(new Color(1,0,0));
       */
    }
    else
    {    	
      if(xyData.length > 1)
      {
        // Make plot symmetric about x axis
        resMax0 = xyData[0].getMaxY();
        resMin0 = xyData[0].getMinY();
        resMax1 = xyData[1].getMaxY();
        resMin1 = xyData[1].getMinY();
        if(resMin1<resMin0) resMin0=resMin1;
        if(resMax1>resMax0) resMax0=resMax1;
        if((resMin0==0.0) && (resMax0==0.0))
        {
          resMin0 = -0.00001;
          resMax0 =  0.00001;
        }
        if(resMin0>=0.0) resMin0 = -0.01;
        if(YAxisLabel.indexOf("PlasmaConcentration")>-1)
          plot.setRangeAxis(new LogarithmicAxis("Log("+YAxisLabel+")")); 
        else
        {
          ValueAxis yAxis = plot.getRangeAxis();
          yAxis.setRange(resMin0 + 0.05*resMin0, resMax0 + 0.05*resMax0);//5% buffer so we can see top and bottom clearly
        }
      }
      else
      {
        // Make plot symmetric about x axis
        resMax0 = xyData[0].getMaxY();
        resMin0 = xyData[0].getMinY();
        if((resMin0==0.0) && (resMax0==0.0))
        {
          resMin0 = -0.00001;
          resMax0 =  0.00001;
        }
        if(resMin0>=0.0) resMin0 = -0.01;
        if(YAxisLabel.indexOf("PlasmaConcentration")>-1)
          plot.setRangeAxis(new LogarithmicAxis("Log("+YAxisLabel+")"));
        else
        {
          ValueAxis yAxis = plot.getRangeAxis();
          yAxis.setRange(resMin0 + 0.05*resMin0, resMax0 + 0.05*resMax0);//5% buffer so we can see top and bottom clearly
        }        	
      }
    }

    formatXYPlot(chart,color);
    //Changing line widths and colors
    XYItemRenderer r = plot.getRenderer(); 
    BasicStroke wideLine = new BasicStroke( lineWidth ); 
    r.setSeriesStroke(0, wideLine); 
    r.setSeriesStroke(1, wideLine); 
    XYLineAndShapeRenderer renderer = (XYLineAndShapeRenderer) plot.getRenderer();
    if(xyData.length>1)
    {
      renderer.setSeriesStroke(//makes a dashed line
          0, //argument below float[]{I,K} -> alternates between solid and opaque (solid for I, opaque for K)
          new BasicStroke(lineWidth, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND, 1.0f, new float[]{15.0f, 30.0f}, 0.0f)
          );
      renderer.setDrawSeriesLineAsPath(true);
      renderer.setUseFillPaint(true);
    }  
    renderer.setBaseShapesVisible(false);
    renderer.setSeriesFillPaint(0, expectedLineColor); 
    renderer.setSeriesFillPaint(1, computedLineColor ); 
    renderer.setSeriesPaint(0, expectedLineColor); 
    renderer.setSeriesPaint(1, computedLineColor); 

    try
    {
      if(toDir==null||toDir.isEmpty())
        toDir=".";
      File JPGFile = new File(toDir+"/"+StringUtils.removeParens(title)+".jpg");
      ChartUtilities.saveChartAsJPEG(JPGFile, chart, 1600, 800);
    }
    catch (IOException e)
    {
      Log.error(e.getMessage());
    }
  }

  public XYSeries createXYSeries(String name, List<Double> x, List<Double>y)
  {
    if(y.size()!=x.size())
    {
      Log.error("axis data is not the same size");

    }    
    XYSeries series = new XYSeries(name);
    for(int i=0; i<x.size();i++) 
        series.add(x.get(i),y.get(i));      
    return series;
  }
  
  public XYSeries createTruncatedXYSeries(String name, List<Double> x, List<Double>y)
  {
    if(y.size()!=x.size())
    {
      Log.error("axis data is not the same size");

    }    
    XYSeries series = new XYSeries(name);
    for(int i=0; i<x.size();i++) 
    {
      if(i%3==0)
        series.add(x.get(i),y.get(i));      
    }
    return series;
  }

  public void formatXYPlot(JFreeChart chart, Paint bgColor)
  {
    XYPlot plot = (XYPlot) chart.getPlot();

    //For Scientific notation
    NumberFormat formatter = new DecimalFormat("0.######E0");
    NumberAxis rangeAxis = (NumberAxis)plot.getRangeAxis();
    rangeAxis.setNumberFormatOverride(formatter);

    //White background outside of plottable area
    chart.setBackgroundPaint(bgColor);

    plot.setBackgroundPaint(Color.white);
    plot.setDomainGridlinePaint(Color.black);
    plot.setRangeGridlinePaint(Color.black);

    plot.setDomainCrosshairVisible(true);
    plot.setRangeCrosshairVisible(true);

    //Changing font sizes so they are readable. 
    plot.getDomainAxis().setLabelFont(largeFont);
    plot.getRangeAxis().setLabelFont(largeFont);
    plot.getDomainAxis().setTickLabelFont(smallFont);
    plot.getRangeAxis().setTickLabelFont(smallFont);


    plot.getDomainAxis().setLabelPaint(bgColor==Color.red?Color.white:Color.black);
    plot.getRangeAxis().setLabelPaint(bgColor==Color.red?Color.white:Color.black);
    plot.getDomainAxis().setTickLabelPaint(bgColor==Color.red?Color.white:Color.black);
    plot.getRangeAxis().setTickLabelPaint(bgColor==Color.red?Color.white:Color.black);

    chart.getLegend().setItemFont(smallFont);
    chart.getTitle().setFont(largeFont);
    chart.getTitle().setPaint(bgColor==Color.red?Color.white:Color.black);
  }

}
