package Big;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.Scanner;

/**
 * Created by STay on 6/4/17.
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigDecimal num = new BigDecimal(5);
        MathContext mc = new MathContext(210, RoundingMode.FLOOR);
        BigDecimal fnum = new BigDecimal(Math.sqrt(num.doubleValue()), mc);
        fnum = fnum.add(new BigDecimal(1));
        fnum = fnum.divide(new BigDecimal(2), mc);
        while (in.hasNext()) {
            String stra = in.next();
            String strb = in.next();
            BigInteger tempb = new BigInteger(strb);
            BigInteger tempa = new BigInteger(stra);
            BigDecimal a, b;
            if (tempb.compareTo(tempa) > 0) {
                a = new BigDecimal(stra);
                b = new BigDecimal(strb);
            }
            else {
                a = new BigDecimal(strb);
                b = new BigDecimal(stra);
            }
            BigDecimal k = b.subtract(a);
            BigDecimal nfnum = new BigDecimal(fnum.doubleValue(), mc);
            nfnum = nfnum.multiply(k);
            BigInteger biga = nfnum.toBigInteger();
            BigInteger aa = a.toBigInteger();
            if (biga.equals(aa)) {
                System.out.println("0");
            } else {
                System.out.println("1");
            }
        }
    }
}
