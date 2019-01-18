import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by STay on 6/4/17.
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            BigInteger a = new BigInteger(in.next());
            BigInteger b = new BigInteger(in.next());
            System.out.println(a.mod(b));
        }
    }
}