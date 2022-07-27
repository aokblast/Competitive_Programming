import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String as = scn.nextLine(), bs = scn.nextLine();

        BigInteger a = new BigInteger(as), b = new BigInteger(bs), r;

        while(b.compareTo(BigInteger.ZERO) > 0){
            r = a.remainder(b);
            a = b;
            b = r;
        }
        System.out.println(a);
    }
}
