import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    static public void main(String []args){
        Scanner scn = new Scanner(System.in);
        int tc = scn.nextInt();
        while(true){

            if(tc == 0){
                break;
            }
            tc--;
            int n = scn.nextInt(), k = scn.nextInt(), d = scn.nextInt();
            BigInteger res = BigInteger.valueOf(1);
            for(int i = n - k + 1; i <= n; ++i){
                res = res.multiply(BigInteger.valueOf(i));
            }
            for(int i = 2; i <= k; ++i){
                res = res.divide(BigInteger.valueOf(i));
            }
            StringBuilder bdr = new StringBuilder();
            while(res.compareTo(BigInteger.ZERO) != 0){
                bdr.append(res.remainder(BigInteger.valueOf(d)));
                res = res.divide(BigInteger.valueOf(d));
            }
            bdr = bdr.reverse();
            System.out.println(bdr);


        }

    }

}
