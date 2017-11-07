import numpy as np
import matplotlib.pyplot as plt


csv = np.genfromtxt ('z_up_data.csv', delimiter=",")

second = csv[:,0]
print(second)
third = csv[:,3]
print(third)

plt.plot(second,third)

plt.show()

