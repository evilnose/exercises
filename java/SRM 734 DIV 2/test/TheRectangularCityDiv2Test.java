import org.junit.Test;

import static org.junit.Assert.*;

public class TheRectangularCityDiv2Test {

    @Test(timeout = 2000)
    public void test0() {
        String[] city = new String[]{
                "....",
                ".##.",
                "...."
        };
        assertEquals(20L, new TheRectangularCityDiv2().find(city));
    }

    @Test(timeout = 2000)
    public void test1() {
        String[] city = new String[]{
                "....",
                ".###",
                "...."
        };
        assertEquals(2L, new TheRectangularCityDiv2().find(city));
    }

    @Test(timeout = 2000)
    public void test2() {
        String[] city = new String[]{
                "....",
                "####",
                "...."
        };
        assertEquals(0L, new TheRectangularCityDiv2().find(city));
    }

    @Test(timeout = 2000)
    public void test3() {
        String[] city = new String[]{
                "....",
                "....",
                "...."
        };
        assertEquals(80L, new TheRectangularCityDiv2().find(city));
    }

    @Test(timeout = 2000)
    public void test4() {
        String[] city = new String[]{
                "....."
        };
        assertEquals(2L, new TheRectangularCityDiv2().find(city));
    }
}
