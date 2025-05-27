package newpackage;

import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Scanner;

/**
 *
 * @author 21390068
 */

public class InsertRow {
    
    static final String DB_DRIVER = "org.mariadb.jdbc.Driver";
    static final String DB_URL = "jdbc:mariadb://localhost:3306/netprog_db_21390068";
    static final String DB_USER = "netprog_db_21390068";
    static final String DB_PASS = "1234";
    
    public static void main(String[] args) {
    
        try {
            Class.forName(DB_DRIVER);
            Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS);

            Scanner input = new Scanner(System.in);
            System.out.print("Give the first name: ");
            String firstname = input.nextLine();
            System.out.println("Give the last name: ");
            String lastname = input.nextLine();

            String SQL_query = "INSERT INTO users" + "(firstname, lastname) VALUES ('" + firstname + "', '" + lastname + "')";  
            System.out.println(SQL_query);
            
            Statement st = conn.createStatement();
            int affected = st.executeUpdate(SQL_query);
            System.out.println("Rows affected: " + affected);
            
            st.close();
            conn.close();
                     
        } catch (ClassNotFoundException ex) {
            System.out.println(ex);
        } catch (SQLException ex) {
            System.out.println(ex);
        }
        
    }
    
}