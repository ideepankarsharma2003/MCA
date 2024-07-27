-- SQLite Queries

-- Table Name: Client_master
-- Description: Used to store client information

-- Column Name	    Data Type	Size	Attributes
-- Client_no        Varchar2	6	    Primary key / first letter must start with ‘C’
-- Name	            Varchar2   	20	    Not null
-- Address1	        Varchar2	30	
-- Address2	        Varchar2	30	
-- City	            Varchar2   	15	
-- Pincode	        Number	    8	
-- Sate	            Varchar2   	15	
-- Bal_due	        Number	    10,2	


CREATE TABLE Client_master (
    Client_no VARCHAR2(6) PRIMARY KEY CHECK (Client_no LIKE 'C%'),
    Name VARCHAR2(20) NOT NULL,
    Address1 VARCHAR2(30),
    Address2 VARCHAR2(30),
    City VARCHAR2(15),
    Pincode NUMBER(8),
    State VARCHAR2(15),
    Bal_due NUMBER(10,2)
    
);

-- # Postgres
CREATE TABLE Client_master (
    Client_no VARCHAR(6) PRIMARY KEY CHECK (Client_no LIKE 'C%'),
    Name VARCHAR(20) NOT NULL,
    Address1 VARCHAR(30),
    Address2 VARCHAR(30),
    City VARCHAR(15),
    Pincode INTEGER,
    State VARCHAR(15),
    Bal_due NUMERIC(10,2)
);




-- Table Name: Product_master
-- Description: Used to store Product information

-- Column Name	    Data Type	Size	Attributes
-- Product_no	    Varchar2	6	    Primary key / first letter must start with ‘P’
-- Description	    Varchar2	15	    Not null
-- Profit_percent	Number	    4,2	    Not null
-- Unit_measure	    Varchar2	10	    Not null
-- Qty_on_hand	    Number	    8	    Not null
-- Reorder_lvl	    Number	    8	    Not null
-- Sell_price	    Number	    8,2	    Not null, cannot be 0
-- Cost_price	    Number	    8,2	    Not null, cannot be 0

CREATE TABLE Product_master (
    Product_no VARCHAR2(6) PRIMARY KEY CHECK (Product_no LIKE 'P%'),
    Description VARCHAR2(15) NOT NULL,
    Profit_percent NUMBER(4,2) NOT NULL,
    Unit_measure VARCHAR2(10) NOT NULL,
    Qty_on_hand NUMBER(8) NOT NULL,
    Reorder_lvl NUMBER(8) NOT NULL,
    Sell_price NUMBER(8,2) NOT NULL CHECK (Sell_price > 0),
    Cost_price NUMBER(8,2) NOT NULL CHECK (Cost_price > 0)
);
-- # Postgres
CREATE TABLE Product_master (
    Product_no VARCHAR(6) PRIMARY KEY CHECK (Product_no LIKE 'P%'),
    Description VARCHAR(15) NOT NULL,
    Profit_percent NUMERIC(4,2) NOT NULL,
    Unit_measure VARCHAR(10) NOT NULL,
    Qty_on_hand NUMERIC(8) NOT NULL,
    Reorder_lvl NUMERIC(8) NOT NULL,
    Sell_price NUMERIC(8,2) NOT NULL CHECK (Sell_price > 0),
    Cost_price NUMERIC(8,2) NOT NULL CHECK (Cost_price > 0)
);

-- Table Name: Salesman_master
-- Description: Used to store salesman working for the company

-- Column Name	        Data Type	Size	Attributes
-- Salesman_no	        Varchar2	6	    Primary key / first letter must start with ‘S’
-- Salesman_name	    Varchar2	20	    Not null
-- Address1	            Varchar2	30	    Not null
-- Address2	            Varchar2	30	
-- City	                Varchar2	20	
-- Pincode	            Varchar2	8	
-- State	            Varchar2	20	
-- Sal_amt	            Number	    8,2	    Not null, cannot be 0
-- Target_to_get	    Number	    6,2	    Not null, cannot be 0
-- Yesterday_sales	    Number	    6,2	    Not null
-- remarks	            Varchar2	60	

