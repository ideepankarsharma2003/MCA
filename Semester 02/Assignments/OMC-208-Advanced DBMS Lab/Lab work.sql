-- SQLite Queries
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

