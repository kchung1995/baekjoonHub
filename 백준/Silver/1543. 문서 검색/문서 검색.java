import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a = br.readLine();
        String b = br.readLine();
        int wordLength = b.length();

        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.length() - i < wordLength) {
                break;
            }
            if(a.substring(i, i + wordLength).equals(b)) {
                count++;
                i = i + wordLength - 1;
            }
        }

        System.out.println(count);
    }
}