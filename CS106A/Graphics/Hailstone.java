/*
 * File: Hailstone.java
 * Name: 
 * Section Leader: 
 * --------------------
 * This file is the starter file for the Hailstone problem.
 */

import acm.program.*;

public class Hailstone extends ConsoleProgram {
	public void run() {
		
		int count = 0; //동작 반복 횟수를 세는 변수
		
		print("This program computes Hailstone \nEnter a number: ");
		int num = readInt();
		
		//1이아닐때까지 동
		while(num != 1)
		{
			//홀수 시 동작
			if(num % 2 == 1)
			{
				print(num + "\tis odd, so I make 3n + 1:\t");
				num = num * 3 + 1;
				println(num);
			}
			//짝수시 동작
			else
			{
				print(num + "\tis even, so I take half:\t");
				num = num / 2;
				println(num);
			}
			
			count++;
		}
		
		println("The process took " + count + " steps to reach 1.");
	}
}

