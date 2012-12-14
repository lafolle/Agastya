
import java.io.*;
import java.math.*;
import java.io.IOException;

public class bigint{

    
    public static void main(String[] args){

	
	int i, n=23;

	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));


	try{
	    try{
		n = Integer.parseInt(reader.readLine());
	    } catch (NumberFormatException nfe){
		System.out.println("JAVA SUCK!");
	    }
	}
	catch (IOException ioe){
	    System.out.println("FOR SURE, JAVA SUCKS!");
	}

	BigInteger p = BigInteger.ZERO, ans = BigInteger.ZERO;

	for(i=2;i<=n;i++){

	    ans = p.multiply(BigInteger.valueOf(2));

	    if((i-1)%2==1) ans = ans.add(BigInteger.valueOf(1));
	    else ans = ans.subtract(BigInteger.valueOf(1));
	    
	}

	System.out.println(ans);

    }
}

/* giving up! java sucks! never gonna touch it again!
   FUCK FUCK FUCK!
*/