CREATE TABLE Salesman_master (
    Salesman_no VARCHAR2(6) PRIMARY KEY CHECK (Salesman_no LIKE 'S%'),
    Salesman_name VARCHAR2(20) NOT NULL,
    Address1 VARCHAR2(30) NOT NULL,
    Address2 VARCHAR2(30),
    City VARCHAR2(20),
    Pincode VARCHAR2(8),
    State VARCHAR2(20),
    Sal_amt NUMBER(8,2) NOT NULL CHECK (Sal_amt > 0),
    Target_to_get NUMBER(6,2) NOT NULL CHECK (Target_to_get > 0),
    Yesterday_sales NUMBER(6,2) NOT NULL,
    remarks VARCHAR2(60)
);
-- # Postgres
CREATE TABLE Salesman_master (
    Salesman_no VARCHAR(6) PRIMARY KEY CHECK (Salesman_no LIKE 'S%'),
    Salesman_name VARCHAR(20) NOT NULL,
    Address1 VARCHAR(30) NOT NULL,
    Address2 VARCHAR(30),
    City VARCHAR(20),
    Pincode VARCHAR(8),
    State VARCHAR(20),
    Sal_amt NUMERIC(8,2) NOT NULL CHECK (Sal_amt > 0),
    Target_to_get NUMERIC(6,2) NOT NULL CHECK (Target_to_get > 0),
    Yesterday_sales NUMERIC(6,2) NOT NULL,
    remarks VARCHAR(60)
);



-- Table Name: Sales_order
-- Description: Used to store Client’s orders

-- Column Name	    Data Type      Size	    Attributes
-- Order_no	        Varchar2       6	    Primary key / first letter must start with ‘O’
-- Order_date	    Date           
-- Client_no	    Varchar2       6	    Foreign key references client_no of client_master table
-- Dely_Address	    Varchar2       25	
-- Salesman_no	    Varchar2       6	    Foreign key references Salesman_no of Salesman_master table
-- Dely_type	    Char           1	    Delivery: Part(P), Full(F)
-- Billed_yn	    Char           1	
-- Dely_date	    Date                    Cannot be less than order date
-- Order_status	    Varchar2       10	    Values (‘In Process’, ‘Fulfilled’, ‘Backorder’, ‘Cancelled’)
CREATE TABLE Sales_order (
    Order_no VARCHAR2(6) PRIMARY KEY CHECK (Order_no LIKE 'O%'),
    Order_date DATE,
    Client_no VARCHAR2(6),
    Dely_Address VARCHAR2(25),
    Salesman_no VARCHAR2(6),
    Dely_type CHAR(1) CHECK (Dely_type IN ('P', 'F')),
    Billed_yn CHAR(1),
    Dely_date DATE CHECK (Dely_date >= Order_date),
    Order_status VARCHAR2(10) CHECK (Order_status IN ('In Process', 'Fulfilled', 'Backorder', 'Cancelled')),
    FOREIGN KEY (Client_no) REFERENCES Client_master(Client_no),
    FOREIGN KEY (Salesman_no) REFERENCES Salesman_master(Salesman_no)
);

-- # Postgres
CREATE TABLE Sales_order (
    Order_no VARCHAR(6) PRIMARY KEY CHECK (Order_no LIKE 'O%'),
    Order_date DATE,
    Client_no VARCHAR(6),
    Dely_Address VARCHAR(25),
    Salesman_no VARCHAR(6),
    Dely_type CHAR(1) CHECK (Dely_type IN ('P', 'F')),
    Billed_yn CHAR(1),
    Dely_date DATE CHECK (Dely_date >= Order_date),
    Order_status VARCHAR(10) CHECK (Order_status IN ('In Process', 'Fulfilled', 'Backorder', 'Cancelled')),
    FOREIGN KEY (Client_no) REFERENCES Client_master(Client_no),
    FOREIGN KEY (Salesman_no) REFERENCES Salesman_master(Salesman_no)
);


