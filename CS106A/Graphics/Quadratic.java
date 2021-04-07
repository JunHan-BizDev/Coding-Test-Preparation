/*
 * File: Quadratic.java
 * Name: 
 * Section Leader: 
 * --------------------
 * This file is the starter file for the Quadratic problem.
 */

import java.util.Scanner;

import acm.program.*;

public class Quadratic extends ConsoleProgram {
	public void run() {
		
		double a = 1, b= 0, c = 0;		
		
		// 세 정수 입력
		print("Enter coefficients for the quadratic equation:\n");
		
		do {
		print("a: ");
		a = readDouble();
		
		//a value가 0이 아니기 위한 예외처리
		if(a == 0)
			println("a should be nonzero. enter again");
		
		} while(a == 0);
		
		print("b: ");
		b = readDouble();
		
		print("c: ");
		c = readDouble();
		
		//계산결과 출력
		println("\nThe first solution is " + closeFomula(a,b,c, true));
		println("The first solution is " + closeFomula(a,b,c, false));


	}
	
	//근의공식 계산 
	private double closeFomula(double a, double b, double c, boolean positive)
	{
		//양 근 
		double ans_positive = (-b + Math.sqrt((Math.pow(b, 2) - 4 * a * c))) / 2*a; 
		//음 근
		double ans_negative = (-b - Math.sqrt((Math.pow(b, 2) - 4 * a * c))) / 2*a; 
		
		if(positive)
			return Math.round(ans_positive);
		else
			return Math.round(ans_negative);					
	}
}
