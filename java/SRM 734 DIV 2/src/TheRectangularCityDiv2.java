import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class TheRectangularCityDiv2 {

    private int n;
    private int m;
    private String[] city;
    private long count;
    private int openCount;

    public long find(String[] city) {
        this.city = city;
        n = city.length;
        m = city[0].length();
        count = 0;
        openCount = 0;
        for (String row : city)
            for (int c = 0; c < row.length(); c++)
                if (row.charAt(c) == '.')
                    openCount++;

        int[] sides = (n-1==0) ? new int[]{0} : new int[]{0, n-1};
        for (int x : sides)
            for (int y = 0; y < m; y++)
                if (city[x].charAt(y) == '.')
                    countPaths(x, y);

        sides = (m-1==0) ? new int[]{0} : new int[]{0, m-1};
        for (int y : sides)
            for (int x = 1; x < n - 1; x++)
                if (city[x].charAt(y) == '.')
                    countPaths(x, y);
        return count;
    }

    private void countPaths(int x, int y) {
        ArrayList<State> hist = new ArrayList<>(1);
        hist.add(new State(x, y, 0));
        while (hist.get(0) != null)
            findNextPath(hist);
    }

    private void findNextPath(ArrayList<State> hist) {
        if (hist.size() == openCount) {
            State last = hist.get(hist.size()-1);
            if (last.x == 0 || last.x == n-1 || last.y == 0 || last.y == m-1)
                count++;
            carry(hist);
        } else if (hist.get(hist.size() - 1).dir == 4) {
            carry(hist);
        } else {
            State ts = hist.get(hist.size() - 1);
            State ns;
            switch (ts.dir) {
                case 0:
                    ns = new State(ts.x + 1, ts.y, 0);
                    break;
                case 1:
                    ns = new State(ts.x, ts.y + 1, 0);
                    break;
                case 2:
                    ns = new State(ts.x - 1, ts.y, 0);
                    break;
                case 3:
                    ns = new State(ts.x, ts.y - 1, 0);
                    break;
                default:
                    throw new IllegalStateException("Dir is not in the range of 0-3");
            }

            if (ns.x < 0 || ns.x > n-1 || ns.y < 0 || ns.y > m-1 || city[ns.x].charAt(ns.y) == '#') {
                ts.dir++;
            } else {
                for (State s : hist)
                    if (s.x == ns.x && s.y == ns.y) {
                        ts.dir++;
                        return;
                    }
                hist.add(ns);
            }
        }
    }

    private void carry(ArrayList<State> hist) {
        if (hist.size() == 1)
            hist.set(0, null);
        else {
            hist.remove(hist.size() - 1);
            hist.get(hist.size() - 1).dir++;
        }
    }

    private static class State {
        private final int x;
        private final int y;
        private int dir;

        private State(int x, int y, int dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
    }
}
