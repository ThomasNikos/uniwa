package newpackage;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

/**
 *
 * @author ice21390068
 */

public class EchoClient {
    
    static final int SERVER_PORT = 9991;
    static final String SERVER_HOST = "localhost";
    
    public static void main(String[] args) {
        try {
            Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
            
            System.out.println("----------------------");
            System.out.println("Client accepted");
            System.out.println("Local socket: " + socket.getLocalSocketAddress());
            System.out.println("Remote socket: " + socket.getRemoteSocketAddress());
            System.out.println("----------------------");
            
            Scanner input = new Scanner(socket.getInputStream());
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true); //true = Auto Flushing
            
            System.out.println(input.nextLine());
            
            Scanner userInput = new Scanner(System.in);
            String message = "";
            String received = "";
            while(true){
                System.out.print("Enter your message: ");
                message = userInput.nextLine();
                
                output.println(message);
                
                if(!input.hasNextLine()){
                    System.out.println("Server is not responding");
                    break;
                }
                
                received = input.nextLine();
                System.out.println(received);
                
                if(message.equalsIgnoreCase("exit")){
                    break;
                }
                           
            }
            
            System.out.println("Terminate connection...");
            socket.close();
            System.out.println("Connection close");
            
        } catch (IOException ex) {
            System.out.println(ex);
        }
    }
    
    
}
