# Advanced DBMS
---

## **Unit 1: Introduction to DBMS**

### **Key Concepts:**

#### **1. Data and Database:**
- **Data:** Represents raw facts and figures that are unprocessed and lack context (e.g., "23", "John", "2024-09-22"). Data on its own is not meaningful.
- **Database:** An organized collection of related data that provides meaning and is managed to facilitate easy access, retrieval, and manipulation. Examples include libraries’ catalog systems or a company's employee records.

#### **2. Database Management System (DBMS):**
- A **DBMS** is software that manages databases. It allows for the creation, definition, and management of databases, handling data storage, retrieval, and updating.
- **Examples:** MySQL, Oracle, Microsoft SQL Server, and PostgreSQL.

#### **3. Database System Concepts and Architecture:**
- **Database System:** An integrated collection of data, the DBMS software, and the application programs that access the data.
- **Components of DBMS:**
  - **Hardware:** Physical devices (servers, storage, etc.)
  - **Software:** DBMS software, application programs, and operating system.
  - **Data:** The actual data stored in databases.
  - **Users:** End-users, database administrators, application developers.

#### **4. Three Schema Architecture:**
- Provides a way to separate the database's physical structure from the logical and external structure:
  - **Internal Schema:** Describes physical storage structure and access paths (e.g., indexing, storage blocks).
  - **Conceptual Schema:** Defines the overall structure of the database without any concern for physical considerations.
  - **External Schema:** Describes how end-users interact with the database through different views.

#### **5. Data Independence:**
- The ability to change the schema at one level without affecting the schema at the next higher level.
  - **Logical Data Independence:** Changing the conceptual schema does not affect the external schema.
  - **Physical Data Independence:** Changing the internal schema does not impact the conceptual schema.

---

## **Unit 2: Enhanced Entity Relationship Model (EER)**

### **Key Concepts:**

#### **1. Entity-Relationship (ER) Model:**
- An ER model represents real-world entities and their relationships.
- **Entity:** An object distinguishable from others (e.g., "Customer," "Product").
- **Attributes:** Descriptive properties of an entity (e.g., Customer: Name, Address).

#### **2. Enhanced ER (EER) Model:**
- **Enhancements over basic ER Model** include additional constructs such as:
  - **Subclasses/Superclasses:** Allows entities to inherit properties from other entities. 
    - **Superclass:** A general entity type (e.g., "Vehicle").
    - **Subclass:** A specialized entity type (e.g., "Car" inherits from "Vehicle").
  - **Inheritance:** Subclasses inherit attributes and relationships of the superclass.
  - **Specialization:** Defining a set of subclasses for an entity (e.g., "Employee" might specialize into "Manager" and "Developer").
  - **Generalization:** Combining subclasses into a superclass.
  
#### **3. Weak Entities:**
- Entities that depend on another "owner" entity for their identification.
- **Example:** "Order Items" cannot exist without an associated "Order."

#### **4. Relationship Types and Constraints:**
- **Cardinality Ratios:** One-to-One, One-to-Many, Many-to-Many.
- **Participation Constraints:** Total or Partial (whether an entity must participate in a relationship).

#### **5. EER Diagram Case Studies:**
- Complex real-world scenarios like hospital management, university systems can be modeled using EER diagrams to capture subclasses, inheritance, and complex relationships.

---

## **Unit 3: Introduction to Relational Model**

### **Key Concepts:**

#### **1. Relational Model Structure:**
- Data organized into tables called **relations**. Each table consists of:
  - **Tuples (Rows):** Represent records.
  - **Attributes (Columns):** Represent fields or properties.

#### **2. Keys in the Relational Model:**
- **Primary Key:** Uniquely identifies each tuple in a relation (e.g., "Student_ID" for a student table).
- **Foreign Key:** An attribute in one table that links to the primary key in another.
- **Super Key:** A set of attributes that uniquely identify tuples (may contain more attributes than necessary).
- **Candidate Key:** Minimal superkey; no unnecessary attributes.

