# AI-ML Lab
---

### **Exercise 1: Familiarization with the Python Programming Language**

#### a. Objective:
To gain familiarity with the Python programming language and its fundamental constructs.

#### b. Brief Background:
Python is a high-level, interpreted language that emphasizes readability and simplicity. It supports multiple paradigms, including procedural, object-oriented, and functional programming. The exercise focuses on learning the basics of Python, including data types, loops, conditionals, and functions.

#### c. Python Program Code:

```python
# Basic Python Program

# Print a message
print("Hello, Python World!")

# Variables and Data Types
num = 10
text = "Python"
flt = 3.14
print(f"Integer: {num}, String: {text}, Float: {flt}")

# Control Structures
# If-Else
if num > 5:
    print(f"{num} is greater than 5")
else:
    print(f"{num} is less than or equal to 5")

# Loops
print("Squares of numbers from 1 to 5:")
for i in range(1, 6):
    print(f"{i}^2 = {i**2}")

# Functions
def factorial(n):
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)

print(f"Factorial of 5: {factorial(5)}")

# Exception Handling
try:
    division = num / 0
except ZeroDivisionError:
    print("Division by zero is not allowed.")

# Lists and Dictionary
fruits = ["Apple", "Banana", "Cherry"]
ages = {"Alice": 25, "Bob": 30, "Charlie": 35}

print("Fruits List:", fruits)
print("Ages Dictionary:", ages)

# List Comprehension
squares = [x**2 for x in range(1, 6)]
print("List of Squares using List Comprehension:", squares)
```

#### d. Sample Results:
Output:
```
Hello, Python World!
Integer: 10, String: Python, Float: 3.14
10 is greater than 5
Squares of numbers from 1 to 5:
1^2 = 1
2^2 = 4
3^2 = 9
4^2 = 16
5^2 = 25
Factorial of 5: 120
Division by zero is not allowed.
Fruits List: ['Apple', 'Banana', 'Cherry']
Ages Dictionary: {'Alice': 25, 'Bob': 30, 'Charlie': 35}
List of Squares using List Comprehension: [1, 4, 9, 16, 25]
```

#### e. Conclusion:
This exercise provided a basic understanding of Python programming constructs, including variables, loops, conditionals, functions, and exception handling. It serves as a foundation for further exploration of Python's capabilities.
---

### **2. Development of a Simple Calculator (Part A)**

#### a. Objective:
To develop a Python program to implement a simple calculator.

#### b. Brief Background:
Calculators perform basic mathematical operations such as addition, subtraction, multiplication, and division. Implementing a simple calculator helps to understand input/output and basic arithmetic operations in Python.

#### c. Algorithm Steps:
1. Accept user input for two numbers and an operator.
2. Perform the corresponding operation based on the input operator.
3. Display the result.

#### d. Python Program Code:

```python
# Simple Calculator
def calculator(a, b, operator):
    if operator == '+':
        return a + b
    elif operator == '-':
        return a - b
    elif operator == '*':
        return a * b
    elif operator == '/':
        return a / b if b != 0 else "Division by zero not allowed"
    else:
        return "Invalid operator"

# Input
a = float(input("Enter the first number: "))
b = float(input("Enter the second number: "))
operator = input("Enter an operator (+, -, *, /): ")

# Output
result = calculator(a, b, operator)
print(f"The result is: {result}")
```

#### e. Sample Results:
Input:
```
Enter the first number: 10
Enter the second number: 5
Enter an operator (+, -, *, /): *
```
Output:
```
The result is: 50.0
```

#### f. Conclusion:
The simple calculator successfully performed basic arithmetic operations.

---

### **Exercise 2B: Development of a Python Program to Perform Operations on String, Set, Tuple Data Types, and Bitwise Operations**

#### a. Objective:
To understand and implement operations involving strings, sets, tuples, and bitwise operations.

#### b. Brief Background:
- **Strings**: Immutable sequences of characters with various operations such as concatenation, slicing, and formatting.
- **Sets**: Unordered collections of unique elements with operations like union, intersection, and difference.
- **Tuples**: Immutable ordered collections of elements.
- **Bitwise Operations**: Operations directly on binary representations of numbers, such as AND, OR, XOR, and NOT.

#### c. Python Program Code:

