package pkg2022;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {


    public static void main(String[] args) throws FileNotFoundException {
        Main reader = new Main();
        reader.readLinesFromFile();
    }

    static void readLinesFromFile() {
        try {
            BufferedReader buffer = new BufferedReader(new FileReader("grades.txt"));
            String line;
            int count = 0;

            while (buffer.ready()) {
                line = buffer.readLine();
                String[] arrOfStr = line.split(" ",0);              
            for (String a : arrOfStr){
                float theoria = 0;
                float ergastirio = 0;
                if(a.equals("ΠΑΔΑ")){
                    String[] arrOfStr1 = arrOfStr[4].split(":",0);
                    if(arrOfStr.length==6){
                    String[] arrOfStr2 = arrOfStr[5].split(":",0);
                    if(arrOfStr2[0].equals("Θ")){
                        theoria =  Float.parseFloat(arrOfStr2[1]);
                    }
                    if(arrOfStr2[0].equals("Ε")){
                        ergastirio =  Float.parseFloat(arrOfStr2[1]);
                    }
                    }
                    if(arrOfStr1[0].equals("Θ")){
                    theoria = Float.parseFloat(arrOfStr1[1]);
                    }
                    if(arrOfStr1[0].equals("Ε")){
                    ergastirio =  Float.parseFloat(arrOfStr1[1]);
                    }
                    FileWriter writer = new FileWriter ("ΠΑΔΑ.txt", true);
                    BufferedWriter pada = new BufferedWriter(writer);
                    pada.write(arrOfStr[2] + " " + (float)(theoria*0.7 + ergastirio*0.3) + "\n");
                    pada.close();
                }
                if(a.equals("ΤΕΙ-Α-Ν1")){
                    FileWriter writer = new FileWriter ("ΤΕΙΑΝ1Θ.txt", true);
                    BufferedWriter file = new BufferedWriter(writer);
                    file.write(arrOfStr[0] + " " + arrOfStr[1] + " " + arrOfStr[2] + " " + arrOfStr[3] + " " + arrOfStr[4] + "\n");
                    file.close();
                    FileWriter writer1 = new FileWriter ("ΤΕΙΑΝ1Ε.txt", true);
                    BufferedWriter file1 = new BufferedWriter(writer1);
                    file1.write(arrOfStr[0] + " " + arrOfStr[1] + " " + arrOfStr[2] + " " + arrOfStr[3] + " " + arrOfStr[5] + "\n");
                    file1.close();
                }
                if(a.equals("ΤΕΙ-Α-Ν2")){
                    FileWriter writer = new FileWriter ("ΤΕΙΑΝ2Θ.txt", true);
                    BufferedWriter file = new BufferedWriter(writer);
                    file.write(arrOfStr[0] + " " + arrOfStr[1] + " " + arrOfStr[2] + " " + arrOfStr[3] + " " + arrOfStr[4] + "\n");
                    file.close();
                    FileWriter writer1 = new FileWriter ("ΤΕΙΑΝ2Ε.txt", true);
                    BufferedWriter file1 = new BufferedWriter(writer1);
                    file1.close();
                }
                if(a.equals("ΤΕΙ-Π")){
                    FileWriter writer = new FileWriter ("ΤΕΙΠΘ.txt", true);
                    BufferedWriter file = new BufferedWriter(writer);
                    file.write(arrOfStr[0] + " " + arrOfStr[1] + " " + arrOfStr[2] + " " + arrOfStr[3] + " " + arrOfStr[4] + "\n");
                    file.close();
                    FileWriter writer1 = new FileWriter ("ΤΕΙΠΕ.txt", true);
                    BufferedWriter file1 = new BufferedWriter(writer1);
                    file1.close();
                }
                }
            }
            buffer.close();

        } catch (FileNotFoundException ex) {
            System.err.println(ex.getMessage());
        } catch (IOException ex) {
            System.err.println(ex.getMessage());
        }
    }



}