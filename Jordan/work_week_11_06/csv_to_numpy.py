import numpy as np
import matplotlib.pyplot as plt


csv = np.genfromtxt ('data.csv', delimiter=",")

second = csv[:,0]
print(second)
third = csv[:,1]
print(third)

plt.plot(second,third)

plt.show()

