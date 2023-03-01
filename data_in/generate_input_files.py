import random

with open("random_10.txt", "w") as file:
    
    for i in range(10):
        value = random.randint(0, 50000)
        file.write(str(value) + "\n")

with open("random_256.txt", "w") as file:
    
    for i in range(256):
        value = random.randint(0, 50000)
        file.write(str(value) + "\n")

with open("random_1000.txt", "w") as file:
    
    for i in range(1000):
        value = random.randint(0, 50000)
        file.write(str(value) + "\n")

with open("random_10000.txt", "w") as file:
    
    for i in range(10000):
        value = random.randint(0, 50000)
        file.write(str(value) + "\n")

with open("random_20000.txt", "w") as file:
    
    for i in range(20000):
        value = random.randint(0, 50000)
        file.write(str(value) + "\n")

with open("random_50000.txt", "w") as file:
    
    for i in range(50000):
        value = random.randint(0, 50000)
        file.write(str(value) + "\n")

with open("few_unique_50000.txt", "w") as file:
    
    allowedValues = [36854, 33592, 9692, 30012, 20468, 27606, 33582, 33745, 33239, 30744]
    for i in range(50000):
        value = random.choice(allowedValues)
        file.write(str(value) + "\n")
