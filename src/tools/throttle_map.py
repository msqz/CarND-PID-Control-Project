#!/usr/bin/env python3

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import numpy as np
from math import sqrt

SPEED_MAX = 100.0

space_speed = np.linspace(0.0, SPEED_MAX, 1000)
space_steer = np.linspace(0.0, 1.0, 1000)
speed, steer = np.meshgrid(space_speed, space_steer)

# throttle [0.0, 1.0]
steer_norm = steer / 1.0
speed_norm = speed / SPEED_MAX

throttle = (-((steer_norm * speed_norm)**(1/2)) + 1.0) ** 5

fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_surface(speed, steer, throttle, cmap=cm.coolwarm)
ax.set_xlabel('speed')
ax.set_ylabel('steer')
ax.set_zlabel('throttle')
plt.show()