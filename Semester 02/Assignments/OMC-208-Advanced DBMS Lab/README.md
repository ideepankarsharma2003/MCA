Let's break down the tasks and solve them one by one.

## Task 1: Case Study 1 - Student Enrollment in Course
1. **ERD (Entity-Relationship Diagram)**: 
   - **Entities**: 
     - Student: Roll_no, Name, Age
     - Course: Course_no, Course_name
     - Faculty: Faculty_no, Faculty_name, Faculty_Qualification, Faculty_salary
   - **Relationships**:
     - Enrolled: Student to Course (Many-to-Many)
     - Teaches: Faculty to Course (One-to-Many)

2. **Database Schema**:
   - **Student Table**:
     - Roll_no (Primary Key, NOT NULL, UNIQUE)
     - Name (NOT NULL)
     - Age (CHECK(Age >= 18 AND Age <= 36))
   - **Course Table**:
     - Course_no (Primary Key, NOT NULL, UNIQUE)
     - Course_name (NOT NULL)
     - Max_students (DEFAULT 100)
   - **Faculty Table**:
     - Faculty_no (Primary Key, NOT NULL, UNIQUE, CHECK(Faculty_no LIKE 'MCA01%'))
     - Faculty_name (NOT NULL)
     - Faculty_Qualification (CHECK(Faculty_Qualification IN ('MCA', 'M.Tech', 'PhD')))
     - Faculty_salary (CHECK(Faculty_salary BETWEEN 25000 AND 50000))

## Task 2: Case Study 2 - Patient Admitted in Hospital
1. **ERD**:
   - **Entities**:
     - Patient: P_no, Name, Age
     - Bed: Bed_no
     - Doctor: Doc_ID, Doc_name, Doc_Qualification, Doc_salary
   - **Relationships**:
     - Admitted: Patient to Bed (Many-to-One)
     - Checks: Doctor to Patient (Many-to-Many)

2. **Database Schema**:
   - **Patient Table**:
     - P_no (Primary Key, NOT NULL, UNIQUE)
     - Name (NOT NULL)
     - Age (CHECK(Age >= 0 AND Age <= 100))
   - **Bed Table**:
     - Bed_no (Primary Key, NOT NULL, UNIQUE)
     - Bed_type (NOT NULL)
   - **Doctor Table**:
     - Doc_ID (Primary Key, NOT NULL, UNIQUE, CHECK(Doc_ID LIKE 'DOC%'))
     - Doc_name (NOT NULL)
     - Doc_Qualification (CHECK(Doc_Qualification IN ('MBBS', 'MS', 'MD')))
     - Doc_salary (CHECK(Doc_salary BETWEEN 25000 AND 50000))

## Task 3: Case Study 3 - Customer Opens an Account
1. **ERD**:
   - **Entities**:
     - Customer: Cust_no, Name, Age
     - Account: Acct_no, Acct_Type, Acct_Balance
     - Loan: Loan_no, Loan_Installment
   - **Relationships**:
     - Holds: Customer to Account (One-to-One)
     - Lends: Customer to Loan (One-to-Many)

2. **Database Schema**:
   - **Customer Table**:
     - Cust_no (Primary Key, NOT NULL, UNIQUE)
     - Name (NOT NULL)
     - Age (CHECK(Age >= 16 AND Age <= 100))
   - **Account Table**:
     - Acct_no (Primary Key, NOT NULL, UNIQUE, CHECK(Acct_no LIKE 'ACC%'))
     - Acct_Type (CHECK(Acct_Type IN ('Current', 'Saving')))
     - Acct_Balance (CHECK(Acct_Balance BETWEEN 1000 AND 50000))
   - **Loan Table**:
     - Loan_no (Primary Key, NOT NULL, UNIQUE)
     - Loan_Installment (CHECK(Loan_Installment BETWEEN 500 AND 50000))

## Task 4: Case Study 4 - Driver Registers in Driving Course
1. **ERD**:
   - **Entities**:
     - Driver: Driv_no, Name, Age
     - Driving_Course: Course_no, Course_Days, Course_Fee
     - Vehicle: Vehicle_no, Vehicle_Type
   - **Relationships**:
     - Registers: Driver to Driving_Course (One-to-One)
     - Owns: Driving_Course to Vehicle (One-to-Many)