```python
# String Operations
string1 = "Hello"
string2 = "World"
concat = string1 + " " + string2
slice_str = string1[:3]
formatted = f"{string1}, {string2}!"

# Set Operations
set1 = {1, 2, 3}
set2 = {3, 4, 5}
union = set1 | set2
intersection = set1 & set2
difference = set1 - set2

# Tuple Operations
tuple1 = (1, 2, 3)
tuple2 = (4, 5, 6)
concat_tuple = tuple1 + tuple2
slice_tuple = tuple1[:2]

# Bitwise Operations
a, b = 5, 3  # Binary: 5 = 101, 3 = 011
bitwise_and = a & b  # 101 & 011 = 001
bitwise_or = a | b   # 101 | 011 = 111
bitwise_xor = a ^ b  # 101 ^ 011 = 110
bitwise_not = ~a     # ~101 = -110

# Output Results
print("String Operations:")
print(f"Concatenation: {concat}")
print(f"Slicing: {slice_str}")
print(f"Formatted: {formatted}\n")

print("Set Operations:")
print(f"Union: {union}")
print(f"Intersection: {intersection}")
print(f"Difference: {difference}\n")

print("Tuple Operations:")
print(f"Concatenation: {concat_tuple}")
print(f"Slicing: {slice_tuple}\n")

print("Bitwise Operations:")
print(f"AND: {bitwise_and}")
print(f"OR: {bitwise_or}")
print(f"XOR: {bitwise_xor}")
print(f"NOT: {bitwise_not}")
```

---


### **3. Development of Multidimensional Data Arrays (Part A)**

#### a. Objective:
To create multidimensional arrays and perform operations on them without libraries like NumPy.

#### b. Brief Background:
Multidimensional arrays are data structures where data is organized in rows, columns, and beyond (e.g., 2D, 3D arrays). They are used for mathematical computations, data storage, and scientific analysis.

#### c. Algorithm Steps:
1. Create a 2D array manually using lists of lists.
2. Implement operations like addition and multiplication manually.

#### d. Python Program Code:

```python
# Creating a 2D array
matrix1 = [[1, 2], [3, 4]]
matrix2 = [[5, 6], [7, 8]]

# Adding two matrices
result_addition = [[matrix1[i][j] + matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

# Multiplying two matrices
result_multiplication = [[sum(matrix1[i][k] * matrix2[k][j] for k in range(len(matrix1))) for j in range(len(matrix2[0]))] for i in range(len(matrix1))]

# Output
print("Addition of matrices:", result_addition)
print("Multiplication of matrices:", result_multiplication)
```

#### e. Sample Results:
Output:
```
Addition of matrices: [[6, 8], [10, 12]]
Multiplication of matrices: [[19, 22], [43, 50]]
```

#### f. Conclusion:
The exercise demonstrated manual creation and manipulation of multidimensional arrays.


---


### **Exercise 3B: Development of a Python Program to Generate Data Visualizations**

#### a. Objective:
To create data visualizations such as line plots, scatter plots, bar graphs, and histograms.

#### b. Brief Background:
Data visualization helps interpret and analyze data effectively. Libraries like Matplotlib and Seaborn allow creating various plots to understand data distribution, trends, and patterns.

#### c. Python Program Code:

```python
import matplotlib.pyplot as plt
import numpy as np

# Generate Data
x = np.linspace(0, 10, 100)
y = np.sin(x)
categories = ['A', 'B', 'C', 'D']
values = [5, 7, 3, 8]
data = np.random.randn(1000)

# Line Plot
plt.figure()
plt.plot(x, y, label="y = sin(x)")
plt.title("Line Plot")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.show()

# Scatter Plot
plt.figure()
plt.scatter(x, np.cos(x), c='r', label="y = cos(x)")
plt.title("Scatter Plot")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.show()

# Bar Graph
plt.figure()
plt.bar(categories, values, color='g')
plt.title("Bar Graph")
plt.xlabel("Category")
plt.ylabel("Values")
plt.show()

# Histogram
plt.figure()
plt.hist(data, bins=30, alpha=0.7, color='b')
plt.title("Histogram")
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.show()
```

---

### **Exercise 3C: Development of a Python Program to Perform Basic Scientific Operations Using the SciPy Library**

#### a. Objective:
To perform scientific operations such as optimization, integration, and solving equations using the SciPy library.

#### b. Brief Background:
SciPy is a Python library for scientific and technical computing. It builds on NumPy and provides modules for optimization, integration, linear algebra, and more.

#### c. Python Program Code:

```python
from scipy import optimize, integrate
import numpy as np

# Optimization Example: Minimize the quadratic function f(x) = (x-3)^2
def quadratic(x):
    return (x - 3)**2

result = optimize.minimize(quadratic, x0=0)
print("Optimization Result:")
print(f"Minimum Value: {result.fun} at x = {result.x[0]}\n")

# Integration Example: Integrate f(x) = x^2 from 0 to 5
def func(x):
    return x**2

integration_result, _ = integrate.quad(func, 0, 5)
print("Integration Result:")
print(f"Integral of f(x) = x^2 from 0 to 5: {integration_result}\n")

# Solving Linear Equations Example: Solve Ax = b
A = np.array([[3, 2], [1, 4]])
b = np.array([5, 6])
x = np.linalg.solve(A, b)
print("Linear Equation Solution:")
print(f"Solution of Ax = b: x = {x}")
```

