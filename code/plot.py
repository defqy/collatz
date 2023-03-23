import matplotlib.pyplot as plt
import numpy as np
import numpy
import time

start_time = time.time()
n = 2

config = open('C:/collatz/code/config.txt', 'r')

name = config.readline()
name = name.replace("\n","")

z = config.readline()[0:]
z = int(z)

config.close()

name = str(name)
line_main = []

with open(f'C:/collatz/data/input/{name}.txt', 'r+') as f: # input
    
    for line in f:
        
        print(n / z * 100 // 1, "%", end = '\r')

        string = line

        line_2 = string.split(";")

        line = []

        for i in range(len(line_2)):
            j = int(line_2[i])
            line.append(j)

        line_main = line_main + line

        line = []

        n = n + 1

arr = np.array(line_main)
unique, counts = numpy.unique(arr, return_counts = True)
counts = dict(zip(unique, counts))

file = open(f'C:/collatz/data/output/{name}.txt', 'w') # output
file.write(str(counts))
file.close()

plt.plot(*zip(*sorted(counts.items())))
print("plot - %ss" % round(time.time() - start_time, 4))
plt.savefig(f"C:/collatz/data/result/{name}.png")
plt.show()