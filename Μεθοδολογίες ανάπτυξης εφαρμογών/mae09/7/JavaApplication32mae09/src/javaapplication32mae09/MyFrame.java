package javaapplication32mae09;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class MyFrame extends JFrame{

    private JTextField input1TF, input2TF, input3TF, num1TF, num2TF;
    private JButton btn, calcBtn;
    private JLabel lbl, resultLbl;
    private JComboBox operationsCb;
    
    public MyFrame() {
        this.setSize(400, 180);
        this.setTitle("Example");
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        this.setResizable(false);
        
        input1TF = new JTextField();
        input2TF = new JTextField();
        input3TF = new JTextField();
        btn = new JButton("Show");
        lbl = new JLabel("Message goes here: ");
        
        this.setLayout(null);
        
        input1TF.setBounds(20, 20, 100, 30);
        input2TF.setBounds(130, 20, 100, 30);
        input3TF.setBounds(240, 20, 100, 30);
        btn.setBounds(20, 60, 80, 30);
        lbl.setBounds(110, 60, 150, 30 );
        this.add(input1TF);
        this.add(input2TF);
        this.add(input3TF);
        this.add(btn);
        this.add(lbl);
        
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String input1 = input1TF.getText();
                String input2 = input2TF.getText();
                String input3 = input3TF.getText();
                if(!input1.isBlank() && !input2.isBlank() && !input3.isBlank()){
                    String message = input1 + "-" + input2 + "-" + input3;
                    lbl.setText(message);
                };
               
            }
        });
        
        num1TF = new JTextField();
        num2TF = new JTextField();
        calcBtn = new JButton("=");
        resultLbl = new JLabel("Result:");
        String[] operations = {"+", "-", "*", "/"};
        operationsCb = new JComboBox(operations);
        
        
        num1TF.setBounds(20, 100, 50, 30);
        operationsCb.setBounds(80, 100, 70, 30);
        num2TF.setBounds(160, 100, 50, 30);
        calcBtn.setBounds(220, 100, 70, 30);
        resultLbl.setBounds(300, 100, 40, 30 );
        this.add(num1TF);
        this.add(num2TF);
        this.add(calcBtn);
        this.add(resultLbl);
        this.add(operationsCb);
                
        calcBtn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                String num1Str = num1TF.getText();
                String num2Str = num1TF.getText();
               
                double num1 = Double.parseDouble(num1Str);
                double num2 = Double.parseDouble(num2Str);
                
                int selectedIndex = operationsCb.getSelectedIndex();
                
                double result = 0;
                
                switch(selectedIndex){
                    case 0:
                        result = num1 + num2;
                        break;
                    case 1:
                        result = num1 - num2;
                        break;
                    case 2:
                        result = num1 * num2;
                        break;
                    case 3: 
                        if(num2 != 0)
                        result = num1 / num2;
                        break;
                }
                
                resultLbl.setText(String.valueOf(result));
                
                
            }
        });
        
        this.setVisible(true);
    }
    
}