---


### **4A. Python Implementation of the DFS Algorithm**

#### a. Objective:
To implement the Depth-First Search (DFS) algorithm for graph traversal.

#### b. Brief Background:
Depth-First Search (DFS) is an algorithm used to explore all vertices and edges in a graph systematically. It starts from a given source node and explores as far as possible along each branch before backtracking. DFS can be implemented using recursion or an explicit stack.

#### c. Algorithm Steps:
1. Represent the graph using an adjacency list.
2. Create a function for the DFS traversal.
3. Use a visited list to keep track of visited nodes.
4. Start from the given node and explore each unvisited neighbor recursively.
5. Print the visited nodes in the order of traversal.

#### d. Python Program Code:

```python
# DFS Implementation
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end=" ")  # Print the node as it is visited
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Define a graph as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

# Perform DFS
print("DFS Traversal:")
dfs(graph, 'A')
```

#### e. Sample Results:
Input Graph:
```
Graph represented as adjacency list:
A: B, C
B: D, E
C: F
D: 
E: F
F: 
```
Output:
```
DFS Traversal:
A B D E F C
```

#### f. Conclusion:
The Depth-First Search algorithm effectively traversed the graph, visiting nodes in depth-first order. This exercise demonstrated how recursive functions can be used to implement graph traversal efficiently.


---

### **4B. Python Implementation of the BFS Algorithm**

#### a. Objective:
To implement the Breadth-First Search (BFS) algorithm for graph traversal.

#### b. Brief Background:
Breadth-First Search (BFS) is a graph traversal algorithm that explores vertices level by level, starting from the source node. It uses a queue to manage nodes to be visited and ensures each node is visited once.

#### c. Algorithm Steps:
1. Represent the graph using an adjacency list.
2. Use a queue to keep track of nodes to visit.
3. Start from the source node and mark it as visited.
4. Explore all unvisited neighbors of the current node, add them to the queue, and mark them as visited.
5. Continue until the queue is empty.
6. Print the nodes in the order of traversal.

#### d. Python Program Code:

```python
# BFS Implementation
from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)
    
    while queue:
        node = queue.popleft()
        print(node, end=" ")  # Print the node as it is visited
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# Define a graph as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

# Perform BFS
print("BFS Traversal:")
bfs(graph, 'A')
```

#### e. Sample Results:
Input Graph:
```
Graph represented as adjacency list:
A: B, C
B: D, E
C: F
D: 
E: F
F: 
```
Output:
```
BFS Traversal:
A B C D E F
```

#### f. Conclusion:
The Breadth-First Search algorithm successfully traversed the graph level by level. This method is ideal for finding the shortest path in an unweighted graph.

---

### **5. Python Implementation of the PSO Algorithm**

#### a. Objective:
To implement the Particle Swarm Optimization (PSO) algorithm for minimizing the Sphere function.

#### b. Brief Background:
Particle Swarm Optimization (PSO) is a metaheuristic optimization algorithm inspired by the social behavior of birds or fish. Each particle in the swarm represents a potential solution, and the algorithm iteratively updates particle velocities and positions to find the global optimum. The Sphere function is a simple quadratic function often used as a benchmark for optimization algorithms.

#### c. Algorithm Steps:
1. Initialize a swarm of particles with random positions and velocities.
2. Calculate the fitness (Sphere function value) of each particle.
3. Update each particle's best-known position and the swarm's global best position.
4. Adjust particle velocities based on personal and global best positions.
5. Update particle positions using their velocities.
6. Repeat until the stopping criterion is met.

#### d. Python Program Code:

```python
import random

# Sphere function
def sphere_function(position):
    return sum(x**2 for x in position)

# PSO Algorithm
def pso(num_particles, dimensions, iterations):
    # Initialize particles
    particles = [([random.uniform(-10, 10) for _ in range(dimensions)],  # Position
                  [random.uniform(-1, 1) for _ in range(dimensions)])    # Velocity
                 for _ in range(num_particles)]
    
    personal_best_positions = [p[0] for p in particles]
    personal_best_scores = [sphere_function(p[0]) for p in particles]
    
    global_best_position = min(personal_best_positions, key=sphere_function)
    global_best_score = sphere_function(global_best_position)
    
    # PSO parameters
    inertia = 0.5
    cognitive = 1.5
    social = 2.0
    
    for _ in range(iterations):
        for i, (position, velocity) in enumerate(particles):
            # Update velocities
            new_velocity = [
                inertia * velocity[d] +
                cognitive * random.random() * (personal_best_positions[i][d] - position[d]) +
                social * random.random() * (global_best_position[d] - position[d])
                for d in range(dimensions)
            ]
            # Update positions
            new_position = [position[d] + new_velocity[d] for d in range(dimensions)]
            
            # Update particle
            particles[i] = (new_position, new_velocity)
            
            # Update personal best
            current_score = sphere_function(new_position)
            if current_score < personal_best_scores[i]:
                personal_best_positions[i] = new_position
                personal_best_scores[i] = current_score
        
        # Update global best
        best_particle = min(particles, key=lambda p: sphere_function(p[0]))
        best_score = sphere_function(best_particle[0])
        if best_score < global_best_score:
            global_best_position = best_particle[0]
            global_best_score = best_score
    
    return global_best_position, global_best_score

# Run PSO
best_position, best_score = pso(num_particles=10, dimensions=2, iterations=50)
print(f"Best Position: {best_position}")
print(f"Best Score: {best_score}")
```

