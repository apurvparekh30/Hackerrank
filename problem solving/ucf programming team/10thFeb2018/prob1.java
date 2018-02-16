import java.math.BigInteger;
import java.util.Scanner;
 
public class Example {
	public static void main(){
		while(1){
			Scanner sc = new Scanner(System.in);
			BigInteger b = sc.nextBigInteger();
			if(b==0){
				break;
			}
			int digits=b.toString().length();
			BigInteger sum=0;
			int j=digits;
			while(b!=0){
				BigInteger n=BigInteger%10;
				sum=sum+Math.pow(n,j);
				j--;
				int newdigits=sum.toString().length();
				if(newdigits>digits){
					
					break;
				}
			}
			if(sum == b){
				System.out.println(b+ " is not a powerful number.");
			}
			else{
				System.out.println(b+ " is not a powerful number.");
			}
		}
		

	}
}