#### **3. Relational Constraints:**
- **Domain Constraint:** Attributes must have values from a specific domain (e.g., "Age" must be a positive integer).
- **Key Constraints:** Ensure uniqueness and proper identification of records.
- **Integrity Constraints:** Maintain the correctness of data (e.g., all foreign keys must match primary keys in the referenced table).

#### **4. Relational Algebra:**
- **Set Operations:** Union, Intersection, Difference - combining relations.
- **Selection (σ):** Extract rows based on specific conditions.
- **Projection (π):** Extract specific columns.
- **Join Operations:** Combine rows from two or more tables based on related attributes.

---

## **Unit 4: Query Processing**

### **Key Concepts:**

#### **1. Query Processing Steps:**
- Translating SQL queries into low-level instructions executed by the database.

#### **2. Heuristics for Query Optimization:**
- Techniques to transform queries into more efficient forms (e.g., pushing selection conditions earlier).

#### **3. Measures of Query Cost:**
- Cost is measured by factors like disk I/O, CPU usage, and memory usage.

#### **4. Evaluation of Expressions:**
- **Cost-Based Optimization:** Choosing the best execution plan based on cost estimation.

#### **5. Transformation of Relational Expressions:**
- Converting high-level queries into optimized, equivalent low-level expressions.

---

## **Unit 5: Optimization & Database Tuning**

### **Key Concepts:**

#### **1. Physical Database Design:**
- Selecting appropriate indexes, storage structures, and access paths.

#### **2. Factors Affecting Physical Design:**
- Query patterns, data volume, and data distribution.

#### **3. Database Tuning:**
- Improving performance through indexing, partitioning, and optimizing queries.

---

## **Unit 6: Functional Dependency Theory and Normalization**

### **Key Concepts:**

#### **1. Functional Dependency (FD):**
- Defines a relationship where one attribute uniquely determines another.
- **Example:** In a relation, if "Student_ID" determines "Student_Name," then Student_Name is functionally dependent on Student_ID.

#### **2. Normal Forms:**
- Techniques to structure database tables to eliminate redundancy and anomalies.
  - **1NF:** Eliminate duplicate columns; each column holds atomic values.
  - **2NF:** Remove partial dependencies (no non-key attribute depends on part of a composite key).
  - **3NF:** Eliminate transitive dependencies (no non-key attribute depends on another non-key attribute).
  - **BCNF:** Every determinant must be a candidate key.
  - **4NF:** Handle multi-valued dependencies.

---

## **Unit 7: SQL Advanced Concepts**

### **Key Concepts:**

#### **1. SQL Basics:**
- **DDL (Data Definition Language):** CREATE, ALTER, DROP.
- **DML (Data Manipulation Language):** SELECT, INSERT, UPDATE, DELETE.
- **DCL (Data Control Language):** GRANT, REVOKE.

#### **2. PL/SQL:**
- **Architecture:** Procedural extension to SQL.
- **Features:** Cursors (row-by-row data processing), Triggers (automatic actions), Stored Procedures (precompiled SQL code).

---

## **Unit 8: Transaction Management**

### **Key Concepts:**

#### **1. Transactions:**
- A **transaction** is a sequence of operations performed as a single logical unit of work. It is fundamental in ensuring database consistency and reliability.
- Transactions must adhere to the **ACID properties**:
  - **Atomicity:** The entire transaction is treated as a single unit that either fully completes or fails entirely. For example, transferring money between accounts must debit one and credit the other simultaneously.
  - **Consistency:** A transaction must transition the database from one consistent state to another. Consistency rules ensure that any data written to the database must be valid according to all defined rules.
  - **Isolation:** Ensures that transactions execute independently of each other, meaning intermediate states are invisible to other transactions.
  - **Durability:** Once a transaction is committed, its changes are permanent, even in the event of a system failure.

#### **2. Concurrency Control:**
- **Concurrency Control** manages simultaneous transaction execution to prevent conflicts and ensure isolation.
  - **Lock-Based Protocols:**
    - **Shared Locks (S):** Allow multiple transactions to read a resource but not modify it.
    - **Exclusive Locks (X):** Only one transaction can read and modify a resource.
  - **Two-Phase Locking (2PL):** A protocol ensuring serializability by acquiring all locks during the first phase (growing phase) and releasing them in the second phase (shrinking phase).
    - **Strict 2PL:** Holds all locks until the transaction commits, ensuring greater safety.
  