-- Table Name: Sales_order_details
-- Description: Used to store Client’s orders with details of each product ordered.

-- Column Name	        Data Type	Size	Attributes
-- Order_no	            Varchar2	6	    Primary key / Foreign key references order_no of Sales_order table
-- Product_no	        Varchar2	6	    Primary key / Foreign key references Product_no of Product_master table
-- Quantiy_order	    Number	    8	
-- Quantity_disp	    Number	    8	
-- Product_rate	        Number	    10,2	
CREATE TABLE Sales_order_details (
    Order_no VARCHAR2(6),
    Product_no VARCHAR2(6),
    Quantity_order NUMBER(8),
    Quantity_disp NUMBER(8),
    Product_rate NUMBER(10,2),
    PRIMARY KEY (Order_no, Product_no),
    FOREIGN KEY (Order_no) REFERENCES Sales_order(Order_no),
    FOREIGN KEY (Product_no) REFERENCES Product_master(Product_no)
);




-- Insert the following data into their respective tables:
-- Table Name: Client_master
-- Description: Used to store client information

-- Client_no	Name	    City	    Pincode	    State	        Bal_due
-- C1	        Ivan	    Mumbai	    248001	    Maharashtra	    15000
-- C2	        Vandana	    Chennai	    248004	    Tamil Nadu	    0
-- C3	        Pramada	    Mumbai	    248006	    Maharashtra	    5000
-- C4	        Basu	    Mumbai	    248010	    Maharashtra	    0
-- C5	        Ravi	    Delhi	    248005	    Delhi	        2000
-- C6	        Rukmani	    Mumbai	    248009	    Maharashtra	    0
INSERT INTO Client_master (Client_no, Name, City, Pincode, State, Bal_due)
VALUES 
('C1', 'Ivan', 'Mumbai', 248001, 'Maharashtra', 15000),
('C2', 'Vandana', 'Chennai', 248004, 'Tamil Nadu', 0),
('C3', 'Pramada', 'Mumbai', 248006, 'Maharashtra', 5000),
('C4', 'Basu', 'Mumbai', 248010, 'Maharashtra', 0),
('C5', 'Ravi', 'Delhi', 248005, 'Delhi', 2000),
('C6', 'Rukmani', 'Mumbai', 248009, 'Maharashtra', 0);





-- Table Name: Product_master
-- Description: Used to store Product information

-- Product_no	Description	Profit percent	Unit_measure	Qty_on_hand	Reorder_Level	Sell price	Cost Price
-- P00001	    Floppy	    5	            Piece	        100	        20	            525	        500
-- P03453	    Monitors	6	            Piece	        10	        3	            12000	    11280
-- P06734	    Mouse	    5	            Piece	        20	        5	            1050	    1000
-- P07865	    Keyboard	5	            Piece	        100	        20	            525	        500
-- P07868	    CD Drive	2	            Piece	        10	        3	            3150	    3050
-- P07885	    HDD	        2.5	            Piece	        10	        3	            5250	    5100
-- P07965	    Cable	    4	            Piece	        10	        3	            8400	    8000
-- P07975	    Keys	    5	            Piece	        10	        3	            1050	    1000
-- P08865	    2GBRAM	    5	            Piece	        2	        3	            1050	    1000

INSERT INTO Product_master (Product_no, Description, Profit_percent, Unit_measure, Qty_on_hand, Reorder_lvl, Sell_price, Cost_price)
VALUES 
( 'P00001',	    'Floppy',       5,      'Piece',	        100,	    20,	            525,	    500),
( 'P03453',	    'Monitors',     6,      'Piece',	        10,	        3,	            12000,	    11280),
( 'P06734',	    'Mouse',        5,      'Piece',	        20,	        5,	            1050,	    1000),
( 'P07865',	    'Keyboard',     5,      'Piece',	        100,	    20,	            525,	    500),
( 'P07868',	    'CD Drive',     2,      'Piece',	        10,	        3,	            3150,	    3050),
( 'P07885',	    'HDD',          2.5,    'Piece',	        10,	        3,	            5250,	    5100),
( 'P07965',	    'Cable',        4,      'Piece',	        10,	        3,	            8400,	    8000),
( 'P07975',	    'Keys',         5,      'Piece',	        10,	        3,	            1050,	    1000),
( 'P08865',	    '2GBRAM',       5,      'Piece',	        2,	        3,	            1050,	    1000);





