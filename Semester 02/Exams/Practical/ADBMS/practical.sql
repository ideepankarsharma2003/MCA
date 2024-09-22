

CREATE TABLE Product (
    Prod_name VARCHAR(50) UNIQUE,
    Prod_no VARCHAR(20) PRIMARY KEY,
    Prod_price INT,
    Prod_quantity INT
);



INSERT INTO Product (Prod_name, Prod_no, Prod_price, Prod_quantity) 
VALUES 
    ('Keyboard', 'P101', 105, 1000),
    ('Mouse', 'P102', 130, 2000),
    ('Speaker', 'P103', 2000, 2000),
    ('Monitor', 'P104', 3400, 2000),
    ('Hard Disk', 'P105', 5000, 3000);



ALTER TABLE Product DROP Primary Key;
ALTER TABLE Product ADD PRIMARY KEY (Prod_name, Prod_no);



SELECT SUM(Prod_price * Prod_quantity) AS TotalInvestment 
FROM Product;



SELECT (SELECT Prod_price FROM Product WHERE Prod_name = 'Hard Disk')-
(SELECT Prod_price FROM Product WHERE Prod_name = 'Speaker') as Price_Difference;




ALTER TABLE Product ADD COLUMN Prod_Customer VARCHAR(50);

UPDATE Product SET Prod_Customer = 'John' WHERE Prod_name = 'Keyboard';
UPDATE Product SET Prod_Customer = 'Ram' WHERE Prod_name = 'Mouse';
UPDATE Product SET Prod_Customer = 'RDJ' WHERE Prod_name = 'Speaker';
UPDATE Product SET Prod_Customer = 'Jimmy' WHERE Prod_name = 'Monitor';
UPDATE Product SET Prod_Customer = 'Ram' WHERE Prod_name = 'Hard Disk';





CREATE TABLE Sales (
    
    Prod_id VARCHAR(20) PRIMARY KEY

);


INSERT INTO Sales (Prod_id) 
VALUES
('P101'),
('P102'),
('P103'),
('P104'),
('P105');





ALTER TABLE Product ADD FOREIGN KEY (Prod_no) 
REFERENCES  Sales(Prod_id);

