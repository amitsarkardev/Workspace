def check_even_odd(n):
    if n % 2 == 0:
        return "Even"
    else:
        return "Odd"

print("--- Program 1 ---")
try:
    num1 = int(input("Enter an integer to check if it's even or odd: "))
    print(f"The number {num1} is {check_even_odd(num1)}.")
except ValueError:
    print("Invalid input! Please enter an integer.")
print("\n")