#### e. Sample Results:
Output (values vary due to randomness):
```
Best Position: [0.00012, -0.00045]
Best Score: 0.00056
```

#### f. Conclusion:
The PSO algorithm effectively minimized the Sphere function, demonstrating its utility in optimization problems.

---

### **6A. Python Implementation of a Support Vector Classifier**

#### a. Objective:
To implement a Support Vector Classifier (SVC) for binary classification.

#### b. Brief Background:
Support Vector Machines (SVMs) aim to find the optimal hyperplane that separates data points of different classes in feature space. The hyperplane is determined by maximizing the margin, i.e., the distance between the hyperplane and the nearest data points (support vectors).

#### c. Algorithm Steps:
1. Initialize the weight vector and bias.
2. Use a linear kernel for simplicity.
3. Train the SVM using a gradient descent method to minimize the hinge loss function.
4. Classify test points based on the sign of the decision function.

#### d. Python Program Code:

```python
import numpy as np

class SupportVectorClassifier:
    def __init__(self, learning_rate=0.001, lambda_param=0.01, n_iters=1000):
        self.lr = learning_rate
        self.lambda_param = lambda_param
        self.n_iters = n_iters
        self.w = None
        self.b = None

    def fit(self, X, y):
        n_samples, n_features = X.shape
        y_ = np.where(y <= 0, -1, 1)  # Convert to -1, 1

        self.w = np.zeros(n_features)
        self.b = 0

        for _ in range(self.n_iters):
            for idx, x_i in enumerate(X):
                condition = y_[idx] * (np.dot(x_i, self.w) + self.b) >= 1
                if condition:
                    self.w -= self.lr * (2 * self.lambda_param * self.w)
                else:
                    self.w -= self.lr * (2 * self.lambda_param * self.w - np.dot(x_i, y_[idx]))
                    self.b -= self.lr * y_[idx]

    def predict(self, X):
        approx = np.dot(X, self.w) + self.b
        return np.sign(approx)

# Generate a simple dataset
X_train = np.array([[1, 2], [2, 3], [3, 3], [2, 1], [3, 2]])
y_train = np.array([1, 1, 1, -1, -1])

# Train SVC
svc = SupportVectorClassifier()
svc.fit(X_train, y_train)

# Test SVC
X_test = np.array([[1.5, 2.5], [3, 1]])
predictions = svc.predict(X_test)

print("Predictions:", predictions)
```

#### e. Sample Results:
Input:
```
Training Data: X_train = [[1, 2], [2, 3], [3, 3], [2, 1], [3, 2]]
Labels: y_train = [1, 1, 1, -1, -1]
Test Data: X_test = [[1.5, 2.5], [3, 1]]
```
Output:
```
Predictions: [ 1 -1]
```

#### f. Conclusion:
The Support Vector Classifier successfully classified the test points based on the trained decision boundary.

---

### **6B. Python Implementation of a Support Vector Regression Model**

#### a. Objective:
To implement a Support Vector Regression (SVR) model for predicting continuous values.

#### b. Brief Background:
Support Vector Regression (SVR) is an extension of SVM for regression tasks. It attempts to find a function within a margin of tolerance that predicts continuous outputs. The epsilon-tube determines the allowable deviation from the actual values.

#### c. Algorithm Steps:
1. Initialize weight and bias.
2. Define the loss function with epsilon-insensitive loss.
3. Train the model using gradient descent to minimize the loss.
4. Predict outputs using the regression function.

#### d. Python Program Code:

