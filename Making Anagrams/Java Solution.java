import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the makeAnagram function below.
    static int makeAnagram(String a, String b) {
        Map<Character, Integer> mapA = new HashMap();
        Map<Character, Integer> mapB = new HashMap();

        setupMap(mapA, a);
        setupMap(mapB, b);

        int numDeletes = 0;

        return calcDeletes(mapA, mapB);
    }

    // O(2n) = O(n)
    static int calcDeletes(Map<Character, Integer> m1, Map<Character, Integer> m2){
        int total = 0;
        for(char c : m1.keySet()){
            if(m2.containsKey(c)){
                // Both maps contain the char, only delete the extras.
                total += Math.abs(m1.get(c) - m2.get(c));
            } else{
                // Only m1 contains this char, delete all of them
                total += m1.get(c);
            }
        }
        for(char c : m2.keySet()){
            if(!m1.containsKey(c)){
                // Only m2 contains this char, delete all of them
                total += m2.get(c);
            }
        }
        return total;
    }

    // O(n)
    static void setupMap(Map<Character, Integer> m, String s){
        for(int i = 0; i < s.length(); i++){
            addOne(m, s.charAt(i));
        }
    }

    static void addOne(Map<Character, Integer> m, char s){
        if(m.containsKey(s)){
            m.put(s, m.get(s) + 1);
        }else{
            m.put(s, 1);
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String a = scanner.nextLine();

        String b = scanner.nextLine();

        int res = makeAnagram(a, b);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
