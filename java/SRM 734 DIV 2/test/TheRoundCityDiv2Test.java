import org.junit.Test;
import static org.junit.Assert.*;

public class TheRoundCityDiv2Test {
	
	@Test(timeout=2000)
	public void test0() {
		int r = 1;
		assertEquals(4, new TheRoundCityDiv2().find(r));
	}
	
	@Test(timeout=2000)
	public void test1() {
		int r = 2;
		assertEquals(12, new TheRoundCityDiv2().find(r));
	}
	
	@Test(timeout=2000)
	public void test2() {
		int r = 3;
		assertEquals(28, new TheRoundCityDiv2().find(r));
	}
	
	@Test(timeout=2000)
	public void test3() {
		int r = 47;
		assertEquals(6920, new TheRoundCityDiv2().find(r));
	}
}
