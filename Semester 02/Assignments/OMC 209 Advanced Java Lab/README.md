# Advanced Java Programming Laboratory - Program List
1. Create a Java class “Employee” with the attributes - employee number, name, designation and salary.
a. Implement methods to set and display these attributes
b. Implement parameterized constructors for initializing these attributes.
Use “this” keyword to illustrate the difference between instance variable and constructor parameters. Display these attributes.
2. Write a Java program to demonstrate method overloading and constructor overloading.
3. Write a Java program to perform the following operations on a string.
    a. Count the number of characters and digits.
    b. Check whether the given string is palindrome or not.
4. Write a Java program to demonstrate single and multi-level inheritance. Display the order of execution of constructors in multi-level inheritance.
5. Write a Java program to demonstrate method overriding.
6. Write a Java program to illustrate the use of
        a. Abstract class
        b. Interfaces in Java

7. Write a Java program to demonstrate exception handling. Show the order of execution of “try”, “catch” and “finally” blocks when an exception occurs and when it does not occur during the execution by providing appropriate inputs during execution and displaying messages.
8. Write a Java program to illustrate the use of I/O streams.
9. Write a Java Servlet program to implement a dynamic HTML using Servlet( Student name and enrolment number should be accepted using HTML and displayed using a Servlet).
10. Write a Java Servlet program to demonstrate the use of cookies.
11. Write a Java Servlet program to demonstrate the use of GET and POST methods for handling HTTP client requests and server responses.
12. Write a JSP program to demonstrate the use of Java Beans.


---

### 1. Create a Java class “Employee”
```java
public class Employee {
    private int employeeNumber;
    private String name;
    private String designation;
    private double salary;

    // Parameterized constructor
    public Employee(int employeeNumber, String name, String designation, double salary) {
        this.employeeNumber = employeeNumber;
        this.name = name;
        this.designation = designation;
        this.salary = salary;
    }

    // Methods to set and display attributes
    public void setEmployeeDetails(int employeeNumber, String name, String designation, double salary) {
        this.employeeNumber = employeeNumber;
        this.name = name;
        this.designation = designation;
        this.salary = salary;
    }

    public void displayEmployeeDetails() {
        System.out.println("Employee Number: " + employeeNumber);
        System.out.println("Name: " + name);
        System.out.println("Designation: " + designation);
        System.out.println("Salary: $" + salary);
    }
}
```

### 2. Demonstrate method and constructor overloading
```java
public class OverloadDemo {
    // Constructor overloading
    public OverloadDemo() {
        System.out.println("Default Constructor");
    }

    public OverloadDemo(String name) {
        System.out.println("Constructor with one argument: " + name);
    }

    // Method overloading
    void demo(int a) {
        System.out.println("a: " + a);
    }

    void demo(int a, int b) {
        System.out.println("a and b: " + a + "," + b);
    }

    double demo(double a) {
        return a*a;
    }
}
```

### 3. Operations on a string
```java
public class StringOperations {
    public void performOperations(String input) {
        countCharactersAndDigits(input);
        checkPalindrome(input);
    }

    private void countCharactersAndDigits(String input) {
        int letters = 0, digits = 0;
        for (char c : input.toCharArray()) {
            if (Character.isLetter(c)) {
                letters++;
            } else if (Character.isDigit(c)) {
                digits++;
            }
        }
        System.out.println("Letters: " + letters + ", Digits: " + digits);
    }

    private void checkPalindrome(String input) {
        String reverse = new StringBuilder(input).reverse().toString();
        if (input.equals(reverse)) {
            System.out.println(input + " is a palindrome.");
        } else {
            System.out.println(input + " is not a palindrome.");
        }
    }
}
```

### 4. Demonstrate inheritance
```java
class Base {
    Base() {
        System.out.println("Base Constructor");
    }
}

class Derived extends Base {
    Derived() {
        System.out.println("Derived Constructor");
    }
}

class DerivedLevelTwo extends Derived {
    DerivedLevelTwo() {
        System.out.println("Derived Level Two Constructor");
    }
}
```

### 5. Demonstrate method overriding
```java
class Animal {
    void speak() {
        System.out.println("The animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    void speak() {
        System.out.println("The dog barks");
    }
}
```

### 6. Use of Abstract class and Interfaces
```java
// Abstract class
abstract class Shape {
    abstract void draw();
}

class Rectangle extends Shape {
    @Override
    void draw() {
        System.out.println("Drawing a rectangle");
    }
}

// Interface
interface AnimalInterface {
    void eat();
}

class Cat implements AnimalInterface {
    public void eat() {
        System.out.println("Cat eats");
    }
}
```

### 7. Demonstrate exception handling
```java
public class ExceptionDemo {
    void execute() {
        try {
            int[] arr = new int[5];
            arr[5] = 30 / 0;
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic Exception caught");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array Index Out Of Bounds Exception caught");
        } finally {
            System.out.println("finally block executed");
        }
    }
}
```

### 8. Illustrate the use of I/O streams
```java
import java.io.*;

public class IOStreamsDemo {
    public static void main(String[] args) throws IOException {
        // Writing to a file
        FileOutputStream fileOut = new FileOutputStream("test.txt");
        String s = "Hello, this is a test.";
        byte[] b = s.getBytes();
        fileOut.write(b);
        fileOut.close();

        // Reading from a file
        FileInputStream fileIn = new FileInputStream("test.txt");
        int i;
        while ((i = fileIn.read()) != -1) {
            System.out.print((char) i);
        }
        fileIn.close();
    }
}
```

### 9. Java Servlet for dynamic HTML
```java
// Servlet code
public class StudentServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        String name = request.getParameter("name");
        String enrollment = request.getParameter("enrollment");
        out.println("<html><body>");
        out.println("<h1>Hello, " + name + "</h1>");
        out.println("<h2>Your enrollment number is " + enrollment + "</h2>");
        out.println("</body></html>");
    }
}
```
HTML Form:
```html
<!-- HTML code -->
<html>
<body>
<form action="StudentServlet" method="get">
    Name: <input type="text" name="name"><br>
    Enrollment Number: <input type="text" name="enrollment"><br>
    <input type="submit" value="Submit">
</form>
</body>
</html>
```

### 10. Demonstrate the use of cookies in Servlet
```java
public class CookieServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // Create cookies
        Cookie cookie = new Cookie("user", "Java Developer");
        response.addCookie(cookie);

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("Cookie set for user.");
        out.println("</body></html>");
    }
}
```

### 11. Use of GET and POST methods
```java
// Handling GET and POST in the same servlet
public class MethodServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        processRequest(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        processRequest(request, response);
    }

    private void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("Request handled using " + request.getMethod() + " method.");
        out.println("</body></html>");
    }
}
```

### 12. Use of Java Beans in JSP
```jsp
<!-- JSP file -->
<%@ page import="java.beans.*" %>
<%
    BeanInfo info = Introspector.getBeanInfo(SomeBean.class);
    PropertyDescriptor[] propertyDescriptors = info.getPropertyDescriptors();
    for (PropertyDescriptor pd : propertyDescriptors) {
        out.println("Property: " + pd.getName());
    }
%>
```
