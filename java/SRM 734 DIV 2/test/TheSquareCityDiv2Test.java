import org.junit.Test;
import static org.junit.Assert.*;

public class TheSquareCityDiv2Test {
	
	@Test(timeout=2000)
	public void test0() {
		int r = 1;
		int[] t = new int[] {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
};
		assertArrayEquals(new int[] {4, 4 }, new TheSquareCityDiv2().find(r, t));
	}
	
	@Test(timeout=2000)
	public void test1() {
		int r = 2;
		int[] t = new int[] {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
};
		assertArrayEquals(new int[] {2, 6 }, new TheSquareCityDiv2().find(r, t));
	}
	
	@Test(timeout=2000)
	public void test2() {
		int r = 7;
		int[] t = new int[] {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
};
		assertArrayEquals(new int[] {1, 9 }, new TheSquareCityDiv2().find(r, t));
	}
	
	@Test(timeout=2000)
	public void test3() {
		int r = 3;
		int[] t = new int[] {
59, 22,  2, 17, 77, 43, 67, 
16, 49, 51, 46, 61,  4,  9, 
42, 12, 80, 82, 24, 29,  1, 
27, 63, 65, 26, 10, 28, 83, 
 7, 73,  8, 47, 37, 23, 38, 
75, 54, 71, 58, 78, 21, 45, 
35, 81, 48, 41, 44, 52, 32
};
		assertArrayEquals(new int[] {5, 20 }, new TheSquareCityDiv2().find(r, t));
	}
}
