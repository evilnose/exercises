import org.junit.Test;
import static org.junit.Assert.*;

public class WordPartsTest {
	
	@Test(timeout=2000)
	public void test0() {
		String original = "ANTIDISESTABLISHMENTARIANISM";
		String compound = "ANTIDISIANISMISM";
		assertEquals(3, new WordParts().partCount(original, compound));
	}
	
	@Test(timeout=2000)
	public void test1() {
		String original = "ANTIDISESTABLISHMENTARIANISM";
		String compound = "ESTABLISHMENT";
		assertEquals(-1, new WordParts().partCount(original, compound));
	}
	
	@Test(timeout=2000)
	public void test2() {
		String original = "TOPCODERDOTCOM";
		String compound = "TOMTMODERDOTCOM";
		assertEquals(5, new WordParts().partCount(original, compound));
	}
	
	@Test(timeout=2000)
	public void test3() {
		String original = "HELLO";
		String compound = "HELLOHEHELLOLOHELLO";
		assertEquals(5, new WordParts().partCount(original, compound));
	}
	
	@Test(timeout=2000)
	public void test4() {
		String original = "DONTFORGETTHEEMPTYCASE";
		String compound = "";
		assertEquals(0, new WordParts().partCount(original, compound));
	}
	
	@Test(timeout=2000)
	public void test5() {
		String original = "BAAABA";
		String compound = "BAAABAAA";
		assertEquals(2, new WordParts().partCount(original, compound));
	}
	
	@Test(timeout=2000)
	public void test6() {
		String original = "ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB";
		String compound = "BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA";
		assertEquals(17, new WordParts().partCount(original, compound));
	}
}
