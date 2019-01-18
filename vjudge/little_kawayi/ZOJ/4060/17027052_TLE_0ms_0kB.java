import java.math.*;
import java.math.BigInteger;
import java.io.*;
import java.util.*;
import java.lang.reflect.Array;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        char[] c1 = new char[1000010];
        char[] c2 = new char[1000010];
        char[] c3 = new char[1000010];
        String cc1 = new String();
        String cc2 = new String();
        for(int k = 0; k < t; k++) {
            int sz = cin.nextInt();
            cc1 = cin.next();
            cc2 = cin.next();
            c1 = cc1.toCharArray();
            c2 = cc2.toCharArray();
            c3[0] = '0';
            for(int i = 0; i < sz; i++) {
                if(c1[i] == c2[i]) c3[i + 1] = '0';
                else c3[i + 1] = '1';
            }
            BigInteger cnt = BigInteger.ZERO;
            for(int i = 1; i <= sz; i++) {
                if(c3[i] == '1' && c3[i - 1] == '0') cnt = cnt.add(BigInteger.ONE);
            }
            BigInteger tmp = BigInteger.valueOf(2);
            BigInteger fi = BigInteger.ONE;
            // System.out.println(cnt);
            if(cnt.compareTo(tmp) > 0) System.out.println(0);
            else if(cnt.compareTo(tmp) == 0) System.out.println(6);
            else if(cnt.compareTo(fi) == 0) System.out.println(2 * (sz - 1));
            else {
                BigInteger ans = tmp.pow(sz);
                ans = ans.subtract(fi);
                System.out.println(ans);
            }
        }
    }
}