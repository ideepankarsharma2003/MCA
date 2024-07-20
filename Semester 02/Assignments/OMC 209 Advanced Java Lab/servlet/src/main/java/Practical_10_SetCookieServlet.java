import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Practical_10_SetCookieServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request,
            HttpServletResponse response)throws ServletException, IOException {
        Cookie ckname = new Cookie("studname",request.getParameter("txtstudname"));
        ckname.setMaxAge(60 * 60 * 24);

        response.addCookie(ckname);
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<!DOCTYPE HTML> " +
                "<html><head> <title>Set Cookie </title></head> " +
                "<body><center>" +
                "<h2>Cookie has been set successfully!</h2><br/>" +
                "<a href='index.html'>Click here to go back to previous page </a>" +
                "</body></html>");
    }

}