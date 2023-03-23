import matplotlib.pyplot as plt

config = open('C:/collatz/code/config.txt', 'r')

arr = []
i = 0

name = config.readline()
name = name.replace("\n", "")

file = open(f'C:/collatz/data/output/{name}.txt', 'r')

string = file.readline()
string = eval(string)
lists = sorted(string.items())

x, y = zip(*lists)
plt.plot(x, y)
plt.savefig(f"C:/collatz/data/result/{name}.png")
plt.show()