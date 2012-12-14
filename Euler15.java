
public class Euler15 {

    public static void main(String[] args) {
	int end = 20, count;
	long paths = 1;

	double start = System.currentTimeMillis();

	// Calculate product
	for (count = 0; count < end; count++)
	    {
		paths *= (2 * end) - count;
		paths /= count + 1;
	    }

	System.out.printf("Number of Paths: %d \n Runtime: %f", paths, System.currentTimeMillis() - start);
    }

}

// there is a O(1) solution to the probelm
