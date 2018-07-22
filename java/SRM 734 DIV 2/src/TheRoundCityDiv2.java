import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class TheRoundCityDiv2 {
	
	public int find(int r) {
	    int c = -1;
	    for (int x = -r; x <= r; x++)
	        for (int y = r*r-x*x; y>=-r;y--)
	            if (x*x + y*y <= r*r)
	                c++;
		return c;
	}
}