#### **3. Enhanced Lock-Based and Timestamp-Based Protocols:**
- **Timestamp-Based Protocols:** Assign a unique timestamp to each transaction. Transactions execute in timestamp order, ensuring consistency.
- **Validation-Based Protocols:** Allow transactions to execute without locks, checking at commit time whether any conflict occurred.

#### **4. Multiple Granularity:**
- Multiple granularity allows locking at various levels, such as rows, tables, or databases, to improve efficiency. For example:
  - **Row-Level Locks:** More granular and flexible but require more resources.
  - **Table-Level Locks:** Less overhead but reduce concurrency.

#### **5. Multi-version Schemes:**
- **Multi-Version Concurrency Control (MVCC):** Maintains multiple versions of data items to support concurrent reads and writes. This technique ensures that readers do not block writers and vice-versa, improving transaction throughput.

#### **6. Deadlock Handling:**
- **Deadlock** occurs when two or more transactions wait indefinitely for resources locked by each other. Deadlock handling techniques include:
  - **Deadlock Prevention:** Ensuring transactions don't hold resources that cause deadlocks (e.g., requesting all needed resources upfront).
  - **Deadlock Detection:** The system periodically checks for deadlocks and resolves them by aborting one of the transactions.
  - **Deadlock Avoidance:** Uses algorithms like Wait-Die and Wound-Wait to ensure deadlocks don't occur by controlling the way locks are requested.

---

## **Unit 9: Recovery**

### **Key Concepts:**

#### **1. Recovery and Atomicity:**
- Recovery ensures that the database remains consistent after failures (e.g., system crashes, disk failures). It ensures that transactions adhere to the Atomicity property, meaning partially executed transactions are rolled back to prevent inconsistency.

#### **2. Types of Failures:**
- **Transaction Failure:** Occurs when a transaction cannot complete due to logical errors or system issues.
- **System Failure:** Happens due to hardware/software issues causing a system crash.
- **Media Failure:** Refers to storage device corruption.

#### **3. Recovery Techniques:**
- **Log-Based Recovery:** Uses logs to record changes made by transactions. Logs include:
  - **Write-Ahead Logging (WAL):** Ensures that logs are written before changes are applied to the database, ensuring recoverability.
  - **Checkpointing:** Periodically saves the state of the database, reducing the amount of work during recovery by marking consistent states.
- **Undo/Redo Operations:**
  - **Undo:** Reverts uncommitted changes.
  - **Redo:** Reapplies committed changes that might not have been written to disk.

#### **4. Recovery with Concurrent Transactions:**
- Handling recovery when multiple transactions are running simultaneously requires careful coordination to maintain consistency. Techniques involve logging information about all active transactions and applying undo/redo operations in the correct sequence.

#### **5. Buffer Management:**
- Manages the transfer of data between memory (RAM) and disk storage. Efficient buffer management reduces disk I/O, enhancing performance. It ensures data consistency by writing data changes from buffers back to the disk.

#### **6. Advanced Recovery Techniques:**
- **Shadow Paging:** Maintains a shadow copy of the database, which remains unchanged until a transaction commits. If a failure occurs, the original data remains intact.
- **ARIES (Algorithm for Recovery and Isolation Exploiting Semantics):** A sophisticated recovery technique that efficiently handles transaction recovery using log records and checkpoints.

---

## **Unit 10: Database Security**

### **Key Concepts:**

#### **1. Database Security Concepts:**
- Protects data from unauthorized access, ensuring confidentiality, integrity, and availability.

#### **2. Levels of Database Security:**
- **Physical Security:** Protects hardware from theft or damage (e.g., secure data centers).
- **Operating System Security:** Ensures that only authorized users can access the system.
- **DBMS Security:** Uses authentication (username/password) and authorization (access rights).
- **Application Security:** Ensures that applications accessing the database follow security protocols.

