import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main(String [] args){
		Scanner in = new Scanner(System.in);
		while(in.hasNextBigInteger()){
			BigInteger a = in.nextBigInteger();
			BigInteger b = in.nextBigInteger();
			System.out.print(a);
			System.out.printf("*");
			System.out.print(b);
			a = a.multiply(b);
			System.out.print("=");
			System.out.println(a);
		}
	}
}