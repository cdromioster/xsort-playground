import random

# Open the output file for writing
with open("unsorted_random_20000.txt", "w") as file:
    
    # Generate 256 random values and write them to the file
    for i in range(20000):
        value = random.randint(0, 50000)
        file.write(str(value) + "\n")
