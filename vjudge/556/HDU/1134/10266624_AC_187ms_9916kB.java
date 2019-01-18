import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by STay on 6/4/17.
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger[] mem = new BigInteger[210];
        mem[0] = mem[1] = BigInteger.ONE;
        for (int i = 2; i <= 200; i++) {
            mem[i] = mem[i - 1].multiply(BigInteger.valueOf(i));
        }
        while(in.hasNext()) {
            int n = in.nextInt();
            if (n == -1) break;
            else {
                System.out.println(mem[2 * n].divide(mem[n + 1].multiply(mem[n])));
            }
        }
    }
}