-- Table Name: Salesman_master
-- Description: Used to store salesman working for the company

-- Salesman no	    Salesman name	Address1	Address2	City	Pincode	State	        Sal_amt	    Tgt_to_get	Ytd_sales	remarks
-- S1	                Kiran	        A/14	Worli	    Mumbai	140001	Maharashtra	    3000	    100	            50	        Good
-- S2	                Manish	        65	    Nariman	    Mumbai	140002	Maharashtra	    3000	    200	            100	        Good
-- S3	                Ravi	        P-7	    Bandra	    Mumbai	140003	Maharashtra	    3000	    200	            100	        Good
-- S4	                Ashish	        A/5	    Juhu	    Mumbai	140004	Maharashtra	    3500	    200	            150	        Good

INSERT INTO Salesman_master (Salesman_no, Salesman_name, Address1, Address2, City, Pincode, State, Sal_amt, Tgt_to_get, Ytd_sales, remarks)
VALUES 
    ('S1', 'Kiran', 'A/14', 'Worli', 'Mumbai', '140001', 'Maharashtra', 3000, 100, 50, 'Good'),
    ('S2', 'Manish', '65', 'Nariman', 'Mumbai', '140002', 'Maharashtra', 3000, 200, 100, 'Good'),
    ('S3', 'Ravi', 'P-7', 'Bandra', 'Mumbai', '140003', 'Maharashtra', 3000, 200, 100, 'Good'),
    ('S4', 'Ashish', 'A/5', 'Juhu', 'Mumbai', '140004', 'Maharashtra', 3500, 200, 150, 'Good');









-- Table Name: Sales_order
-- Description: Used to store Client’s orders

-- Order no	Order date	Client no	Dely type	Bill yn	Salesman no	Dely date	Order status 
-- O1	        12-Jan-13	C1	        F	        N	    S1	        11-Jan-13	In Process
-- O2	        12-Feb-13	C2	        P	        N	    S2	        14-Feb-13	Cancelled
-- O3	        12-Sep-13	C3	        F	        Y	    S3	        17-Sep-13	Fulfilled
-- O4	        12-Oct-13	C1	        F	        Y	    S1	        19-Oct-13	Fulfilled
-- O5	        12-Oct-13	C4	        P	        N	    S2	        25-Oct-13	Cancelled
-- O6	        12-Nov-14	C5	        F	        N	    S4	        16-Nov-14	In Process
INSERT INTO Sales_order (Order_no, Order_date, Client_no, Dely_type, Billed_yn, Salesman_no, Dely_date, Order_status)
VALUES
    -- ('O1', '2013-01-12', 'C1', 'F', 'N', 'S1', '2013-01-11', 'In Process'),
    ('O2', '2013-02-12', 'C2', 'P', 'N', 'S2', '2013-02-14', 'Cancelled'),
    ('O3', '2013-09-12', 'C3', 'F', 'Y', 'S3', '2013-09-17', 'Fulfilled'),
    ('O4', '2013-10-12', 'C1', 'F', 'Y', 'S1', '2013-10-19', 'Fulfilled'),
    ('O5', '2013-10-12', 'C4', 'P', 'N', 'S2', '2013-10-25', 'Cancelled'),
    ('O6', '2014-11-12', 'C5', 'F', 'N', 'S4', '2014-11-16', 'In Process');










-- Table Name: Sales_order_details
-- Description: Used to store Client’s orders with details of each product ordered.

