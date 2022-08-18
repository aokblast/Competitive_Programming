import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        BigInteger cur = BigInteger.ONE;
        BigInteger []arr = new BigInteger[n + 1];
        arr[0] = BigInteger.ONE;
        if(n == 1){
            int tmp = scn.nextInt();
            if(tmp == 0) {
                System.out.println(1);
            }else{
                System.out.println(0);
            }
            return;
        }
        for(int i = 1; i <= n; ++i) {
            cur = cur.multiply(BigInteger.valueOf(i));
            arr[i] = cur;
        }
        cur = arr[n - 2];

        boolean ans = true;

        int tot = 0;

        for(int i = 1; i <= n; ++i){
            int tmp = scn.nextInt();
            tot += tmp;
            if(tmp > n - 1 || tmp == 0){
                ans = false;
                break;
            }
            cur = cur.divide(arr[tmp - 1]);
        }

        if(ans && tot == (n - 1) * 2){
            System.out.println(cur);
        }else{
            System.out.println(0);
        }


    }
}
