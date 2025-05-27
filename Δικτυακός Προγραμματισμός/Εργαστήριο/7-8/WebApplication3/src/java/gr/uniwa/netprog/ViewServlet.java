package gr.uniwa.netprog;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author 21390068
 */
@WebServlet(name = "ViewServlet", urlPatterns = {"/view"})//edw mou leei oti ayto to servlet antistoixei se auto to url
public class ViewServlet extends HttpServlet { //dexetai kata 99% get, post request

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<!DOCTYPE html>");
        out.println("<html>");
        out.println("<head>");
        out.println("<title>View Employees</title>");
        out.println("<style>\n"
                + " table {\n"
                + " font-family: arial, sans-serif;\n"
                + " border-collapse: collapse;\n"
                + " width: 60%;\n"
                + " }\n"
                + "\n"
                + " td, th {\n"
                + " border: 1px solid #dddddd;\n"
                + " text-align: left;\n"
                + " padding: 8px;\n"
                + " }\n"
                + "\n"
                + " tr:nth-child(even) {\n"
                + " background-color: #dddddd;\n"
                + " }\n"
                + " </style>");
        out.println("</head>");
        out.println("<body>");

        out.println("<h1>Employees List</h1>");

        List<Employee> list = EmployeeDao.getAllEmployees();

        out.print("<table border='1' width='100%'");
        out.print("<tr><th>Id</th><th>Name</th><th>Password</th><th>Email</th><th>Country</th><th>Edit</th><th>Delete</th></tr>");

        for (Employee e : list) {
            out.print("<tr>"
                    + "<td>" + e.getId() + "</td>"
                    + "<td>" + e.getName() + "</td>"
                    + "<td>" + e.getPassword() + "</td>"
                    + "<td>" + e.getEmail() + "</td>"
                    + "<td>" + e.getCountry() + "</td>"
                    + "<td><a href='./edit?id=" + e.getId() + "'>edit</a></td>"
                    + "<td><a href='./delete?id=" + e.getId() + "'>delete</a></td>"
                    + "</tr>");
        }
        out.print("</table>");
        out.println("<p><a href='./add.html'>Add New Employee</a></p>");
        out.println("<p><a href='./index.html'>Home</a></p>");
        out.println("</body>");
        out.println("</html>");

        out.close();
    }

}
