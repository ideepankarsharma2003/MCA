# **Advanced Java Programming - Detailed Unit-wise Notes**

---

## **Unit 1: Java Classes**

### **1. Introduction to Object-Oriented Programming (OOP) in Java**
- **Classes and Objects**
  - **Class**: A blueprint for creating objects. It defines properties (fields) and behaviors (methods).
  - **Object**: An instance of a class containing actual values.

### **2. Defining Classes**
- **Syntax**:
  ```java
  public class ClassName {
      // fields
      // methods
  }
  ```
- **Constructors**:
  - Special methods used to initialize objects.
  - **Types**:
    - **Default Constructor**: No parameters.
    - **Parameterized Constructor**: Takes arguments to set initial values.

### **3. Member Variables and Methods**
- **Fields**: Variables declared within a class.
- **Methods**: Functions defined inside a class to perform actions.

### **4. Object Creation and Usage**
- **Instantiation**:
  ```java
  ClassName obj = new ClassName();
  ```
- **Accessing Members**:
  - Use the dot (`.`) operator: `obj.field` or `obj.method()`.

### **5. Static Members**
- **Static Variables and Methods**:
  - Belong to the class rather than any object instance.
  - Accessed using the class name: `ClassName.staticMethod()`.

### **6. Access Modifiers**
- **public**: Accessible from any other class.
- **private**: Accessible only within the declared class.
- **protected**: Accessible within the same package or subclasses.
- **Default (Package-private)**: Accessible within the same package.

### **7. Inner Classes**
- **Member Inner Class**: Defined within another class.
- **Static Nested Class**: Declared static; can be accessed without an instance of the outer class.
- **Anonymous Inner Class**: Defined and instantiated in a single statement.

### **8. Method Overloading**
- **Concept**: Multiple methods with the same name but different parameters.
- **Rules**:
  - Different number or type of parameters.
  - Return type is not considered for overloading.

### **9. 'this' and 'super' Keywords**
- **this**:
  - Refers to the current object.
  - Used to resolve naming conflicts and invoke constructors.
- **super**:
  - Refers to the parent class object.
  - Used to access superclass methods and constructors.

---

## **Unit 2: Arrays and String Handling**

### **1. Arrays in Java**
- **Declaration and Initialization**:
  ```java
  int[] arr = new int[10];
  int[] arr = {1, 2, 3, 4, 5};
  ```
- **Types**:
  - **Single-dimensional Arrays**: A list of elements.
  - **Multi-dimensional Arrays**: Arrays of arrays (e.g., 2D arrays).

### **2. Array Manipulation**
- **Traversing Arrays**:
  - Using loops (`for`, `foreach`).
- **Common Operations**:
  - Copying arrays.
  - Sorting arrays (`Arrays.sort(arr)`).
  - Searching elements.

### **3. String Handling**
- **String Class**:
  - Immutable sequence of characters.
  - Common methods: `length()`, `charAt()`, `substring()`, `concat()`.
- **StringBuffer and StringBuilder**:
  - **StringBuffer**: Mutable and thread-safe.
  - **StringBuilder**: Mutable but not thread-safe.
  - Methods: `append()`, `insert()`, `delete()`, `reverse()`.

### **4. String Formatting and Regular Expressions**
- **String Formatting**:
  - `String.format("format string", args)`
  - Example: `String.format("Name: %s", name)`
- **Regular Expressions**:
  - Pattern matching using `Pattern` and `Matcher` classes.

### **5. Command-line Arguments**
- **Passing Arguments**:
  - Arguments passed to `main(String[] args)` method.
- **Accessing Arguments**:
  ```java
  public static void main(String[] args) {
      for (String arg : args) {
          System.out.println(arg);
      }
  }
  ```

---

## **Unit 3: Inheritance**

### **1. Concept of Inheritance**
- **Purpose**: To acquire properties and behaviors from an existing class.
- **Benefits**:
  - Code reusability.
  - Method overriding for dynamic behavior.

### **2. Implementing Inheritance in Java**
- **Syntax**:
  ```java
  class SubClass extends SuperClass {
      // additional fields and methods
  }
  ```
- **Method Overriding**:
  - Redefining a superclass method in the subclass.
  - **Annotation**: `@Override`

### **3. Types of Inheritance in Java**
- **Single Inheritance**: One superclass and one subclass.
- **Multilevel Inheritance**: A subclass derived from another subclass.
- **Hierarchical Inheritance**: Multiple subclasses derived from a single superclass.

