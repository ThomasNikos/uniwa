
package charachterfiles;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;


public class CharachterFiles {


    public static void main(String[] args) {
            /*try {
            BufferedWriter buffer = new BufferedWriter(new FileWriter("data.txt"));
            buffer.write("This is an example");
            buffer.newLine();
            buffer.write("Test test");
            buffer.close();
            System.out.println("Write Charachter Completed");
            } catch (IOException ex) {
            ex.getMessage();
            }*/
        try {
            BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\user\\Documents\\MAE09\\CharachterFiles\\data.txt"));
            String line;
            int count = 0;
            while(reader.ready()){
                line = reader.readLine();
                System.out.println(line);
                count++;
            }
            System.out.println("Total lines read: " + count);
        } catch (FileNotFoundException ex) {
                System.out.println(ex.getMessage());
        } catch (IOException ex) {
                System.out.println(ex.getMessage());
        }
        
        }
    }
    

