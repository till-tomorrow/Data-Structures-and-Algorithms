import java.util.Arrays;

public class bubbleSortExample {

    /*
    The idea of bubble sort algorithm is to repeatedly iterate through the array and compare the adjacent
    elements to each other and switch their places if they appear to be in wrong order.
    Run this class to see how it works on the example numbers array.
    */

    public static void bubbleSort(int[] numberArray) {

        int n = numberArray.length;
        int temp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (n - i); j++) {

                if (numberArray[j - 1] > numberArray[j]) {
                    temp = numberArray[j - 1];
                    numberArray[j - 1] = numberArray[j];
                    numberArray[j] = temp;
                }

            }
        }
    }

    public static void main(String[] args) {

        int[] numbers = {0, 4, 23, 5, 11, -3};
        bubbleSort(numbers);
        System.out.println(Arrays.toString(numbers));

    }


}
