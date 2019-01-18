import java.io.BufferedInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int t, n;
        BigInteger a, b;
        t = cin.nextInt();
        for (int cas = 1; cas <= t; cas++) {
            a = cin.nextBigInteger();
            System.out.print("Case #");
            System.out.print(cas);
            System.out.print(": ");
            System.out.println(a.multiply(a).multiply(BigInteger.valueOf(8)).subtract(BigInteger.valueOf(7).multiply(a)).add(BigInteger.ONE));
        }
    }
}
