package javaapplication41;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class MyFrame extends JFrame{

    private JTextField field1;
    private JLabel label1;
    private JTextArea area;
    private JButton clearBtn, addTextBtn, selectBtn;
    
    
    public MyFrame() {
        this.setSize(500, 500);
        this.setTitle("Exanple");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        field1 = new JTextField(10);
        label1 = new JLabel("Text: ");
               
        JPanel topPanel = new JPanel();
        topPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
        topPanel.add(label1);
        topPanel.add(field1);
               
        area = new JTextArea();
        area.setLineWrap(true);
        this.add(area);
        
        clearBtn = new JButton("Clear");
        addTextBtn = new JButton("Add Text");
        selectBtn = new JButton("Select");
        
        JPanel bottomPanel = new JPanel();
        bottomPanel.add(clearBtn);
        bottomPanel.add(selectBtn);
        topPanel.add(addTextBtn);
        
        this.add(topPanel, BorderLayout.NORTH);
        this.add(bottomPanel, BorderLayout.SOUTH);
        
        addTextBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
               String text = field1.getText();
               if(text.isEmpty()){
                    JOptionPane.showMessageDialog(MyFrame.this, "No input provided.", "Error", JOptionPane.ERROR_MESSAGE);
               } else{
                    area.append(text + "\n");
               }
            }
        });
        clearBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                area.setText("");
                field1.setText("");
            }
        });
        selectBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selected = area.getSelectedText();
                if (!selected.isEmpty()){
                    JOptionPane.showMessageDialog(MyFrame.this, selected, "Selected Text", JOptionPane.INFORMATION_MESSAGE);
                }else {
                    JOptionPane.showMessageDialog(MyFrame.this, "Nothing Selected", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        
        this.setVisible(true);
        
        
    }
    
}