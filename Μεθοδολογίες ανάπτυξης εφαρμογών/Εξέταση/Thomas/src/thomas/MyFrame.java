package thomas;

import java.awt.TextArea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 *
 * @author user
 */
public class MyFrame extends JFrame {

    private JButton insertbtn, erasebtn, savebtn, exitbtn; 
    private JTextField input1TF, input2TF, input3TF, input4TF;
    private TextArea txt;
    private JLabel msglbl;
    private int fullprice = 0;
            
    
    public MyFrame() {
        this.setSize(480, 420);
        this.setTitle("Application");
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        insertbtn = new JButton("Insert");
        erasebtn = new JButton("Erase");
        savebtn = new JButton("Save");
        exitbtn = new JButton("Exit"); 
        input1TF = new JTextField();
        input2TF = new JTextField();
        input3TF = new JTextField();
        input4TF = new JTextField();
        txt = new TextArea();
        msglbl = new JLabel("Price: ");
        
        insertbtn.setBounds(20, 20, 100, 30);
        erasebtn.setBounds(130, 20, 100, 30);
        savebtn.setBounds(240, 20, 100, 30);
        exitbtn.setBounds(20, 330, 100, 30);
        input1TF.setBounds(20, 65, 100, 30);
        input2TF.setBounds(120, 65, 100, 30);
        input3TF.setBounds(220, 65, 100, 30);
        input4TF.setBounds(320, 65, 100, 30);
        txt.setBounds(20, 110, 400, 200);
        msglbl.setBounds(350, 20, 100, 30);


        
        this.add(insertbtn);
        this.add(erasebtn);
        this.add(savebtn);
        this.add(exitbtn);        
        this.add(input1TF);
        this.add(input2TF);
        this.add(input3TF);
        this.add(input4TF);
        this.add(txt);
        this.add(msglbl);
        
        insertbtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String ak = input1TF.getText(); 
                String make = input2TF.getText(); 
                String color = input3TF.getText(); 
                String price = input4TF.getText(); 
                if(!ak.isEmpty()&&!make.isEmpty()&&!color.isEmpty()&&!price.isEmpty()){
                    String line = ak + "-" + make + "-" + color + "-" + price;
                    txt.append(line + "\n");
                    /*fullprice += price;
                     msglbl.setText(fullprice);*/
                }

                
            }
        });
        
        erasebtn.addActionListener (new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input1TF.setText("");
                input2TF.setText("");
                input3TF.setText("");
                input4TF.setText("");
            }
        });
        
        savebtn.addActionListener (new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    FileOutputStream output = new FileOutputStream("cars.txt", true);
                    byte[] data = txt.getText().getBytes();
                    output.write(data);
                    output.close();
                } catch (FileNotFoundException ex) {
                    Logger.getLogger(MyFrame.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    Logger.getLogger(MyFrame.class.getName()).log(Level.SEVERE, null, ex);
                }
                
            }
        });
        
        exitbtn.addActionListener (new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
              int i = JOptionPane.showConfirmDialog(null, "Exit the app?");
              if(i==JOptionPane.YES_OPTION)
                  System.exit(0);
              else if(i==JOptionPane.CANCEL_OPTION)
                  msglbl.setText("CANCEL");
              else if(i==JOptionPane.NO_OPTION)
                  msglbl.setText("NO");                     
                
            }
        });      
        
        this.setVisible(true);
    }
    
    
    
}
