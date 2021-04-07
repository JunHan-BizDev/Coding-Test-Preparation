/*
 * File: Pyramid.java
 * Name: 
 * Section Leader: 
 * ------------------
 * This file is the starter file for the Pyramid problem.
 * It includes definitions of the constants that match the
 * sample run in the assignment, but you should make sure
 * that changing these values causes the generated display
 * to change accordingly.
 */

import acm.graphics.*;
import acm.program.*;

public class Pyramid extends GraphicsProgram {

/** Width of each brick in pixels */
	private static final int BRICK_WIDTH = 30;

/** Width of each brick in pixels */
	private static final int BRICK_HEIGHT = 12;

/** Number of bricks in the base of the pyramid */
	private static final int BRICKS_IN_BASE = 15;
	
	float bottom = BOTTOM_ALIGNMENT;
	float mid = CENTER_ALIGNMENT;
	
	public void run() {
		
		int x_begin = 0;
		int y_begin = getHeight() - BRICK_HEIGHT;
		
		for(int height = BRICKS_IN_BASE; height >= 1; height--)
		{
			x_begin = getWidth() / 2;
			x_begin -= height * (BRICK_WIDTH / 2);
			
			for(int len = height; len > 0; len--)
			{
			
				GRect brick = new GRect(x_begin,y_begin,BRICK_WIDTH, BRICK_HEIGHT);
				add(brick);
				x_begin += BRICK_WIDTH;
			}
			
			y_begin -= BRICK_HEIGHT;
		}
		
	}
}

