/*
 * File: GraphicsHierarchy.java
 * Name: 
 * Section Leader: 
 * ----------------------------
 * This file is the starter file for the GraphicsHierarchy problem.
 */

import acm.graphics.*;
import acm.program.*;

public class GraphicsHierarchy extends GraphicsProgram {	
	public void run() {
	
	 
	 /*  WINDOW  */
		
	//window size
	final int window_width = 800;
	final int window_height = 600;
	
	this.setSize(window_width, window_height);
	
	 /*  BOX  */
	
	//box number 
	final int GOBJECT = 0, GLABEL = 1, GLINE = 2, GOVAL = 3, GRECT = 4;
	
	//box size 
	final int box_width = 150;
	final int box_height = 45;	
	
	//box position 
	int[] x_box = new int[5];
	int[] y_box = {50,300,300,300,300};
	final int interval = (window_width - 4 * box_width) / x_box.length; // interval between boxes

	x_box[GOBJECT] = (window_width - box_width) / 2;
	for(int i = 1; i< 5; i++)
		x_box[i] = box_width * (i - 1)+ interval * i;
	
	
	//boxes
	
	GObject[] box_arr = new GRect[5];
	
	for(int i = 0; i < 5; i++)
	{
		GObject box = new GRect(box_width, box_height);
		box_arr[i] = box;
	}
	
	/* 
	 * Labels */
	
	GObject label_GObject = new GLabel("GObject");
	GObject label_GLabel  = new GLabel("GLabel");
	GObject label_GLine   = new GLabel("GLine");
	GObject label_GOval   = new GLabel("GOval");
	GObject label_GRect   = new GLabel("GRect");
	GObject[] label_arr = {label_GObject,label_GLabel,label_GLine,label_GOval,label_GRect};
	
	double[] x_label = new double[5];
	double[] y_label = new double[5];
	for(int i = 0; i < 5;i++)
	{
		x_label[i] =  x_box[i] + box_width / 2 - label_arr[i].getWidth() / 2;
		y_label[i] =  y_box[i] + (box_height / 2) + label_arr[i].getHeight() / 2;
	}
	
	/*
	 * lines */
	
	
	// starting position 
	double x_line_start = x_box[GOBJECT] + box_width / 2;
	double y_line_start = y_box[GOBJECT] + box_height;

	// ending position
	double[] x_line_end = {x_line_start,0,0,0,0};
	double[] y_line_end = {y_line_start,0,0,0,0};
	for(int i = 1; i < 5; i++)
	{
		x_line_end[i] = x_box[i] + box_width / 2;
		y_line_end[i] = y_box[i];
	}
	
	//initialize line	
	for(int i = 1; i < 5; i++)
	{
		GObject line = new GLine(x_line_start,y_line_start,x_line_end[i],y_line_end[i]);
		add(line);
	}


	
	for(int i = 0 ; i < 5; i++)
	{
		add(box_arr[i],x_box[i],y_box[i]);
		add(label_arr[i],x_label[i],y_label[i]);
	}

	}
}

