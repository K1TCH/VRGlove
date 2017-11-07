import numpy as np
import matplotlib.pyplot as plt
from pykalman import KalmanFilter
from scipy import signal

# csv = np.genfromtxt ('dataSquare.csv', delimiter=",")

# second = csv[:,0]
# print(second)
# third = csv[:,1]
# print(third)

second = np.linspace(0,2*3.14) 
third = np.sin(second) 

plt.subplot(2, 1, 1)
plt.plot(second,third)

kf = KalmanFilter(initial_state_mean=0, n_dim_obs=2)

plt.subplot(2, 1, 2)
# signal.stft(third)
# signal.stft(second)
# yf = signal.stft(third)
# plt.plot(signal.stft(second),)
# signal.convolve(second,np.exp( (-2*3.14j)  / 50) )
# plt.plot(, signal.stft(third))
y = signal.convolve(third, third[::-1], mode="same")
plt.plot(np.arange(-len(third)/2,len(third)/2), y) 
# plt.plot(np.linspace(0, 10000,1), y) 
# print(signal.convolve(second,third,method='direct'))
# plt.plot(signal.convolve(second,third,mode='same',method='direct'))
# plt.plot(signal.fftconvolve(second,third))

plt.show()
