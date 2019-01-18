import java.math.*;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        for(int i = 0; i < t; i++) {
            int n = cin.nextInt();
            BigInteger ans = BigInteger.ONE;
            for(int j = 1; j <= n; j++) {
                ans = ans.multiply(BigInteger.valueOf(2));
            }
            System.out.println(ans);
        }
    }
}