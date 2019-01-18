import java.math.*;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int N = cin.nextInt();
        for(int i = 1; i <= N; i++) {
            BigInteger ans = BigInteger.ZERO;
            for(int j = 0; j < 4; j++) {
                BigInteger a = cin.nextBigInteger();
                ans = ans.add(a);
            }
            System.out.println(ans);
        }
    }
}