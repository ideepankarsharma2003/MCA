import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Practical_11_GetPostServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request,
            HttpServletResponse response)
            throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        response.setContentType("text/html");
        String code = request.getParameter("txtmsg");
        out.println("<h2> In GET Method. Check URL.</h2>");
        out.println("<h3> Your message is : " + code + "</h3>");
    }

    @Override
    protected void doPost(HttpServletRequest request,
            HttpServletResponse response)
            throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        response.setContentType("text/html");
        String code = request.getParameter("txtmsg");
        out.println("<h2>In POST Method. Check URL.</h2>");
        out.println("<h3> Your message is : " + code + "</h3>");
    }

}