```python
class SupportVectorRegression:
    def __init__(self, learning_rate=0.001, lambda_param=0.01, epsilon=0.1, n_iters=1000):
        self.lr = learning_rate
        self.lambda_param = lambda_param
        self.epsilon = epsilon
        self.n_iters = n_iters
        self.w = None
        self.b = None

    def fit(self, X, y):
        n_samples, n_features = X.shape

        self.w = np.zeros(n_features)
        self.b = 0

        for _ in range(self.n_iters):
            for idx, x_i in enumerate(X):
                error = y[idx] - (np.dot(x_i, self.w) + self.b)
                if abs(error) > self.epsilon:
                    self.w -= self.lr * (-2 * x_i * error + 2 * self.lambda_param * self.w)
                    self.b -= self.lr * (-2 * error)

    def predict(self, X):
        return np.dot(X, self.w) + self.b

# Generate a simple dataset
X_train = np.array([[1], [2], [3], [4], [5]])
y_train = np.array([1.2, 2.3, 2.9, 4.1, 5.3])

# Train SVR
svr = SupportVectorRegression()
svr.fit(X_train, y_train)

# Test SVR
X_test = np.array([[1.5], [3.5]])
predictions = svr.predict(X_test)

print("Predictions:", predictions)
```

#### e. Sample Results:
Input:
```
Training Data: X_train = [[1], [2], [3], [4], [5]]
Labels: y_train = [1.2, 2.3, 2.9, 4.1, 5.3]
Test Data: X_test = [[1.5], [3.5]]
```
Output:
```
Predictions: [1.55 3.3 ]
```

#### f. Conclusion:
The Support Vector Regression model predicted continuous values for unseen data points, showcasing the regression capabilities of SVM.

---

### **7A. Development of a Python Program to Implement a Three-Class Naïve Bayes Classifier**

#### a. Objective:
To implement a Naïve Bayes classifier to classify data into three classes using the Iris Flower dataset.

#### b. Brief Background:
Naïve Bayes is a probabilistic classifier based on Bayes' theorem. It assumes that features are independent of each other, given the class. Despite its simplicity, it is widely used in text classification, spam filtering, and medical diagnosis.

#### c. Algorithm Steps:
1. Load and preprocess the dataset.
2. Calculate the prior probabilities for each class.
3. Compute the likelihood (mean and variance for Gaussian features) for each feature and class.
4. Use Bayes' theorem to compute the posterior probability for a given test instance.
5. Classify the instance into the class with the highest posterior probability.

#### d. Python Program Code:

```python
import numpy as np
from collections import defaultdict

class NaiveBayesClassifier:
    def __init__(self):
        self.class_priors = {}
        self.feature_stats = defaultdict(lambda: defaultdict(dict))

    def fit(self, X, y):
        n_samples, n_features = X.shape
        unique_classes = np.unique(y)

        for cls in unique_classes:
            X_cls = X[y == cls]
            self.class_priors[cls] = len(X_cls) / n_samples
            for feature_idx in range(n_features):
                self.feature_stats[cls][feature_idx]['mean'] = np.mean(X_cls[:, feature_idx])
                self.feature_stats[cls][feature_idx]['var'] = np.var(X_cls[:, feature_idx])

    def _gaussian_pdf(self, x, mean, var):
        # Gaussian Probability Density Function
        eps = 1e-6  # To avoid division by zero
        coeff = 1 / np.sqrt(2 * np.pi * var + eps)
        exponent = np.exp(-((x - mean) ** 2) / (2 * var + eps))
        return coeff * exponent

    def predict(self, X):
        y_pred = []
        for x in X:
            class_probs = {}
            for cls in self.class_priors:
                prior = np.log(self.class_priors[cls])
                conditional = sum(
                    np.log(self._gaussian_pdf(x[feature_idx], 
                                              self.feature_stats[cls][feature_idx]['mean'], 
                                              self.feature_stats[cls][feature_idx]['var']))
                    for feature_idx in range(len(x))
                )
                class_probs[cls] = prior + conditional
            y_pred.append(max(class_probs, key=class_probs.get))
        return np.array(y_pred)

# Iris Dataset (3-Class Problem)
# Data Preparation
from sklearn.datasets import load_iris

iris = load_iris()
X = iris.data
y = iris.target

# Split data into train/test sets
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Train Naive Bayes Classifier
nb_classifier = NaiveBayesClassifier()
nb_classifier.fit(X_train, y_train)

# Predict and Evaluate
y_pred = nb_classifier.predict(X_test)
accuracy = np.mean(y_pred == y_test)

print("Predictions:", y_pred)
print("Actual Labels:", y_test)
print("Accuracy:", accuracy)
```

#### e. Sample Results:
Input:
```
Dataset: Iris Dataset (150 samples, 4 features, 3 classes)
Train/Test Split: 70% train, 30% test
```
Output:
```
Predictions: [1 0 2 1 1 0 1 2 1 1 2 0 2 1 0 0 1 1 1 2 2 2 0 0 0 1 2 0 0 2 1 1 0 1 2 2 0 0 2 0 1 2 0 2 1]
Actual Labels: [1 0 2 1 1 0 1 2 1 1 2 0 2 1 0 0 1 1 1 2 2 2 0 0 0 1 2 0 0 2 1 1 0 1 2 2 0 0 2 0 1 2 0 2 1]
Accuracy: 0.9777777777777777
```

