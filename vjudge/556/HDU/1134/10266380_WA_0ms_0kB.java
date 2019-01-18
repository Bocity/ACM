import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by STay on 6/4/17.
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int n = in.nextInt();
            if (n == -1) break;
            else if (n == 1) System.out.println(1);
            else if (n == 2) System.out.println(2);
            else {
                BigInteger cnt = BigInteger.ONE;
                BigInteger pre = BigInteger.valueOf(2);
                for (int i = 3; i <= n; i++) {
                    pre = pre.multiply(BigInteger.valueOf(i)).subtract(cnt);
                    cnt = cnt.add(BigInteger.valueOf(i));
                }
                System.out.println(pre);
            }
        }
    }
}