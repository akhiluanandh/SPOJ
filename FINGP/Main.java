import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    try {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String pat = br.readLine();
      int n = Integer.parseInt(br.readLine());
      ArrayList<String> ans = new ArrayList<String>();
      for (int i = 0; i < n; i++) {
        String st = br.readLine();
        if (st.endsWith(pat)) {
          ans.add(st);
        }
      }
      if (ans.size() == 0) {
        System.out.println("Wrong fingerprints!");
      } else {
        System.out.println(ans.size());
        Collections.sort(ans);
        for (String str : ans) {
          System.out.println(str);
        }
      }
    } catch (IOException e) {}
  }
 }
