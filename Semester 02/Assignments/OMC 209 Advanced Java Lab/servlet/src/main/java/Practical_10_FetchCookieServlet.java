import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Practical_10_FetchCookieServlet extends HttpServlet {
        Cookie ck = null;
        Cookie[] ckary = null;

        private String searchCookie(String s) {
                for (Cookie temp : ckary) {
                        ck = temp;
                        if ((ck.getName()).compareTo(s) == 0)
                                return ck.getValue();
                }
                return "";
        }

        @Override
        protected void doPost(HttpServletRequest request,
                        HttpServletResponse response)
                        throws ServletException, IOException {
                ckary = request.getCookies();
                response.setContentType("text/html");
                PrintWriter out;
                out = response.getWriter();
                out.println("<!DOCTYPE HTML><html> <head> <title> Fetch Cookie </title></head><body><center>");
                if (ckary != null) {
                        out.println("<h2>Your cookie value is : " +
                                        searchCookie("studname") + " </h2><br/>");
                } else {
                        out.println("<h2>No Cookies found!</h2>");
                }
                out.println("<br/> " +
                                "<a href='index.html'>Click here to go back to previous page</a> " +
                                "</center></body></html>");
        }

}