#!/usr/bin/env python
import rospy
import numpy as np
import math

def x_rotation(theta, vector):
    Rx = np.array([[1, 0, 0, 0], [0, np.cos(theta), -np.sin(theta), 0], [0, np.sin(theta),np.cos(theta), 0], [ 0,  0,  0,   1]])
    return Rx @ vector

def z_rotation(theta, vector):
    Rz = np.array([[np.cos(theta), -np.sin(theta), 0, 0], [np.sin(theta), np.cos(theta), 0, 0], [0, 0,1 , 0],[0, 0, 0, 1]])
    return np.dot(Rz, vector)