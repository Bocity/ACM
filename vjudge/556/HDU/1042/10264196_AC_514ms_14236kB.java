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
            BigInteger ans = BigInteger.ONE;
            BigInteger temp = BigInteger.ONE;
            for (int i = 2; i <= n; i++) {
                temp = temp.add(BigInteger.ONE);
                ans = ans.multiply(temp);
            }
            System.out.println(ans);
        }
    }
}