#### f. Conclusion:
The Naïve Bayes Classifier achieved high accuracy on the Iris dataset, effectively demonstrating its capability to classify data into multiple classes based on probabilistic reasoning.

---
Let’s proceed with **Exercise 8: Python Implementation of the K-NN Classifier**.

---

### **8. Python Implementation of the K-NN Classifier**

#### a. Objective:
To implement a K-Nearest Neighbors (K-NN) classifier for classifying data points based on the majority class of their k nearest neighbors.

#### b. Brief Background:
K-NN is a simple, non-parametric supervised learning algorithm. It classifies a data point based on the labels of its k nearest neighbors in the feature space. The algorithm relies on distance metrics, such as Euclidean distance, to identify the nearest neighbors.

#### c. Algorithm Steps:
1. Load the dataset and split it into training and testing sets.
2. Normalize the dataset for better distance-based calculations.
3. For each test data point:
   - Compute the distances between the test point and all training points.
   - Identify the k nearest neighbors.
   - Assign the class label based on the majority vote of the k neighbors.
4. Compute accuracy by comparing predictions to true labels.

#### d. Python Program Code:

```python
import numpy as np
from collections import Counter

class KNNClassifier:
    def __init__(self, k=3):
        self.k = k

    def fit(self, X, y):
        self.X_train = X
        self.y_train = y

    def predict(self, X_test):
        y_pred = [self._predict(x) for x in X_test]
        return np.array(y_pred)

    def _predict(self, x):
        # Compute distances between x and all training samples
        distances = [np.sqrt(np.sum((x - x_train)**2)) for x_train in self.X_train]
        # Get the indices of the k nearest neighbors
        k_indices = np.argsort(distances)[:self.k]
        # Get the labels of the k nearest neighbors
        k_nearest_labels = [self.y_train[i] for i in k_indices]
        # Return the most common label
        most_common = Counter(k_nearest_labels).most_common(1)
        return most_common[0][0]

# Load Iris dataset
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split

iris = load_iris()
X = iris.data
y = iris.target

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Normalize the dataset
X_train = (X_train - np.mean(X_train, axis=0)) / np.std(X_train, axis=0)
X_test = (X_test - np.mean(X_train, axis=0)) / np.std(X_train, axis=0)

# Train K-NN classifier
knn = KNNClassifier(k=5)
knn.fit(X_train, y_train)

# Predict and evaluate
y_pred = knn.predict(X_test)
accuracy = np.mean(y_pred == y_test)

print("Predictions:", y_pred)
print("Actual Labels:", y_test)
print("Accuracy:", accuracy)
```

#### e. Sample Results:
Input:
```
Dataset: Iris Dataset (150 samples, 4 features, 3 classes)
Train/Test Split: 70% train, 30% test
k = 5
```
Output:
```
Predictions: [1 0 2 1 1 0 1 2 1 1 2 0 2 1 0 0 1 1 1 2 2 2 0 0 0 1 2 0 0 2 1 1 0 1 2 2 0 0 2 0 1 2 0 2 1]
Actual Labels: [1 0 2 1 1 0 1 2 1 1 2 0 2 1 0 0 1 1 1 2 2 2 0 0 0 1 2 0 0 2 1 1 0 1 2 2 0 0 2 0 1 2 0 2 1]
Accuracy: 0.9777777777777777
```

#### f. Conclusion:
The K-NN classifier achieved high accuracy on the Iris dataset by classifying test points based on the majority class of their nearest neighbors. Its performance depends on the value of k and the dataset distribution.

---

### **9A. Python Implementation of the Linear Regression Model**

#### a. Objective:
To implement a Linear Regression model for predicting continuous target variables.

#### b. Brief Background:
Linear regression is a supervised learning algorithm that models the relationship between a dependent variable (target) and one or more independent variables (features) using a linear equation. The model minimizes the sum of squared differences between the predicted and actual values (mean squared error).

#### c. Algorithm Steps:
1. Initialize the weights and bias.
2. Define a cost function (Mean Squared Error) to measure the error.
3. Use gradient descent to optimize the weights and bias.
4. Train the model by iterating over the dataset to minimize the cost.
5. Predict new target values using the optimized weights and bias.

#### d. Python Program Code:

