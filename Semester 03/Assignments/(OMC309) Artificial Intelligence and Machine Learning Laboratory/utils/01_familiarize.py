def familiarize():
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