2. **Database Schema**:
   - **Driver Table**:
     - Driv_no (Primary Key, NOT NULL, UNIQUE)
     - Name (NOT NULL)
     - Age (CHECK(Age >= 18 AND Age <= 100))
   - **Driving_Course Table**:
     - Course_no (Primary Key, NOT NULL, UNIQUE)
     - Course_Days (CHECK(Course_Days BETWEEN 60 AND 100))
     - Course_Fee (CHECK(Course_Fee > 100))
   - **Vehicle Table**:
     - Vehicle_no (Primary Key, NOT NULL, UNIQUE, CHECK(Vehicle_no LIKE 'VEH%'))
     - Vehicle_Type (CHECK(Vehicle_Type IN ('Car', 'Bus', 'Truck', 'Tempo')))

## Additional Tables
### Client_master
- **Client_no** (Primary Key, VARCHAR2(6), NOT NULL, CHECK(Client_no LIKE 'C%'))
- **Name** (VARCHAR2(20), NOT NULL)
- **Address1** (VARCHAR2(30))
- **Address2** (VARCHAR2(30))
- **City** (VARCHAR2(15))
- **Pincode** (NUMBER(8))
- **State** (VARCHAR2(15))
- **Bal_due** (NUMBER(10,2))

### Product_master
- **Product_no** (Primary Key, VARCHAR2(6), NOT NULL, CHECK(Product_no LIKE 'P%'))
- **Description** (VARCHAR2(15), NOT NULL)
- **Profit_percent** (NUMBER(4,2), NOT NULL)
- **Unit_measure** (VARCHAR2(10), NOT NULL)
- **Qty_on_hand** (NUMBER(8), NOT NULL)
- **Reorder_lvl** (NUMBER(8), NOT NULL)
- **Sell_price** (NUMBER(8,2), NOT NULL, CHECK(Sell_price > 0))
- **Cost_price** (NUMBER(8,2), NOT NULL, CHECK(Cost_price > 0))

### Salesman_master
- **Salesman_no** (Primary Key, VARCHAR2(6), NOT NULL, CHECK(Salesman_no LIKE 'S%'))
- **Salesman_name** (VARCHAR2(20), NOT NULL)
- **Address1** (VARCHAR2(30), NOT NULL)
- **Address2** (VARCHAR2(30))
- **City** (VARCHAR2(20))
- **Pincode** (VARCHAR2(8))
- **State** (VARCHAR2(20))
- **Sal_amt** (NUMBER(8,2), NOT NULL, CHECK(Sal_amt > 0))
- **Target_to_get** (NUMBER(6,2), NOT NULL, CHECK(Target_to_get > 0))
- **Yesterday_sales** (NUMBER(6,2), NOT NULL)
- **Remarks** (VARCHAR2(60))

### Sales_order
- **Order_no** (Primary Key, VARCHAR2(6), NOT NULL, CHECK(Order_no LIKE 'O%'))
- **Order_date** (DATE)
- **Client_no** (VARCHAR2(6), NOT NULL, Foreign Key references Client_master(Client_no))
- **Dely_Address** (VARCHAR2(25))
- **Salesman_no** (VARCHAR2(6), NOT NULL, Foreign Key references Salesman_master(Salesman_no))
- **Dely_type** (CHAR(1), CHECK(Dely_type IN ('P', 'F')))
- **Billed_yn** (CHAR(1))
- **Dely_date** (DATE, CHECK(Dely_date >= Order_date))
- **Order_status** (VARCHAR2(10), CHECK(Order_status IN ('In Process', 'Fulfilled', 'Backorder', 'Cancelled')))

### Sales_order_details
- **Order_no** (VARCHAR2(6), NOT NULL, Foreign Key references Sales_order(Order_no))
- **Product_no** (VARCHAR2(6), NOT NULL, Foreign Key references Product_master(Product_no))
- **Quantity_order** (NUMBER(8))
- **Quantity_disp** (NUMBER(8))
- **Product_rate** (NUMBER(10,2))

## Inserting Data
**Client_master**:
```sql
INSERT INTO Client_master (Client_no, Name, City, Pincode, State, Bal_due)
VALUES 
('C1', 'Ivan', 'Mumbai', 248001, 'Maharashtra', 15000),
('C2', 'Vandana', 'Chennai', 248004, 'Tamil Nadu', 0),
('C3', 'Pramada', 'Mumbai', 248006, 'Maharashtra', 5000),
('C4', 'Basu', 'Mumbai', 248010, 'Maharashtra', 0),
('C5', 'Ravi', 'Delhi', 248005, 'Delhi', 2000),
('C6', 'Rukmani', 'Mumbai', 248009, 'Maharashtra', 0);
```