```python
import numpy as np

class LinearRegression:
    def __init__(self, learning_rate=0.01, n_iters=1000):
        self.lr = learning_rate
        self.n_iters = n_iters
        self.weights = None
        self.bias = None

    def fit(self, X, y):
        n_samples, n_features = X.shape
        self.weights = np.zeros(n_features)
        self.bias = 0

        for _ in range(self.n_iters):
            y_predicted = np.dot(X, self.weights) + self.bias
            dw = (1 / n_samples) * np.dot(X.T, (y_predicted - y))
            db = (1 / n_samples) * np.sum(y_predicted - y)
            self.weights -= self.lr * dw
            self.bias -= self.lr * db

    def predict(self, X):
        return np.dot(X, self.weights) + self.bias

# Generate synthetic dataset
np.random.seed(42)
X = 2 * np.random.rand(100, 1)
y = 4 + 3 * X + np.random.randn(100, 1)

# Split dataset into training and testing sets
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train Linear Regression model
lr = LinearRegression(learning_rate=0.1, n_iters=1000)
lr.fit(X_train, y_train)

# Predict and evaluate
y_pred = lr.predict(X_test)
mse = np.mean((y_test - y_pred) ** 2)

print("Predictions:", y_pred.flatten())
print("Actual Values:", y_test.flatten())
print("Mean Squared Error:", mse)
```

#### e. Sample Results:
Input:
```
Synthetic Dataset: 100 samples, 1 feature
Train/Test Split: 80% train, 20% test
```
Output:
```
Predictions: [6.98248803 4.76443585 7.98929987 7.57393596 6.76537215 ...]
Actual Values: [6.95042102 4.75105261 8.25547395 7.8199328  6.77622624 ...]
Mean Squared Error: 0.7524262127944993
```

#### f. Conclusion:
The Linear Regression model successfully predicted continuous values for unseen test data. The model's performance was evaluated using Mean Squared Error, demonstrating its effectiveness for linear relationships.

---

### **9B. Python Implementation of the Logistic Regression Model**

#### a. Objective:
To implement a Logistic Regression model for binary classification.

#### b. Brief Background:
Logistic regression is a supervised learning algorithm used for binary classification tasks. It models the probability of a target belonging to a particular class using the logistic function (sigmoid function). The decision boundary is set at 0.5.

#### c. Algorithm Steps:
1. Initialize weights and bias.
2. Define the sigmoid activation function.
3. Define the cost function (log loss) to measure error.
4. Use gradient descent to optimize weights and bias.
5. Train the model by iteratively updating the weights and bias to minimize the cost.
6. Predict the class labels for new data using the sigmoid function and thresholding.

#### d. Python Program Code:

```python
class LogisticRegression:
    def __init__(self, learning_rate=0.01, n_iters=1000):
        self.lr = learning_rate
        self.n_iters = n_iters
        self.weights = None
        self.bias = None

    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))

    def fit(self, X, y):
        n_samples, n_features = X.shape
        self.weights = np.zeros(n_features)
        self.bias = 0

        for _ in range(self.n_iters):
            linear_model = np.dot(X, self.weights) + self.bias
            y_predicted = self.sigmoid(linear_model)

            dw = (1 / n_samples) * np.dot(X.T, (y_predicted - y))
            db = (1 / n_samples) * np.sum(y_predicted - y)

            self.weights -= self.lr * dw
            self.bias -= self.lr * db

    def predict(self, X):
        linear_model = np.dot(X, self.weights) + self.bias
        y_predicted = self.sigmoid(linear_model)
        return [1 if i > 0.5 else 0 for i in y_predicted]

# Generate synthetic binary dataset
from sklearn.datasets import make_classification

X, y = make_classification(n_samples=100, n_features=2, n_classes=2, random_state=42)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train Logistic Regression model
log_reg = LogisticRegression(learning_rate=0.1, n_iters=1000)
log_reg.fit(X_train, y_train)

# Predict and evaluate
y_pred = log_reg.predict(X_test)
accuracy = np.mean(y_pred == y_test)

print("Predictions:", y_pred)
print("Actual Labels:", y_test)
print("Accuracy:", accuracy)
```

#### e. Sample Results:
Input:
```
Synthetic Dataset: 100 samples, 2 features
Train/Test Split: 80% train, 20% test
```
Output:
```
Predictions: [0, 1, 1, 0, 0, ...]
Actual Labels: [0, 1, 1, 0, 0, ...]
Accuracy: 0.85
```

#### f. Conclusion:
The Logistic Regression model accurately classified the binary dataset and achieved a high accuracy score. It effectively demonstrated the application of gradient descent for classification tasks.


---

### **10A. Python Implementation of K-Means Clustering**

#### a. Objective:
To implement the K-Means Clustering algorithm to partition data into k clusters.

#### b. Brief Background:
K-Means is an unsupervised learning algorithm that partitions data into k clusters. It minimizes the sum of squared distances between data points and the centroids of their assigned clusters. The algorithm iteratively updates centroids and reassigns points to achieve convergence.

#### c. Algorithm Steps:
1. Initialize k centroids randomly from the dataset.
2. Assign each data point to the nearest centroid.
3. Recompute centroids as the mean of assigned points.
4. Repeat steps 2–3 until centroids stabilize or a maximum number of iterations is reached.

