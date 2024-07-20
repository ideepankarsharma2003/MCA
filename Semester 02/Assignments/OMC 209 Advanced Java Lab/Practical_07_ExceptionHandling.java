public class Practical_07_ExceptionHandling {
    public static void main(String[] args) {
        try {
            int[] arr = new int[5];
            arr[5] = 30 / 0;
        } catch (ArithmeticException e) {
            System.out.println(String.format("Exception occured: [[ %s ]]", e));
            System.out.println("`Arithmetic Exception` caught.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(String.format("Exception occured: [[ %s ]]", e));
            System.out.println("`Array Index Out Of Bounds Exception` caught.");
        } finally {
            System.out.println("`finally` block executed.");
        }
    }
}
