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
            a = new BigInteger(cin.next(), 2);
            b = new BigInteger(cin.next(), 2);
            System.out.print("Case #");
            System.out.print(cas);
            System.out.print(": ");
            System.out.println(a.gcd(b).toString(2));
        }
    }
}
