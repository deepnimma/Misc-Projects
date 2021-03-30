import java.utils.Scanner;

public class java {
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();

        while(n != 1) {
            if(n % 2 == 0) {
                n /= 2;
            }
            else {
                n = 3 *n + 1;
            }

            System.out.println(n);
        }
    }
}