### **4. Polymorphism**
- **Compile-time Polymorphism**: Method overloading.
- **Runtime Polymorphism**: Method overriding.
- **Dynamic Method Dispatch**:
  - Determining the method to invoke at runtime based on the object type.

### **5. Abstract Classes and Methods**
- **Abstract Class**:
  - Cannot be instantiated.
  - May contain abstract methods (without implementation).
- **Abstract Method**:
  - Declared without an implementation.
  - Must be overridden in subclasses.

---

## **Unit 4: Interfaces and Packages**

### **1. Interfaces in Java**
- **Definition**:
  - A contract specifying methods that a class must implement.
- **Syntax**:
  ```java
  public interface InterfaceName {
      // abstract methods
  }
  ```
- **Implementing Interfaces**:
  ```java
  public class ClassName implements InterfaceName {
      // implementation of methods
  }
  ```
- **Functional Interfaces**:
  - Interfaces with a single abstract method.
  - Used with lambda expressions.

### **2. Packages**
- **Purpose**:
  - Organize classes into namespaces.
  - Avoid naming conflicts.
- **Creating Packages**:
  - Use the `package` keyword at the top of the Java file.
  - Example: `package com.example.myapp;`
- **Using Packages**:
  - Import classes using the `import` statement.

### **3. Access Modifiers with Packages**
- **Default Access**:
  - Accessible within the same package.
- **Protected Access**:
  - Accessible within the same package and subclasses.

---

## **Unit 5: Exception Handling and Overview of Threads**

### **1. Exception Handling**
- **Types of Exceptions**:
  - **Checked Exceptions**: Must be declared or handled (e.g., `IOException`).
  - **Unchecked Exceptions**: Runtime exceptions (e.g., `NullPointerException`).
- **Keywords**:
  - **try**: Encloses code that might throw an exception.
  - **catch**: Handles the exception.
  - **finally**: Executes code regardless of exception occurrence.
  - **throw**: Used to explicitly throw an exception.
  - **throws**: Declares an exception in method signature.
- **Custom Exceptions**:
  - Create by extending `Exception` or `RuntimeException`.

### **2. Overview of Threads**
- **Multithreading**:
  - Running multiple threads simultaneously.
- **Creating Threads**:
  - **Extending Thread Class**:
    ```java
    public class MyThread extends Thread {
        public void run() {
            // code
        }
    }
    ```
  - **Implementing Runnable Interface**:
    ```java
    public class MyRunnable implements Runnable {
        public void run() {
            // code
        }
    }
    ```
- **Thread Lifecycle**:
  - New → Runnable → Running → Blocked/Waiting → Terminated
- **Synchronization Basics**:
  - Preventing thread interference and memory consistency errors.
  - Use `synchronized` keyword for methods or blocks.

---

## **Unit 6: Overview of Java I/O Streams, Networking, and Event Handling**

### **1. Java I/O Streams**
- **Byte Streams**:
  - Handle input and output of bytes.
  - Classes: `InputStream`, `OutputStream`.
- **Character Streams**:
  - Handle input and output of characters.
  - Classes: `Reader`, `Writer`.
- **File Handling**:
  - Reading from and writing to files using streams.

### **2. Networking in Java**
- **Sockets**:
  - Endpoints for communication between two machines.
- **ServerSocket and Socket Classes**:
  - **ServerSocket**: Waits for requests from clients.
  - **Socket**: Connects to server socket.
- **Client-Server Communication**:
  - Establish connection, read/write data, close connection.

### **3. Event Handling**
- **Event Delegation Model**:
  - Event source generates an event.
  - Event listener handles the event.
- **Components**:
  - **Event Source**: Object that generates events.
  - **Event Listener**: Interface that receives and processes events.
- **Common Event Listeners**:
  - `ActionListener`, `MouseListener`, `KeyListener`.

---

## **Unit 7: Servlets**

### **1. Introduction to Servlets**
- **Definition**:
  - Java programs that run on a server to handle client requests and generate dynamic web content.
- **Servlet Lifecycle Methods**:
  - **init()**: Initializes the servlet.
  - **service()**: Handles requests and generates responses.
  - **destroy()**: Called before the servlet is destroyed.

### **2. Developing Servlets**
- **Environment Setup**:
  - Install a servlet container (e.g., Apache Tomcat).
- **Writing a Servlet**:
  - Extend `HttpServlet` class.
  - Override `doGet()` or `doPost()` methods.
