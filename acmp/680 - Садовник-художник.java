import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {
        try (
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
        ) {
            solve(in, out);
        }
    }

    void solve(Scanner in, PrintWriter out) {
        long n = in.nextLong();
        long res = (1L << (n - 1)) * 3;
        out.println(res);
    }

}