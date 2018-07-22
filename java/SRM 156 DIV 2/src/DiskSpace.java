import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class DiskSpace {
	
	public int minDrives(int[] used, int[] total) {
		int sum = 0;
		for (int d : used)
		    sum += d;

		Arrays.sort(total);
		for (int i = total.length - 1; i >= 0; i--) {
		    sum -= total[i];
		    if (sum <= 0)
		        return total.length - i;
        }
        return -1;
	}
}