**Product_master**:
```sql
INSERT INTO Product_master (Product_no, Description, Profit_percent, Unit_measure, Qty_on_hand, Reorder_lvl, Sell_price, Cost_price)
VALUES 
('P00001', 'Floppy', 5, 'Piece', 100, 20, 525, 500),
('P03453', 'Monitors', 6, 'Piece', 10, 3, 12000, 11280),
('P06734', 'Mouse', 5, 'Piece', 20, 5

, 1050, 1000),
('P07865', '1.44 Floppies', 2, 'Piece', 100, 20, 525, 510),
('P07868', 'Keyboards', 10, 'Piece', 10, 3, 3150, 2850),
('P07885', '1.22 Floppies', 5, 'Piece', 100, 20, 525, 500),
('P07965', '1.44 Floppies', 2, 'Piece', 100, 20, 525, 510),
('P07975', 'Monitors', 6, 'Piece', 10, 3, 12000, 11280),
('P08865', 'Keyboards', 10, 'Piece', 10, 3, 3150, 2850);
```

**Salesman_master**:
```sql
INSERT INTO Salesman_master (Salesman_no, Salesman_name, City, Pincode, State, Sal_amt, Target_to_get, Remarks)
VALUES 
('S00001', 'Ram Kumar', 'Bangalore', 560001, 'Karnataka', 3000, 2000, 'Good'),
('S00002', 'Mohan', 'Mysore', 560005, 'Karnataka', 3500, 1000, 'Good'),
('S00003', 'Ravi', 'Chennai', 560003, 'Tamil Nadu', 2500, 2000, 'Good'),
('S00004', 'Rakesh', 'Mumbai', 560002, 'Maharashtra', 3500, 2000, 'Good'),
('S00005', 'Anil', 'Mumbai', 560004, 'Maharashtra', 3000, 1000, 'Good'),
('S00006', 'Manoj', 'Delhi', 560006, 'Delhi', 2500, 2000, 'Good'),
('S00007', 'Sunil', 'Bangalore', 560007, 'Karnataka', 3500, 2000, 'Good'),
('S00008', 'Ashok', 'Bangalore', 560008, 'Karnataka', 3000, 2000, 'Good');
```


### Basic Queries:

**a) Find the names of all clients having ‘a’ as the second letter in their name.**
```sql
SELECT Name 
FROM Client_master 
WHERE Name LIKE '_a%';
```

**b) Find out the clients who stay in a city whose second letter is ’a’.**
```sql
SELECT Name 
FROM Client_master 
WHERE City LIKE '_a%';
```

**c) Find the list of all clients who stay in ‘Mumbai’ or ‘Delhi’.**
```sql
SELECT Name 
FROM Client_master 
WHERE City IN ('Mumbai', 'Delhi');
```

**d) Print the list of clients whose bal_due is greater than value 10000.**
```sql
SELECT Name 
FROM Client_master 
WHERE Bal_due > 10000;
```

**e) Print the information from the sales_order table for orders placed in the month of January.**
```sql
SELECT * 
FROM Sales_order 
WHERE EXTRACT(MONTH FROM Order_date) = 1;
```

**f) Display the order information for client_no ‘C1’ and ‘C2’.**
```sql
SELECT * 
FROM Sales_order 
WHERE Client_no IN ('C1', 'C2');
```

**g) Find Products whose selling price is greater than 2000 and less than or equal to 5000.**
```sql
SELECT * 
FROM Product_master 
WHERE Sell_price > 2000 AND Sell_price <= 5000;
```

**h) Find products whose selling price is more than 1500. Calculate a new selling price as, original selling price * 1.15. Rename the new column in the above query as new_price.**
```sql
SELECT Product_no, Description, Sell_price, Sell_price * 1.15 AS new_price 
FROM Product_master 
WHERE Sell_price > 1500;
```

**i) List the names, city, and state of clients who are not in the state of ‘Maharashtra’.**
```sql
SELECT Name, City, State 
FROM Client_master 
WHERE State <> 'Maharashtra';
```

### Date Manipulation:

**a) Display the order number and day on which clients placed their order.**
```sql
SELECT Order_no, TO_CHAR(Order_date, 'Day') AS Order_day 
FROM Sales_order;
```

**b) Display the month (in alphabets) and date when the order must be delivered.**
```sql
SELECT Order_no, TO_CHAR(Dely_date, 'Month DD') AS Delivery_month_date 
FROM Sales_order;
```

