
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.GenericServlet;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;

public class DemoServlet extends  GenericServlet{
    @Override
    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        // TODO Auto-generated method stub
        String name= req.getParameter("username");
        PrintWriter pw= res.getWriter();
        pw.println("<html><body>");
        pw.println("Hello,  "+ name);
        pw.println("</html></body>");

    }
}
