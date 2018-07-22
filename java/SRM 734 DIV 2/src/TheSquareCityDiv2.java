import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class TheSquareCityDiv2 {
    private int[] t;
    private int n;

    public int[] find(int r, int[] t) {
        ArrayList<Integer[]> finalPos = new ArrayList<>();
        this.t = t;
        n = (int) Math.sqrt(t.length);
        int lastX;
        int lastY;
        int[] nextPos;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                nextPos = new int[]{x, y};
                do {
                    lastX = nextPos[0];
                    lastY = nextPos[1];
                    nextPos = findNextPos(r, nextPos[0], nextPos[1]);
                } while (nextPos != null);
                finalPos.add(new Integer[]{lastX, lastY, 1});
            }
        }

        for (int i = 0; i < finalPos.size(); i++) {
            Integer[] curr = finalPos.get(i);
            for (int j = i + 1; j < finalPos.size(); j++)
                if (curr[0].equals(finalPos.get(j)[0]) && curr[1].equals(finalPos.get(j)[1])) {
                    curr[2]++;
                    finalPos.remove(j--);
                }
        }

        int max = 0;
        for (Integer[] pos : finalPos)
            if (pos[2] > max)
                max = pos[2];
        return new int[]{finalPos.size(), max};
    }

    private int[] findNextPos(int r, int x1, int y1) {
        int diff;
        int max = t[x1 * n + y1];
        int[] maxPos = new int[]{-1, -1};
        for (int x2 = Math.max(0, x1 - r); x2 <= Math.min(n - 1, x1 + r); x2++) {
            diff = r - Math.abs(x2 - x1);
            for (int y2 = Math.max(0, y1 - diff); y2 <= Math.min(n - 1, y1 + diff); y2++) {
                if (t[x2 * n + y2] > max) {
                    max = t[x2 * n + y2];
                    maxPos[0] = x2;
                    maxPos[1] = y2;
                }
            }
        }
        if (max == t[x1 * n + y1])
            return null;
        else
            return maxPos;
    }
}