**c) Display the order_date in the format ‘DD-Month-yy’ for example, 12-February-14.**
```sql
SELECT TO_CHAR(Order_date, 'DD-Month-yy') AS Formatted_order_date 
FROM Sales_order;
```

**d) Find the date, 15 days after today’s date.**
```sql
SELECT SYSDATE + 15 AS Date_after_15_days 
FROM dual;
```

**e) Find the number of days elapsed between today’s date and the delivery date of the orders placed by the clients.**
```sql
SELECT Order_no, (Dely_date - SYSDATE) AS Days_until_delivery 
FROM Sales_order;
```

### Joins, Union, Intersection, and Minus:

**a) Find out the products, which have been sold to ‘Ivan’.**
```sql
SELECT DISTINCT p.Product_no, p.Description 
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
JOIN Sales_order so ON so.Order_no = sod.Order_no
JOIN Client_master c ON c.Client_no = so.Client_no
WHERE c.Name = 'Ivan';
```

**b) Find out the products and their quantities that will have to be delivered in the current month.**
```sql
SELECT p.Product_no, p.Description, sod.Quantity_disp 
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
JOIN Sales_order so ON so.Order_no = sod.Order_no
WHERE EXTRACT(MONTH FROM so.Dely_date) = EXTRACT(MONTH FROM SYSDATE);
```

**c) Find the product_no and description of constantly sold i.e., rapidly moving products.**
```sql
SELECT p.Product_no, p.Description 
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
GROUP BY p.Product_no, p.Description
HAVING COUNT(sod.Order_no) > 1;
```

**d) Find the names of clients who have purchased ‘HDD’.**
```sql
SELECT DISTINCT c.Name 
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
JOIN Sales_order_details sod ON so.Order_no = sod.Order_no
JOIN Product_master p ON sod.Product_no = p.Product_no
WHERE p.Description LIKE '%HDD%';
```

**e) List the product_no and the order_no of customers having qty_ordered less than 5 from the sales_order_details table for the product Floppy Disk.**
```sql
SELECT sod.Product_no, sod.Order_no 
FROM Sales_order_details sod
JOIN Product_master p ON sod.Product_no = p.Product_no
WHERE p.Description LIKE '%Floppy Disk%' AND sod.Quantity_order < 5;
```

**f) Find the products and their quantities for the orders placed by ‘Ivan’ and ‘Vandana’.**
```sql
SELECT p.Product_no, p.Description, sod.Quantity_order 
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
JOIN Sales_order so ON so.Order_no = sod.Order_no
JOIN Client_master c ON c.Client_no = so.Client_no
WHERE c.Name IN ('Ivan', 'Vandana');
```

**g) Find the products and their quantities for the orders placed by client_no ‘C1’ and ‘C2’.**
```sql
SELECT p.Product_no, p.Description, sod.Quantity_order 
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
JOIN Sales_order so ON so.Order_no = sod.Order_no
WHERE so.Client_no IN ('C1', 'C2');
```

### Subqueries:

**a) Find the product_no and description of non-moving products, i.e., products not being sold.**
```sql
SELECT p.Product_no, p.Description 
FROM Product_master p
WHERE p.Product_no NOT IN (SELECT Product_no FROM Sales_order_details);
```

**b) Find the customer name, address1, address2, city, and pincode for the client who has placed order no ‘O1’.**
```sql
SELECT c.Name, c.Address1, c.Address2, c.City, c.Pincode 
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
WHERE so.Order_no = 'O1';
```

**c) Find the client names who have placed orders before the month of May 14.**
```sql
SELECT DISTINCT c.Name 
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
WHERE so.Order_date < TO_DATE('01-MAY-14', 'DD-MON-YY');
```

**d) Find out if the product ‘Floppy Disk’ has been ordered by any client and print the client_no, name to whom it was sold.**
```sql
SELECT DISTINCT c.Client_no, c.Name 
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
JOIN Sales_order_details sod ON so.Order_no = sod.Order_no
JOIN Product_master p ON sod.Product_no = p.Product_no
WHERE p.Description LIKE '%Floppy Disk%';
```

**e) Find the names of clients who have placed orders worth Rs. 10000 or more.**
```sql
SELECT DISTINCT c.Name 
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
JOIN Sales_order_details sod ON so.Order_no = sod.Order_no
GROUP BY c.Name
HAVING SUM(sod.Product_rate * sod.Quantity_order) >= 10000;
```
