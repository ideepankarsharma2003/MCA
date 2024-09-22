

## **Unit 1: Introduction to DBMS**

### **Key Concepts:**
- **Data and Database:**
  - **Data:** Raw facts and figures without context (e.g., numbers, names, dates).
  - **Database:** A collection of organized data that allows easy access, management, and updating.

- **Database Management System (DBMS):**
  - A software system that enables users to define, create, maintain, and control access to the database.
  
- **Database System Concepts and Architecture:**
  - **Database System:** Combination of DBMS software and database.
  - **Components:** Users, DBMS, Database itself, Hardware, and Application Programs.

- **Three Schema Architecture:**
  - **Internal Schema:** Physical storage structure.
  - **Conceptual Schema:** Logical structure of the entire database.
  - **External Schema:** View level, representing various users’ views.

- **Data Independence:**
  - **Logical Data Independence:** Ability to change conceptual schema without altering external schema.
  - **Physical Data Independence:** Ability to change internal schema without affecting conceptual schema.

---

## **Unit 2: Enhanced Entity Relationship Model (EER)**

### **Key Concepts:**
- **Entity-Relationship (ER) Model:**
  - **Entity:** Real-world object with distinct existence (e.g., Student, Employee).
  - **Attributes:** Properties of entities (e.g., Name, ID).
  - **Entity Sets:** Collection of similar entities.

- **Weak Entity Types:**
  - Entities that cannot be uniquely identified without a related entity.
  
- **Relationship Types:**
  - Define how entities are related.

- **Enhanced ER Tools:**
  - **Subclasses and Superclasses:** Specialization (defining sub-entities) and Generalization (defining a higher-level entity).
  - **Inheritance:** Properties inherited from superclass to subclass.
  - **Specialization & Generalization:** Defining more specialized or generalized relationships between entities.
  
- **Constraints:** 
  - Defining rules for specialization/generalization.

- **EER Diagram Case Studies:** Use EER diagrams to model complex relationships.

---

## **Unit 3: Introduction to Relational Model**

### **Key Concepts:**
- **Relational Model Structure:**
  - Data is organized into tables (relations), with rows (tuples) and columns (attributes).

- **Keys:**
  - **Primary Key:** Unique identifier for a row.
  - **Foreign Key:** Reference to a primary key in another table.
  - **Super Key & Candidate Key:** Unique attribute or a set of attributes to identify tuples.

- **Relational Constraints:**
  - **Domain Constraints:** Values must belong to a specific domain.
  - **Key Constraints:** Primary keys should be unique.
  - **Integrity Constraints:** Ensures data accuracy and consistency.

- **Relational Algebra Operations:**
  - **Set Operations:** Union, Intersection, Difference.
  - **Cartesian Product:** Combining tuples from two relations.
  - **Relational Operations:** Select, Project, Join, Division.

---

## **Unit 4: Query Processing**

### **Key Concepts:**
- **Query Processing Stages:**
  - Translating SQL queries into execution plans.

- **Heuristics for Query Optimization:**
  - Rules used to improve query performance.

- **Measures of Query Cost:** 
  - Metrics to evaluate the efficiency of query execution.

- **Evaluation of Expression:**
  - Execution strategies for relational expressions.

- **Transformation of Relational Expressions:** 
  - Converting expressions into equivalent but more efficient forms.

---

## **Unit 5: Optimization & Database Tuning**

### **Key Concepts:**
- **Physical Database Design:**
  - Deciding storage structures and access methods for efficient data retrieval.

- **Factors Influencing Physical Design:**
  - Data volume, query types, access patterns.

- **Database Tuning Techniques:**
  - Index creation, query rewriting, denormalization, hardware optimization.

---

## **Unit 6: Functional Dependency Theory and Normalization**

### **Key Concepts:**
- **Functional Dependency (FD):**
  - Relationship between attributes where one attribute determines another.

- **Normalization Process:**
  - **First Normal Form (1NF):** Eliminates repeating groups.
  - **Second Normal Form (2NF):** Removes partial dependencies.
  - **Third Normal Form (3NF):** Eliminates transitive dependencies.
  - **Boyce-Codd Normal Form (BCNF):** Advanced version of 3NF.
  - **Fourth Normal Form (4NF):** Handles multivalued dependencies.

---

## **Unit 7: SQL Advanced Concepts**

### **Key Concepts:**
- **SQL Basics:**
  - **DDL (Data Definition Language):** CREATE, ALTER, DROP.
  - **DML (Data Manipulation Language):** SELECT, INSERT, UPDATE, DELETE.
  - **DCL (Data Control Language):** GRANT, REVOKE.

- **Views and Constraints:**
  - Virtual tables and data constraints in SQL.

- **PL/SQL:**
  - **Architecture:** Procedural language extension for SQL.
  - **Cursors, Triggers, Stored Procedures:** Advanced database programming elements.

---

## **Unit 8: Transaction Management**

### **Key Concepts:**
- **Transaction Properties (ACID):**
  - **Atomicity, Consistency, Isolation, Durability.**

- **Lock-Based and Timestamp Protocols:**
  - Mechanisms for handling concurrency.

- **Multiple Granularity:** 
  - Different levels of locking (row, table, database).

- **Multi-version Schemes:** 
  - Maintaining multiple versions of data for concurrency.

- **Deadlock Handling:** 
  - Detecting and resolving deadlocks.

---

## **Unit 9: Recovery**

### **Key Concepts:**
- **Recovery Techniques:**
  - Ensuring data integrity in case of failure.

- **Buffer Management:**
  - Managing data exchange between memory and disk.

- **Advanced Recovery Techniques:** 
  - Checkpointing, logging, and transaction rollback.

---

## **Unit 10: Database Security**

### **Key Concepts:**
- **Database Security Levels:**
  - **Access Control:** Permissions for users.
  - **Multilevel Security:** Protecting data at different sensitivity levels.

---

## **Unit 11: Introduction to Parallel Databases**

### **Key Concepts:**
- **Parallel Database Architecture:**
  - Distributing data across multiple processors to improve performance.

- **Parallel Query Evaluation:** 
  - Executing queries in parallel to reduce response time.

---

## **Unit 12: Introduction to Distributed Databases**

### **Key Concepts:**
- **Centralized vs. Non-Centralized Databases:**
  - Differences in data storage and management.

- **Distributed Database Systems (DDBMS):**
  - **Homogeneous:** Uniform architecture.
  - **Heterogeneous:** Different architectures.

- **Distributed Database Design & Query Processing:**
  - Data distribution strategies and efficient query execution in a distributed environment.

- **Distributed Concurrency Management:** 
  - Ensuring consistency across multiple locations.

---
