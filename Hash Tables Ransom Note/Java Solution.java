import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the checkMagazine function below.
    static void checkMagazine(String[] magazine, String[] note) {
        Map<String, Integer> map = new HashMap<String, Integer>();

        for(int i = 0; i < magazine.length; i++){
            addOne(map, magazine[i]);
        }
        for(int i = 0; i < note.length; i++){
            if(!map.containsKey(note[i]) || map.get(note[i]) < 1){
                System.out.println("No");
                return;
            }
            map.put(note[i], map.get(note[i]) - 1);
        }
        System.out.println("Yes");
    }

    static void addOne(Map<String, Integer> m, String s){
        if(m.containsKey(s)){
            m.put(s, m.get(s) + 1);
        }else{
            m.put(s, 1);
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String[] mn = scanner.nextLine().split(" ");

        int m = Integer.parseInt(mn[0]);

        int n = Integer.parseInt(mn[1]);

        String[] magazine = new String[m];

        String[] magazineItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            String magazineItem = magazineItems[i];
            magazine[i] = magazineItem;
        }

        String[] note = new String[n];

        String[] noteItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            String noteItem = noteItems[i];
            note[i] = noteItem;
        }

        checkMagazine(magazine, note);

        scanner.close();
    }
}
