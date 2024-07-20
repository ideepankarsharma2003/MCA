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

    