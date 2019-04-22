import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;


public class Main{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        BigInteger temp;
        BigInteger sum = new BigInteger("0",10);
        String s;
        while(cin.hasNext())
        {
            s = cin.next();
            temp = new BigInteger(s,10);
            if(temp.equals(new BigInteger("0",10)))
            {
                break;
            }
            sum = sum.add(temp);
        }
        System.out.println(sum.toString());
    }
}