- **Deployment**:
  - Package servlet classes into a WAR file.
  - Configure in `web.xml` or use annotations.

### **3. ServletConfig and ServletContext**
- **ServletConfig**:
  - Contains configuration information for a single servlet.
  - Accessed via `getServletConfig()`.
- **ServletContext**:
  - Shared information across the entire web application.
  - Accessed via `getServletContext()`.

---

## **Unit 8: Handling Client Requests and Servlet Responses**

### **1. HTTP Protocol Basics**
- **HTTP Methods**:
  - **GET**: Retrieves data.
  - **POST**: Sends data to the server.

### **2. Handling Requests**
- **HttpServletRequest Interface**:
  - Methods to read request data: `getParameter()`, `getInputStream()`.
  - Retrieve headers, cookies, and session information.

### **3. Generating Responses**
- **HttpServletResponse Interface**:
  - Methods to set response data: `setContentType()`, `getWriter()`.
  - Redirecting: `sendRedirect()`.
  - Forwarding: Using `RequestDispatcher`.

### **4. Setting Response Content Type**
- **Example**:
  ```java
  response.setContentType("text/html");
  ```

---

## **Unit 9: Cookies and Sessions**

### **1. State Management**
- **Challenge**: HTTP is stateless; each request is independent.

### **2. Cookies**
- **Definition**:
  - Small pieces of data stored on the client side.
- **Creating Cookies**:
  ```java
  Cookie cookie = new Cookie("name", "value");
  response.addCookie(cookie);
  ```
- **Reading Cookies**:
  ```java
  Cookie[] cookies = request.getCookies();
  ```

### **3. Session Tracking**
- **HttpSession Interface**:
  - Manages user-specific data on the server side.
- **Creating a Session**:
  ```java
  HttpSession session = request.getSession();
  ```
- **Storing Data in Session**:
  ```java
  session.setAttribute("key", value);
  ```
- **Retrieving Data**:
  ```java
  Object value = session.getAttribute("key");
  ```

---

## **Unit 10: Introduction to JSP, JavaBeans, and JDBC**

### **1. JavaServer Pages (JSP)**
- **Purpose**:
  - Simplify the creation of dynamic web pages.
- **JSP Lifecycle**:
  - Translation → Compilation → Initialization → Execution → Cleanup.
- **Scripting Elements**:
  - **Expressions**: `<%= expression %>`
  - **Scriptlets**: `<% code %>`
  - **Declarations**: `<%! code %>`
- **Directives**:
  - **Page Directive**: `<%@ page ... %>`
  - **Include Directive**: `<%@ include file="..." %>`
  - **Taglib Directive**: `<%@ taglib uri="..." prefix="..." %>`

### **2. JavaBeans**
- **Definition**:
  - Reusable software components that follow certain conventions.
- **Conventions**:
  - Must have a no-arg constructor.
  - Properties accessed via getter and setter methods.
- **Using JavaBeans in JSP**:
  ```jsp
  <jsp:useBean id="beanId" class="com.example.BeanClass" scope="page"/>
  <jsp:getProperty name="beanId" property="propertyName"/>
  <jsp:setProperty name="beanId" property="propertyName" value="value"/>
  ```

### **3. Java Database Connectivity (JDBC)**
- **Purpose**:
  - Connect Java applications to a database.
- **Steps to Connect to a Database**:
  1. **Load the JDBC Driver**:
     ```java
     Class.forName("com.mysql.jdbc.Driver");
     ```
  2. **Establish Connection**:
     ```java
     Connection con = DriverManager.getConnection(url, user, password);
     ```
  3. **Create Statement**:
     ```java
     Statement stmt = con.createStatement();
     ```
  4. **Execute Query**:
     ```java
     ResultSet rs = stmt.executeQuery("SELECT * FROM table");
     ```
  5. **Process Results**:
     ```java
     while (rs.next()) {
         // retrieve data
     }
     ```
  6. **Close Connections**:
     ```java
     rs.close();
     stmt.close();
     con.close();
     ```
- **PreparedStatement**:
  - Used for executing parameterized queries.
  - Prevents SQL injection attacks.

---

# **Essential Readings**

1. **Herbert Schildt**, *The Java Complete Reference*, 9th Edition, Tata McGraw-Hill, 2014.
2. **Marty Hall and Larry Brown**, *Core Servlets and JavaServer Pages Volume 1: Core Technologies*, 2nd Edition, Sun Microsystems, 2014.

---
