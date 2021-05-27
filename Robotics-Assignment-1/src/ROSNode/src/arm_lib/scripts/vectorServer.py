#!/usr/bin/env python
from __future__ import print_function
from os import read

from numpy.core.fromnumeric import alen
    
from arm_lib.srv import rotateAndTranslate,rotateAndTranslateResponse
import rospy    
import numpy as np

def rotate_translate(rotation_matrix, vector):
    return np.matmul(rotation_matrix, vector)

def handle_rotation_translation(req):
    alpha, beta, gamma = np.deg2rad(req.d), np.deg2rad(req.e), np.deg2rad(req.f)
    rotation_x = np.array([[1, 0, 0], 
                            [0, np.cos(alpha), -np.sin(alpha)], 
                            [0, np.sin(alpha), np.cos(alpha)]], dtype='float32')

    rotation_y = np.array([[np.cos(beta), 0, np.sin(beta)], 
                            [0, 1, 0],
                            [-np.sin(beta), 0, np.cos(beta)]], dtype='float32')
    
    rotation_z = np.array([[np.cos(gamma), -np.sin(gamma), 0], 
                            [np.sin(gamma), np.cos(gamma), 0], 
                            [0, 0, 1]], dtype='float32')

    vector = np.array([[req.a], 
                       [req.b],
                       [req.c]], dtype='float32')
    #translation distance                   
    d = req.g
    
    #rotation in x-axis
    x = rotate_translate(rotation_x, vector)
     #rotatin in y-axis
    y = rotate_translate(rotation_y, x)
    #rotatin in z-axis
    z = rotate_translate(rotation_z, y)
    #translation by z
    z = z + d
    


    
    return rotateAndTranslateResponse(z[0],z[1],z[2])
    
def rotation_translation_server():

    rospy.init_node('rotation_translation_server')#initializes ros node with the given name

    s = rospy.Service('rotation_translation',rotateAndTranslate,handle_rotation_translation)
    #rospy service declares a new service named rotation_translation with rotateAndTranslate
     # service type. All requests are passed to  hanlde_rotation_translation function.
    print("Ready to rotate and translate")
    rospy.spin() #used to prevent the main thread from exiting
if __name__=="__main__":
    rotation_translation_server()
