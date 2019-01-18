import java.io.BufferedInputStream;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int T;
        T = cin.nextInt();
        for(int cas = 1; cas <= T; ++cas) {
            int n;
            n = cin.nextInt();
//            BigDecimal f[] = new BigDecimal[120];
            ArrayList<BigDecimal> f = new ArrayList<>();
            BigDecimal x, y;
            double a, b;
            for(int i = 0; i < n; ++i) {
                Byte c;
                String tmp = cin.next();
                String[] tmpp = tmp.split(":");
                a = Double.parseDouble(tmpp[0]);
                b = Double.parseDouble(tmpp[1]);

                x = BigDecimal.valueOf(a);
                y = BigDecimal.valueOf(b);
                BigDecimal tt = x.divide(x.add(y), 1024, BigDecimal.ROUND_CEILING);
                f.add(tt);
            }
            Collections.sort(f);
            BigDecimal one = BigDecimal.ONE;
            BigDecimal tmp = BigDecimal.ZERO;
            int ans = 0;
            for(int i = 0; i < n; ++i) {
                tmp = tmp.add(f.get(i));
                if(tmp.compareTo(one) == -1) {
                    ans++;
                } else {
                    break;
                }
            }
            System.out.println("Case #" + cas + ": " + ans);
        }
    }
}
