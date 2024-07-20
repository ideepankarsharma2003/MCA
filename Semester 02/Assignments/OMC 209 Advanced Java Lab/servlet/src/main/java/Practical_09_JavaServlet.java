
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Practical_09_JavaServlet extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String Studentname = request.getParameter("name");
        String Studentenrolno = request.getParameter("enrlno");
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* Response sent to Client */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title >Servlet ServletStudent</title>");
            out.println("</head>");
            out.println("<body>");

            out.println("<h3> Servlet displaying accepted Student Name and Enrolment No. </h3>");
            out.println("<h3>Student Name :" + Studentname + "</h3><br>");
            out.println("<h3>Enrollment No:" + Studentenrolno + "</h3>");
            out.println("</body>");
            out.println("</html>");
            out.println("</body>");
            out.println("</html>");
        }
    }

    @Override
    protected void doGet(HttpServletRequest request,
            HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }
}
