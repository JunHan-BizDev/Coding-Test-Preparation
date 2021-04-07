/*
 * File: Rainbow.java
 * Name: 
 * Section Leader: 
 * -----------------
 * This file is the starter file for the Rainbow problem.
 */

import java.awt.Color;

import acm.graphics.*;
import acm.program.*;

public class Rainbow extends GraphicsProgram {	
	public void run() {
		
		//1.창 크기 고정 
		final int window_width = 800;
		final int window_height = 400;
		
		this.setSize(window_width, window_height);

		//2. 변수 선언 
		Color[] colors = {Color.red,Color.orange, Color.yellow
				,Color.green, Color.blue,Color.magenta,Color.cyan};
		
		//3. 배경색 초기화
		getGCanvas().setBackground(Color.cyan);

		//4. 원 그리기 
		for(int layer = 0; layer < 7; layer++)
		{
			GOval circle = new GOval(-125,30 + layer* 30,1000,700);
			circle.setFillColor(colors[layer]);
			circle.setColor(colors[layer]);
			circle.setFilled(true);
			add(circle);
		}
		
	}
}