-- Order_no	Product_no	Qty_ordered	Qty_disp	Product_rate
-- O1	        P00001	    4	        4	        525
-- O1	        P07965	    2	        1	        8400
-- O1	        P07885	    2	        1	        5250
-- O2	        P00001	    10	        0	        525
-- O5	        P07868	    3	        3	        3150
-- O5	        P07885	    3	        1	        5250
-- O5	        P00001	    10	        10	        525
-- O5	        P03453	    4	        4	        1050
-- O3	        P03453	    2	        2	        1050
-- O3	        P06734	    1	        1	        12000
-- O6	        P07965	    1	        0	        8400
-- O6	        P07975	    1	        0	        1050
-- O8	        P00001	    10	        5	        525
-- O8	        P07975	    5	        3	        1050

INSERT INTO Sales_order_details (Order_no, Product_no, Quantity_order, Quantity_disp, Product_rate)
VALUES
    -- ('O1', 'P00001', 4, 4, 525),
    -- ('O1', 'P07965', 2, 1, 8400),
    -- ('O1', 'P07885', 2, 1, 5250),
    -- ('O8', 'P00001', 10, 5, 525),
    -- ('O8', 'P07975', 5, 3, 1050),
    ('O2', 'P00001', 10, 0, 525),
    ('O5', 'P07868', 3, 3, 3150),
    ('O5', 'P07885', 3, 1, 5250),
    ('O5', 'P00001', 10, 10, 525),
    ('O5', 'P03453', 4, 4, 1050),
    ('O3', 'P03453', 2, 2, 1050),
    ('O3', 'P06734', 1, 1, 12000),
    ('O6', 'P07965', 1, 0, 8400),
    ('O6', 'P07975', 1, 0, 1050);



-- ##################################
-- Questions

-- Write queries for following questions
-- a) Find the names of all clients having ‘a’ as the second letter in their name.
SELECT Name
FROM Client_master
WHERE Name LIKE '_a%';

-- b) Find out the clients who stay in a city whose second letter is ’a’.
SELECT Name
FROM Client_master
WHERE City LIKE '_a%';

-- c) Find the list of all clients who stay in ‘Mumbai’ or ‘Delhi’.
SELECT Name
FROM Client_master
WHERE City IN ('Mumbai', 'Delhi');

-- d) Print the list of clients whose bal_due is greater than value 10000.
SELECT Name
FROM Client_master
WHERE Bal_due > 10000;

-- e) Print the information from sales_order table for orders placed in the month of January.
SELECT *
FROM Sales_order
WHERE strftime('%m', Order_date) = '02';

-- f) Display the order information for client_no ‘C1’ and ‘C2’.
SELECT *
FROM Sales_order
WHERE Client_no IN ('C1', 'C2');

-- g) Find Products whose selling price is greater than 2000 and less than or equal to 5000.
SELECT *
FROM Product_master
WHERE Sell_price > 2000 AND Sell_price <= 5000;

-- h) Find products whose selling price is more than 1500. Calculate a new selling price as, original selling price * .15.    
--     Rename the new column in the above query as new_price.
SELECT Product_no, Description, Sell_price, Sell_price * 1.15 AS new_price
FROM Product_master
WHERE Sell_price > 1500;


-- i) List the names, city and state of clients who are not in the state of ‘Maharashtra’.
SELECT Name, City, State
FROM Client_master
WHERE State != 'Maharashtra';

-- Exercise on Date Manipulation
-- a) Display the order number and day on which clients placed their order.
SELECT Order_no, strftime('%d', Order_date) AS Day
FROM Sales_order;

-- b) Display the month (in alphabets) and date when the order must be delivered.
SELECT Order_no, strftime('%m', Dely_date) AS Month, strftime('%d', Dely_date) AS Day
FROM Sales_order;

-- c) Display the order_date in the format ‘DD-Month-yy’ for example, 12-February-14.





-- d) Find the date, 15 days after today’s date.
SELECT date('now', '+15 days') AS Date_After_15_Days;

