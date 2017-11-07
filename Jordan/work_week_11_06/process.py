import numpy as np
from scipy import signal
import matplotlib.pyplot as plt
from pykalman import KalmanFilter

csv = np.genfromtxt ('dataSquare.csv', delimiter=",")

second = csv[:,0]
print(second)
third = csv[:,1]
print(third)

plt.subplot(2, 1, 1)
plt.plot(second,third)

kf = KalmanFilter(initial_state_mean=0, n_dim_obs=2)

plt.subplot(2, 1, 2)
plt.plot(signal.fftconvolve(second,third))

plt.show()
