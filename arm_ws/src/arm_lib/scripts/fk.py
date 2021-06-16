import rospy
from std_msgs.msg import String 
from math import cos, sin, radians
import numpy as np
import math
from arm_lib.srv import Fk,FkResponse
def roty(o):
    return np.array([[np.cos(o) ,0, np.sin(o),0],
                     [ 0        ,1   ,0     ,0],
                     [-np.sin(o),0, np.cos(o),0],
                     [0         ,0, 0        ,1]])

def rotx(o):
    return np.array([[1,     0    ,     0     ,0],
                     [0, np.cos(o), -np.sin(o),0],
                     [0, np.sin(o), np.cos(o) ,0],
                     [0,    0     ,     0     ,1]])

def rotz(o):
    return np.array([
                              [np.cos(o), -np.sin(o),0, 0],
                              [np.sin(o),np.cos(o) , 0, 0],
                              [0         ,0       , 1,  0],
                              [0         ,0       , 0, 1]])
def transz(b):
    return np.array([[1,0,0,0],
                    [0,1,0,0],
                    [0,0,1,b],
                    [0,0,0,1]])
def transx(b):
    return np.array([[1,0,0,b],
                    [0,1,0,0],
                    [0,0,1,0],
                    [0,0,0,1]])
def transy(b):
    return np.array([[1,0,0,0],
                    [0,1,0,b],
                    [0,0,1,0],
                    [0,0,0,1]])                   
def handle_fk(fksrvin):
    m1=transz(0,0,0.1)
    m2=rotz(fksrvin.joint_positions[0]).dot(transz(fksrvin.link_lengths[0]))
    m3= rotx(fksrvin.joint_positions[1]).dot(transz(fksrvin.link_lengths[1]))
    m4=rotx(fksrvin.joint_positions[2]).dot(transz(fksrvin.link_lengths[2]))
    m5= rotx(fksrvin.joint_positions[3]).dot(transz(fksrvin.link_lengths[3]))
    m6= rotz(fksrvin.joint_positions[4]).dot(transz(fksrvin.link_lengths[4]))
    m7=roty(refksrvinq.joint_positions[5]).dot(transz(fksrvin.link_lengths[5]))
    m=m1
    mats=[m2,m3,m4,m5,m6,m7]
    for i in range(len(mats)):
        m=m.dot(mats[i])
    x=m[0,3]
    y=m[1,3]
    z=m[2,3]
    return FkResponse([x,y,z])

def fk_server():
    rospy.init_node('fk_server')
    s=rospy.Service('fk',FK,handle_fk)
    print("Ready to Fk")
    ros.spin()

if __name__ == '__main__':
    fk_server()
