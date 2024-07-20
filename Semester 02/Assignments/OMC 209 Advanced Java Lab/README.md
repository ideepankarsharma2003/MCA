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
/**
 * Practical_01_Employee
 */
public class Practical_01_Employee {

    private int employeeNumber;
    private String name;
    private String designation;
    private double salary;

    // Parameterized constructor
    public Practical_01_Employee(int employeeNumber, String name, String designation, double salary) {
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

    public static void main(String[] args) {
        Practical_01_Employee employee= new  Practical_01_Employee(
            1, "Bruce Wayne", "Batman", 1000000000.99
        );
        employee.displayEmployeeDetails();
    }


}

    
```
---
### 2. Demonstrate method and constructor overloading
```java
public class Practical_02_MethodAndConstructorOverloading {

    public Practical_02_MethodAndConstructorOverloading() {
        System.out.println("This is the default constructor.");
    }
    public Practical_02_MethodAndConstructorOverloading(String string){
        System.out.println("This is the overloaded constructor with argument "+ string);
    }

    public void printFunction(int  x){
        System.out.println("The integer is: "+ x);
    }
    public  void  printFunction (String s){
        System.out.println("The string is: "+ s);
    }

    public static void main(String[] args) {
        Practical_02_MethodAndConstructorOverloading obj1= new Practical_02_MethodAndConstructorOverloading();
        obj1= new  Practical_02_MethodAndConstructorOverloading("Dummy String");

        obj1.printFunction(3);
        obj1.printFunction("Dummy string");

    }
    
}

```
---
### 3. Operations on a string
```java
public class Practical_03_OperationsOnString {
    public static  void  charDigitCount(String s){
        int char_count= 0;
        int digits= 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i)>=48 && s.charAt(i)<=57) digits++;
            else char_count++;
        }

        System.out.println("Length of the given string: "+ s.length());
        System.out.println("Total number of non-digit characters in the string are: "+ char_count);
        System.out.println("Total number of digit characters in the string are: "+ digits);
    }

    public static void main(String[] args) {
        Practical_03_OperationsOnString.charDigitCount("The Amazing Spiderman 3");
    }
}

```


---
### 4. Demonstrate inheritance
```java
/**
 * InnerPractical_04_Inheritance
 */
class Base{
    Base(){
        System.out.println("Base Class Constructor.");
    }
}

class LevelOneChild extends  Base{

    public LevelOneChild() {
    System.out.println("Level 1 child Constructor.");
    }
    
}

class LevelTwoChild extends  LevelOneChild{

    public LevelTwoChild() {
    System.out.println("Level 2 child Constructor.");
    }
    
}

public class Practical_04_Inheritance {
    public static void main(String[] args) {
       LevelTwoChild obj= new LevelTwoChild();
    }
}

```

---
### 5. Demonstrate method overriding
```java
class Animal{

    public void speak() {
    System.out.println("The animal makes a sound.");
    }
    
}
class Dog extends  Animal{

    public void speak() {
    System.out.println("The dog barks.");
    }
    
}


public class Practical_05_MethodOverriding {
    public static void main(String[] args) {
        Animal animal= new Animal();
        Dog dog= new Dog();
        animal.speak();
        dog.speak();
    }
}

```

---
### 6. Use of Abstract class and Interfaces
```java
interface Talkable{
    public void talk();
}

abstract class Animal{
    String name;
    public Animal(String name) {
        this.name= name;
        System.out.println("This is a "+ name+ ", an Animal.");
    }
    
    abstract void move();
}

abstract class Reptile{
    String name;
    public Reptile(String name) {
        this.name= name;
        System.out.println("This is a "+ name+ ", a Reptile.");
    }
    
    abstract void crawl();
}


class Snake extends Reptile implements  Talkable{
    public  Snake(String name){
        super(name);
    }
    @Override
    public void talk(){
        System.out.println(this.name+ " hisses.");
    }
    @Override
    public  void  crawl(){
        System.out.println(this.name+ " crawls. ");
    }
}

class Cat extends Animal implements  Talkable{
    public  Cat(String name){
        super(name);
    }
    @Override
    public void talk(){
        System.out.println(this.name+ " meows.");
    }
    @Override
    public  void  move(){
        System.err.println(this.name+ " moves.");
    }
}


public class Practical_06_AbstractClassesAndInterfaces {
    public static void main(String[] args) {
        Snake snake= new Snake("Kaala Naag");
        Cat cat= new  Cat("Persian Tommy");
        cat.move();
        snake.crawl();
        snake.talk();
        cat.talk();
    }
}
```

---
### 7. Demonstrate exception handling
```java
public class Practical_07_ExceptionHandling {
    public static void main(String[] args) {
        try {
            int[] arr = new int[5];
            arr[5] = 30 / 0;
        } catch (ArithmeticException e) {
            System.out.println(String.format("Exception occured: [[ %s ]]", e));
            System.out.println("`Arithmetic Exception` caught.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(String.format("Exception occured: [[ %s ]]", e));
            System.out.println("`Array Index Out Of Bounds Exception` caught.");
        } finally {
            System.out.println("`finally` block executed.");
        }
    }
}
```
---

### 8. Illustrate the use of I/O streams
```java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Practical_08_IOStreams {
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
