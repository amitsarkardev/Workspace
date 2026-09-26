def find_largest(a,b,c):
    if a >= b and a >= c:
        return a
    elif b >= a and b >= c:
        return b
    else:
        return c

print("--- Program to check largest number---")
try:
    a = float(input("Enter first number: "))
    b = float(input("Enter second number: "))
    c = float(input("Enter third number: "))
    print("The largest number is:", find_largest(a,b,c))
except ValueError:
    print("Invalid input! Please enter numeric values.")
print("\n")