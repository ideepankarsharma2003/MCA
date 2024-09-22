Let's solve the given problem step by step with SQL queries.

### **Step 1: Create the `Product` table and insert the data**
```sql
CREATE TABLE Product (
    Prod_Name VARCHAR(50) UNIQUE,
    Prod_No VARCHAR(10) PRIMARY KEY,
    Prod_Price INT,
    Prod_Quantity INT
);

-- Inserting the data into Product table
INSERT INTO Product (Prod_Name, Prod_No, Prod_Price, Prod_Quantity) VALUES 
('Keyboard', 'P101', 105, 1000),
('Mouse', 'P102', 130, 2000),
('Speaker', 'P103', 2000, 2000),
('Monitor', 'P104', 3400, 2000),
('Hard disk', 'P105', 5000, 3000);
```

### **a) Removing the Primary Key constraint and making `Prod_Name` and `Prod_No` a composite key**
```sql
-- Dropping the primary key constraint
ALTER TABLE Product DROP CONSTRAINT Product_pkey;

-- Creating a composite primary key with Prod_Name and Prod_No
ALTER TABLE Product ADD PRIMARY KEY (Prod_Name, Prod_No);
```

### **b) Finding the total amount invested to purchase all the products**
```sql
-- Calculating total investment
SELECT SUM(Prod_Price * Prod_Quantity) AS Total_Investment FROM Product;
```

### **c) Finding the difference between the price of Speaker and Hard disk**
```sql
-- Calculating the price difference between Speaker and Hard disk
SELECT 
    (SELECT Prod_Price FROM Product WHERE Prod_Name = 'Hard disk') - 
    (SELECT Prod_Price FROM Product WHERE Prod_Name = 'Speaker') AS Price_Difference;
```

### **d) Adding a new column `Prod_Customer` and inserting corresponding data**
```sql
-- Adding the Prod_Customer column
ALTER TABLE Product ADD COLUMN Prod_Customer VARCHAR(50);

-- Updating the Prod_Customer column with assumed data
UPDATE Product SET Prod_Customer = 'John Doe' WHERE Prod_Name = 'Keyboard';
UPDATE Product SET Prod_Customer = 'Jane Smith' WHERE Prod_Name = 'Mouse';
UPDATE Product SET Prod_Customer = 'Mark Twain' WHERE Prod_Name = 'Speaker';
UPDATE Product SET Prod_Customer = 'Lucy Brown' WHERE Prod_Name = 'Monitor';
UPDATE Product SET Prod_Customer = 'Alan Green' WHERE Prod_Name = 'Hard disk';
```

### **e) Creating a new `Sales` table and defining `Prod_No` as a Foreign Key**
```sql
-- Creating the Sales table
CREATE TABLE Sales (
    Sale_ID INT PRIMARY KEY,
    Prod_ID VARCHAR(10),
    Sale_Date DATE,
    Quantity_Sold INT,
    FOREIGN KEY (Prod_ID) REFERENCES Product(Prod_No)
);

-- Inserting sample data into Sales table
INSERT INTO Sales (Sale_ID, Prod_ID, Sale_Date, Quantity_Sold) VALUES 
(1, 'P101', '2024-01-01', 150),
(2, 'P102', '2024-01-02', 300),
(3, 'P103', '2024-01-03', 200),
(4, 'P104', '2024-01-04', 100),
(5, 'P105', '2024-01-05', 50);
```

These SQL queries address all the parts of the problem by creating and manipulating the `Product` table and establishing a relationship with the new `Sales` table using a foreign key constraint.