-- e) Find the number of days elapsed between today’s date and the delivery date of the orders placed by the clients.
SELECT Order_no, julianday('now') - julianday(Dely_date) AS Days_Elapsed
FROM Sales_order;


-- Exercises on Joins, Union, Intersection and Minus:
-- a) Find out the products, which have been sold to ‘Ivan’.
SELECT DISTINCT p.Product_no, p.Description
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
JOIN Sales_order so ON so.Order_no = sod.Order_no
JOIN Client_master c ON c.Client_no = so.Client_no
WHERE c.Name = 'Ivan';
-- b) Find out the products and their quantities that will have to be delivered in the current month.
SELECT p.Product_no, p.Description, sod.Quantity_order
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
JOIN Sales_order so ON so.Order_no = sod.Order_no
WHERE strftime('%m', so.Dely_date) = strftime('%m', 'now');


-- c) Find the product_no and description of constantly sold i.e., rapidly moving products.
SELECT Product_no, Description
FROM Product_master
WHERE Qty_on_hand < Reorder_lvl;

-- d) Find the names of clients who have purchased ‘HDD’.
SELECT DISTINCT c.Name
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
JOIN Sales_order_details sod ON so.Order_no = sod.Order_no
JOIN Product_master p ON sod.Product_no = p.Product_no
WHERE p.Description = 'HDD';

-- e) List the product_no and the order_no of customers having qty_ordered less than 5 from the sales_order_details table for the product Floppy Disk.
SELECT sod.Product_no, sod.Order_no
FROM Sales_order_details sod
JOIN Product_master p ON sod.Product_no = p.Product_no
WHERE p.Description = 'Floppy' AND sod.Quantity_order < 5;

-- f) Find the productd and their quantities for the orders places by ‘Ivan’ and ‘Vandana’.
SELECT p.Product_no, p.Description, sod.Quantity_order
,c.Name as name
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
JOIN Sales_order so ON so.Order_no = sod.Order_no
JOIN Client_master c ON c.Client_no = so.Client_no
WHERE c.Name IN ('Ivan', 'Vandana');

-- g) Find the products and their quantities for the orders placed by client_no ‘C1’ and ‘C2’.
SELECT p.Product_no, p.Description, sod.Quantity_order
FROM Product_master p
JOIN Sales_order_details sod ON p.Product_no = sod.Product_no
JOIN Sales_order so ON so.Order_no = sod.Order_no
WHERE so.Client_no IN ('C1', 'C2');

-- Exercises on Subqueries:
-- a) Find the product_no and description of non moving products that is, products not being sold.
SELECT Product_no, Description
FROM Product_master
WHERE Product_no NOT IN (SELECT DISTINCT Product_no FROM Sales_order_details);

-- b) Find the customer name, address1,  address2, city and picode for the client who has placed order no ‘O1’.
SELECT c.Name, c.Address1, c.Address2, c.City, c.Pincode
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
WHERE so.Order_no = 'O1';


-- c) Find the client names who have placed orders before the month of may 14.
SELECT DISTINCT c.Name
-- ,strftime('%Y-%m', so.Order_date) as Order_date
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
WHERE strftime('%Y-%m', so.Order_date) < '2014-05';


-- d) Find out if the product ‘Floppy Disk’ has been ordered by any client and print the client_no, name to whom it was sold.
SELECT DISTINCT c.Client_no, c.Name
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
JOIN Sales_order_details sod ON so.Order_no = sod.Order_no
JOIN Product_master p ON sod.Product_no = p.Product_no
WHERE p.Description = 'Floppy';

-- f) Find the names of clients who have placed oerders worth Rs. 10000 or more.
SELECT DISTINCT c.Name
, SUM(sod.Quantity_order * sod.Product_rate) AS order_worth
FROM Client_master c
JOIN Sales_order so ON c.Client_no = so.Client_no
JOIN Sales_order_details sod ON so.Order_no = sod.Order_no
GROUP BY c.Client_no, c.Name
HAVING SUM(sod.Quantity_order * sod.Product_rate) >= 10000;