#### **3. Access Control:**
- Determines who can access or modify data. Techniques include:
  - **Discretionary Access Control (DAC):** Users have control over access to their data.
  - **Mandatory Access Control (MAC):** Access is based on predefined rules (e.g., security labels).
  - **Role-Based Access Control (RBAC):** Access is assigned based on user roles within an organization.

#### **4. Multilevel Security:**
- Data is classified into levels (e.g., confidential, secret, top secret), and users have access based on their security clearance.

#### **5. Encryption Techniques:**
- Data is encrypted to prevent unauthorized access. Common methods include:
  - **Symmetric Encryption:** Same key for encryption/decryption.
  - **Asymmetric Encryption:** Different keys for encryption/decryption (public/private keys).

#### **6. SQL Injection Prevention:**
- SQL Injection attacks exploit vulnerabilities in SQL queries to gain unauthorized access. Prevention techniques include using prepared statements, input validation, and parameterized queries.

---

## **Unit 11: Introduction to Parallel Databases**

### **Key Concepts:**

#### **1. Parallel Database Architecture:**
- **Shared Memory:** All processors access the same memory.
- **Shared Disk:** All processors share the same disk but have their own memory.
- **Shared Nothing:** Each processor has its own memory and disk (scalable and commonly used).

#### **2. Types of Parallelism:**
- **Inter-Query Parallelism:** Different queries are executed in parallel.
- **Intra-Query Parallelism:** Different parts of a single query are executed simultaneously.
- **Intra-Operation Parallelism:** Parallel execution of a single operation (e.g., parallel sorting).
- **Inter-Operation Parallelism:** Parallel execution of different operations in a query plan.

#### **3. Parallel Query Evaluation:**
- Divides large queries into smaller tasks that can be executed concurrently. Techniques include:
  - **Data Partitioning:** Distributing data across different nodes (e.g., range partitioning, hash partitioning).
  - **Pipelining:** Passing results of one operation directly to the next without intermediate storage.

#### **4. Challenges in Parallel Databases:**
- **Load Balancing:** Ensuring even distribution of workload across processors.
- **Data Skew:** Uneven data distribution causing performance bottlenecks.

---

## **Unit 12: Introduction to Distributed Databases**

### **Key Concepts:**

#### **1. Distributed Database Concepts:**
- A **Distributed Database Management System (DDBMS)** manages a database spread across multiple locations, providing the illusion of a single unified database.

#### **2. Centralized vs. Non-Centralized Databases:**
- **Centralized:** Data resides in a single location, offering simplicity but less fault tolerance.
- **Non-Centralized (Distributed):** Data is stored across different locations, enhancing availability, reliability, and scalability.

#### **3. Homogeneous vs. Heterogeneous DDBMS:**
- **Homogeneous DDBMS:** All sites use the same DBMS software and follow the same schema.
- **Heterogeneous DDBMS:** Different sites may use different DBMS software or schemas.

#### **4. Distributed Database Design:**
- Data distribution strategies include:
  - **Fragmentation:** Breaking a database into smaller pieces (fragments) based on usage patterns. Types of fragmentation include:
    - **Horizontal Fragmentation:** Dividing rows across different locations.
    - **Vertical Fragmentation:** Dividing columns across different locations.
  - **Replication:** Storing copies of data at multiple sites to improve availability and reliability.
  - **Allocation:** Deciding where to place data fragments or replicas based on access patterns.

#### **5. Query Processing in DDBMS:**
- Involves translating high-level queries into execution plans that operate across multiple sites.
- **Challenges:** Efficiently handling data retrieval, data movement, and processing across distributed locations.

#### **6. Distributed Concurrency Management:**
- Ensuring data consistency when multiple transactions execute simultaneously across different locations.
- **Two-Phase Commit Protocol (2PC):** Ensures

 all sites agree on the outcome (commit/abort) of a transaction, maintaining atomicity and consistency in distributed transactions.

#### **7. Distributed Deadlock Detection:**
- Deadlocks in distributed databases are harder to detect. Algorithms such as centralized or distributed wait-for graphs help manage deadlocks effectively.

---

