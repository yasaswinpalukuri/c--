import java.util.*;
import java.io.*;

public class dataAnnotation {
    public static void main(String[] args) {
        File file = new File("coding_qual_input_new.txt");
        HashMap<Integer,String> hm = new HashMap<>();
        int maxValue = 0;
        try (Scanner scan = new Scanner(file)) {
            while (scan.hasNextLine()) {
                String line = scan.nextLine();
                // System.out.println(line);
                String[] parts = line.split(" ");
                hm.put(Integer.parseInt(parts[0]),parts[1]);
                // System.out.println("Key: " + parts[0] + " Value: " + parts[1]);
                if(Integer.parseInt(parts[0]) > maxValue){
                    maxValue = Integer.parseInt(parts[0]);
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        
        int i =1;
        int j =1;
        String ans = "";
        while(i <= maxValue){
            if(hm.containsKey(i)){
                System.out.println("Key: " + i + " Value: " + hm.get(i));
                ans += hm.get(i) + " ";
            }
            i += ++j;
        }
        System.out.print(ans);
    }
}
