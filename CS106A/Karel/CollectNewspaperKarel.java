/*
 * File: CollectNewspaperKarel.java
 * --------------------------------
 * At present, the CollectNewspaperKarel subclass does nothing.
 * Your job in the assignment is to add the necessary code to
 * instruct Karel to walk to the door of its house, pick up the
 * newspaper (represented by a beeper, of course), and then return
 * to its initial position in the upper left corner of the house.
 */

import stanford.karel.*;
import java.util.Stack;

public class CollectNewspaperKarel extends SuperKarel {
	
static int TURN_LEFT = 3, TURN_RIGHT = 2, FORWARD = 1;

	 public void run() 
	{
		 int path_num = -1;
		 boolean find_door = false, reach_end = false;
		 Stack<Integer> path = new Stack<>(); //to memorize the path 
		 // 1: Going straight 2: turnRight 3: turn left
		 
		//find door & pick up the newspaper
		while(true)
		{
			find_door = isDoor();
			if(find_door)
			{
				path.push(TURN_RIGHT);
				path.push(FORWARD);
				pickBeeper();
				turnAround();
				
				break;
			}
			
			reach_end = reachToEnd();
			if(reach_end)
			{
				turnRight();
				path.push(TURN_LEFT);
			}
			else
			{
				path.push(FORWARD);
			}
		}
		
		//going back to the initial position
		while(!path.isEmpty())
		{
			path_num = path.pop();
			
			switch(path_num)
			{
			case 1: move(); break;
			case 2: turnRight(); break;
			case 3: turnLeft(); break;
			}
		}
		
		turnAround();
	}
	
	 public boolean isDoor()
	 {
		 turnLeft();
		 try
		 {
			 move();
		 } 
		 catch(Exception e)
		 {
			 turnRight();
			 return false;
		 }
		 
		 return true;
	 }
	 
	 public boolean reachToEnd() {
		 try
		 {
			 move();
		 }
		 catch(Exception e)
		 {
			 return true;
		 }
		 return false;
	 }
}
