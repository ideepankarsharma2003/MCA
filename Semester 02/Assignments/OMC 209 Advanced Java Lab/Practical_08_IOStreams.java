import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Practical_08_IOStreams {
    public static void main(String[] args) throws IOException {
        // Writing to a file
        FileOutputStream fileOut = new FileOutputStream("test.txt");
        String s = "Hello, this is a test.";
        byte[] b = s.getBytes();
        fileOut.write(b);
        fileOut.close();

        // Reading from a file
        FileInputStream fileIn = new FileInputStream("test.txt");
        int i;
        while ((i = fileIn.read()) != -1) {
            System.out.print((char) i);
        }
        fileIn.close();
    }
}
