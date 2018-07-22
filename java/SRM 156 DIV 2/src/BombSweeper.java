import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class BombSweeper {
	
	public double winPercentage(String[] board) {
	    final int colLen = board.length;
	    final int rowLen = board[0].length();
	    HashSet<Integer> all = new HashSet<>();
        HashSet<Integer> bombs = new HashSet<>();

        for (int r = 0; r < board.length; r++)
            for (int c = 0; c < board[0].length(); c++)
                all.add(r * rowLen + c);

		for (int r = 0; r < board.length; r++) {
            for (int c = 0; c < board[0].length(); c++) {
                if (board[r].charAt(c) == 'B') {
                    for (int rt = Math.max(0, r - 1); rt <= Math.min(colLen-1, r + 1); rt++) {
                        for (int ct = Math.max(0, c - 1); ct <= Math.min(rowLen-1, c + 1); ct++) {
                            all.remove(rt * rowLen + ct);
                        }
                    }
                    bombs.add(r * rowLen + c);
                }
            }
        }

		double win = all.size();

		return (win / (win + bombs.size())) * 100;
	}
}
