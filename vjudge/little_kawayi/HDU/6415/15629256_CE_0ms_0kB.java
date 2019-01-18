import java.math.*;
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class A {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        int cnt = 0;
        while(cnt < t) {
            cnt++;
            int n = cin.nextInt();
            int m = cin.nextInt();
            int k = cin.nextInt();
            BigInteger ans = BigInteger.ONE;
            for(int i = 1; i <= n; i++) {
                ans = ans.multiply(BigInteger.valueOf(i));
            }
            for(int i = 1; i <= m; i++) {
                ans = ans.multiply(BigInteger.valueOf(i));
            }
            for(int i = 1; i <= m * n; i++) {
                ans = ans.multiply(BigInteger.valueOf(i));
            }
            for(int i = 1; i <= (m + n - 1); i++) {
                ans = ans.divide(BigInteger.valueOf(i));
            }
            ans = ans.mod(BigInteger.valueOf(k));
            System.out.println(ans);
        }
    }
}