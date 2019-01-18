import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by STay on 6/4/17.
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cas = 1;
        int t = in.nextInt();
        while(t-- != 0) {
            BigInteger a = new BigInteger(in.next());
            BigInteger b = new BigInteger(in.next());
            System.out.println("Case " + cas++ + ":");
            System.out.println(a + " + " + b + " = " + a.add(b));
            if (t != 0) System.out.println();
        }
    }
}