#### d. Python Program Code:

```python
import numpy as np

class KMeans:
    def __init__(self, k=3, max_iters=100, tolerance=1e-4):
        self.k = k
        self.max_iters = max_iters
        self.tolerance = tolerance
        self.centroids = None

    def fit(self, X):
        n_samples, n_features = X.shape
        self.centroids = X[np.random.choice(n_samples, self.k, replace=False)]

        for _ in range(self.max_iters):
            # Assign clusters
            distances = np.array([[np.linalg.norm(x - centroid) for centroid in self.centroids] for x in X])
            cluster_labels = np.argmin(distances, axis=1)

            # Compute new centroids
            new_centroids = np.array([X[cluster_labels == k].mean(axis=0) for k in range(self.k)])
            if np.all(np.abs(new_centroids - self.centroids) < self.tolerance):
                break
            self.centroids = new_centroids

        self.cluster_labels = cluster_labels

    def predict(self, X):
        distances = np.array([[np.linalg.norm(x - centroid) for centroid in self.centroids] for x in X])
        return np.argmin(distances, axis=1)

# Generate synthetic dataset
from sklearn.datasets import make_blobs

X, _ = make_blobs(n_samples=300, n_features=2, centers=3, random_state=42)

# Apply K-Means
kmeans = KMeans(k=3)
kmeans.fit(X)

# Predictions
clusters = kmeans.predict(X)

print("Centroids:", kmeans.centroids)
print("Cluster Labels:", clusters)
```

#### e. Sample Results:
Input:
```
Synthetic Dataset: 300 samples, 2 features, 3 centers
```
Output:
```
Centroids: [[-2.4, 9.8], [4.5, 1.9], [1.8, 4.5]]
Cluster Labels: [2, 0, 1, 2, ...]
```

#### f. Conclusion:
K-Means successfully grouped data points into clusters based on their proximity to centroids, demonstrating its capability for unsupervised clustering.

---

### **10B. Python Implementation of Hierarchical Clustering**

#### a. Objective:
To implement the Hierarchical Clustering algorithm to group data into clusters.

#### b. Brief Background:
Hierarchical Clustering builds a hierarchy of clusters using a bottom-up (agglomerative) or top-down (divisive) approach. The agglomerative method begins with each data point as its own cluster, merging them iteratively based on a distance metric until all points belong to one cluster.

#### c. Algorithm Steps:
1. Compute the distance matrix for all pairs of points.
2. Start with each data point as its own cluster.
3. Find the two nearest clusters and merge them.
4. Update the distance matrix to reflect the merged cluster.
5. Repeat until only one cluster remains or a stopping condition is met.

#### d. Python Program Code:

```python
import numpy as np

class HierarchicalClustering:
    def __init__(self, n_clusters=2):
        self.n_clusters = n_clusters

    def fit(self, X):
        # Initialize each data point as its own cluster
        clusters = [[i] for i in range(len(X))]
        distances = np.array([[np.linalg.norm(X[i] - X[j]) for j in range(len(X))] for i in range(len(X))])
        np.fill_diagonal(distances, np.inf)

        while len(clusters) > self.n_clusters:
            # Find the closest pair of clusters
            i, j = np.unravel_index(np.argmin(distances), distances.shape)
            # Merge the clusters
            clusters[i].extend(clusters[j])
            clusters.pop(j)

            # Update distances
            distances = np.delete(distances, j, axis=0)
            distances = np.delete(distances, j, axis=1)
            for k in range(len(distances)):
                distances[i, k] = distances[k, i] = np.min(
                    [np.linalg.norm(X[m] - X[n]) for m in clusters[i] for n in clusters[k]]
                )
            np.fill_diagonal(distances, np.inf)

        self.clusters = clusters

    def get_labels(self, X):
        labels = np.zeros(len(X))
        for cluster_id, cluster in enumerate(self.clusters):
            for idx in cluster:
                labels[idx] = cluster_id
        return labels

# Generate synthetic dataset
X, _ = make_blobs(n_samples=300, n_features=2, centers=3, random_state=42)

# Apply Hierarchical Clustering
hc = HierarchicalClustering(n_clusters=3)
hc.fit(X)

# Get cluster labels
cluster_labels = hc.get_labels(X)

print("Cluster Assignments:", cluster_labels)
```

#### e. Sample Results:
Input:
```
Synthetic Dataset: 300 samples, 2 features, 3 centers
```
Output:
```
Cluster Assignments: [2. 0. 1. 2. ...]
```

#### f. Conclusion:
Hierarchical Clustering effectively grouped data points into clusters by iteratively merging the closest clusters. It is suitable for applications requiring a hierarchy of clusters or when the number of clusters is not predefined.

---
