package newpackage;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

/**
 *
 * @author ice21390068
 */

public class EchoServer {

    static final int SERVER_PORT = 9991;

    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(SERVER_PORT);
            System.out.println("Server is now operating.");
            
            while(true){
                System.out.println("----------------------");
                System.out.println("Waiting for client...");
                Socket socket = serverSocket.accept();
                
                System.out.println("Client accepted");
                System.out.println("Local socket: " + socket.getLocalSocketAddress());
                System.out.println("Remote socket: " + socket.getRemoteSocketAddress());
                System.out.println("----------------------");
                
                Scanner input = new Scanner(socket.getInputStream());
                PrintWriter output = new PrintWriter(socket.getOutputStream(), true); //true = Auto Flushing
                
                output.println("Welcome to EchoServer");
                
                while(true){
                    if(!input.hasNextLine()){
                        System.out.println("Client is not responding");
                        break;
                    }
                    String line = input.nextLine();
                    
                    if(line.equalsIgnoreCase("exit")){
                        System.out.println("Client requested exit");
                        output.println("bye from server");
                        break;
                    }else{
                        System.out.println("Client says: " + line);
                        output.println("Server says: " + line);
                    }                                        
                }
                
                System.out.println("Terminate connection...");
                socket.close();
                System.out.println("Connection closed");
                
            }
        } catch (IOException ex) {
            System.out.println(ex);
        }
    }

}
