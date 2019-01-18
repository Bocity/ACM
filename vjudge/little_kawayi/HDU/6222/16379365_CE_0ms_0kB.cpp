import java.math.*;
import java.math.BigInteger;
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger fi = BigInteger.valueOf(4);
        BigInteger se = BigInteger.valueOf(14);
        BigInteger f = BigInteger.valueOf(4);
        List<BigInteger> tmp = new ArrayList <>();
        tmp.add(fi);
        tmp.add(se);
        BigInteger maxn = BigInteger.TEN.pow(30);
        BigInteger cmp;
        while(se.compareTo(maxn) <= 0) {
            cmp = se;
            se = f.multiply(se).subtract(fi);
            tmp.add(se);
            fi = cmp;
        }
        int N = cin.nextInt();
        for(int i = 1; i <= N; i++) {
            BigInteger a = cin.nextBigInteger();
            for(BigInteger j : tmp) {
                if(a.compareTo(j) <= 0) {
                    System.out.println(j);
                    break;
                }
            }
            // BigInteger ans = BigInteger.ZERO;
            // for(int j = 0; j < 4; j++) {
            //     BigInteger a = cin.nextBigInteger();
            //     ans = ans.add(a);
            // }
            // System.out.println(ans);
        }
    }
}