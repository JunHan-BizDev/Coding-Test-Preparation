/*
 * File: StoneMasonKarel.java
 * --------------------------
 * The StoneMasonKarel subclass as it appears here does nothing.
 * When you finish writing it, it should solve the "repair the quad"
 * problem from Assignment 1.  In addition to editing the program,
 * you should be sure to edit this comment so that it no longer
 * indicates that the program does nothing.
 */

import stanford.karel.*;

public class StoneMasonKarel extends SuperKarel {

	public void run()
	{
		int col_count = 1;
		do
		{
			if(col_count % 4 == 1)
			{
				goGetRepaired();
			}
		}
		while(goingForward(col_count));
		
	}
	
	
	
	
	
	
	
	
	public void goGetRepaired()
	{
		int height = 1;
		turnLeft();
		while(!frontIsBlocked())
		{
			if(!beepersPresent())
			{
				putBeeper();
			}
			move();
			height++;
		}

		if(!beepersPresent())
		{
			putBeeper();
		}

		turnAround();
		
		for(int i = 1; i < height;i++)
		{
			move();
		}
		turnLeft();
		
	}
	public boolean checkAndPutBeeper()
	{
		try {
			putBeeper();
		}
		catch(Exception e)
		{
			return false;
		}
		return true;
	}
	
	public boolean goingForward(int col_count)
	{
		try
		{
			do{
			move();
			col_count++;
			}
			while(col_count % 4 != 1);
			
			return true;
		}
		catch(Exception e)
		{
			return false;
		}
	}

}
