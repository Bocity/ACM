import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
    public static void main(String args[]){
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int n = cin.nextInt();
        for(int i = 0; i < n; i++){
            int a = cin.nextInt();
            int b = cin.nextInt();
            int c = cin.nextInt();
           // System.out.println(a);
            BigInteger x = BigInteger.valueOf(1);
            BigInteger y = BigInteger.valueOf(1);
            for(int j = 1; j <= b; ++j){
                y = y.multiply(BigInteger.valueOf(j));
            }
            for(int j = a; j >= a - b + 1; --j){
                x = x.multiply(BigInteger.valueOf(j));
            }
            BigInteger z = x.divide(y);
            System.out.println(z.toString(c));
        }
    }
}