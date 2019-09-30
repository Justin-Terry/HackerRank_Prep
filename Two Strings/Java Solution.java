import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the twoStrings function below.
    static String twoStrings(String s1, String s2) {
        // Using a hashmap here because lookup time is O(1)
        Map<Character, Integer> map = new HashMap();
        
        for(int i = 0; i < s1.length(); i++){
            addOne(map, s1.charAt(i));
        }

        for(int i = 0; i<s2.length(); i++){
            if(map.containsKey(s2.charAt(i))){
                return "YES";
            }
        }

        return "NO";
    }

    static void addOne(Map<Character, Integer> m, char c){
        if(m.containsKey(c)){
            m.put(c, m.get(c) + 1);
        }else{
            m.put(c, 1);
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s1 = scanner.nextLine();

            String s2 = scanner.nextLine();

            String result = twoStrings(s1, s2);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
