import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
  static int N = 100000 * 2 + 10;
  static int[] oil = new int[N];
  static int[] dist = new int[N];
  static long[] s = new long[N];
  static int[] q = new int[N];
  static boolean[] yes = new boolean[N];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
    int n = Integer.parseInt(br.readLine());
    for(int i = 1;i <= n;i ++) {
      String[] s1 = br.readLine().split(" ");
      oil[i] = Integer.parseInt(s1[0]);
      dist[i] = Integer.parseInt(s1[1]);
    }

    // clockwise
    for(int i = 1;i <= n ;i ++) s[i] = s[i + n] = oil[i] - dist[i];
    for(int i = 1;i <= n * 2;i ++) s[i] += s[i - 1];
    int hh = 0,tt = -1;
    for(int i = n * 2;i >= 1;i --) {
      if(hh <= tt && q[hh] > i + n - 1) hh ++;
      while(hh <= tt && s[q[tt]] >= s[i]) tt --;
      q[++ tt] = i;
      if(i <= n && s[q[hh]] - s[i - 1] >= 0) yes[i] = true;
    }

    // anticlockwise
    dist[0] = dist[n];
    for(int i = n;i >= 1;i --) s[i] = s[i + n] = oil[i] - dist[i - 1];
    for(int i = n * 2;i >= 1;i --) s[i] += s[i + 1];
    hh = 0; tt = -1;
    for(int i = 1;i <= n * 2;i ++) {
      if(hh <= tt && q[hh] < i - n + 1) hh ++;
      while(hh <= tt && s[q[tt]] >= s[i]) tt --;
      q[++ tt] = i;

      if(i >= n + 1 && s[q[hh]] - s[i + 1] >= 0) yes[i - n] = true;
    }

    for(int i = 1;i <= n;i ++) {
      if(yes[i]) log.write("TAK\n");
      else log.write("NIE\n");
    }
    log.flush();
  }
}