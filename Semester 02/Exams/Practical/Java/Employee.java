import java.util.Scanner;

public class Employee {
    private int employeeNumber;
    private String name;
    private String designation;
    private double salary;

    public Employee(){

    }

    public Employee(int employeeNumber, String name, String designation, double salary) {
        this.employeeNumber = employeeNumber;
        this.name = name;
        this.designation = designation;
        this.salary = salary;
    }

    public void setEmployeeDetails(int employeeNumber, String name, String designation, double salary) {
        this.employeeNumber = employeeNumber;
        this.name = name;
        this.designation = designation;
        this.salary = salary;
    }

    public void displayDetails() {
        System.out.println("Employee Number: " + employeeNumber + "\n"
                + "Name: " + name + "\n"
                + "Designation: " + designation + "\n"
                + "Salary: " + salary);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int employeeNumber=4;
        String name="Ben", designation="Manager";
        double salary=4000;

        System.out.print("Enter Employee Number: ");
        employeeNumber = scanner.nextInt();
        scanner.nextLine();
        
        System.out.print("Enter Name: ");
        name = scanner.nextLine();
        
        System.out.print("Enter Designation: ");
        designation = scanner.nextLine();
        
        System.out.print("Enter Salary: ");
        salary = scanner.nextDouble();
        scanner.nextLine();

        Employee emp = new Employee(employeeNumber, name, designation, salary);
        

        System.out.println("\nEmployee Details:");
        emp.displayDetails();

        

        scanner.close();
    }
}
