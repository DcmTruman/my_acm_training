import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;


public class Main{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        BigInteger temp;
        
        String s;
        while(cin.hasNext())
        {
            BigInteger sum = new BigInteger("1",10);
            s = cin.next();
            temp = new BigInteger(s,10);
            BigInteger i = new BigInteger("1",10);
            while(i.compareTo(temp) == -1 || i.compareTo(temp) == 0)
            {
                sum = sum.multiply(i);
                i = i.add(new BigInteger("1",10));
            }
            System.out.println(sum.toString());
        }
       
    }
}