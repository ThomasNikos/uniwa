package javaapplication10;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class JavaApplication10 {

    public static void main(String[] args) {

            /*byte[] data = "This is an example ".getBytes();
            try {
            FileOutputStream output = new FileOutputStream("data.txt", true);
            output.write(data);
            output.close();
            System.out.println("Bytes written: " + data.length);
            } catch (FileNotFoundException ex) {
            System.err.println(ex.getMessage());
            } catch (IOException ex) {
            
            }
            */
        try {
            FileInputStream input = new FileInputStream("data.txt");
            
            int c, count = 0;
            while((c = input.read()) != -1){
                System.out.println(c);
                count++;
            }
            
            input.close();
            System.out.println("Total Bytes Read: " + count);
        } catch (FileNotFoundException ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
        
    }
    
}
