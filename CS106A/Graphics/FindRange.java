/*
 * File: FindRange.java
 * Name: 
 * Section Leader: 
 * --------------------
 * This file is the starter file for the FindRange problem.
 */

import java.util.Collections;
import java.util.LinkedList;

import acm.program.*;

public class FindRange extends ConsoleProgram {
	
	
	public void run() {
		
		int input = -1;
		LinkedList<Integer> num_array = new LinkedList<Integer>();

		println("This program finds the smallest and largest integers in a list. "
				+ "Enter values, one per line, using a 0 to signal the end of the list.");
		
		while(true)
		{
			print(" ? ");
			input = readInt();
			
			if(input == 0)
				break;
			
			num_array.add(input);
		}
		
		if(num_array.size() == 0)
			println("no value has entered.");
		else
		{
			Collections.sort(num_array);	
			
			println("The smallest value is " + num_array.getFirst());
			println("The largest value is " + num_array.getLast());
		}
		
	}

}

