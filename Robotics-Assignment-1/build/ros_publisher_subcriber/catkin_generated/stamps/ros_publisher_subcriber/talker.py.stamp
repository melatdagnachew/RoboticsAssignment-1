import rospy
from std_msgs.msg import String
from ros_publisher_subcriber.msg import Input
from ros_publisher_subcriber.msg import Output
from math import cos, sin, radians
import numpy as np
import math

def trig(angle):
  r = radians(angle)
  return cos(r), sin(r)

def rotate(rotation):
    xC, xS = trig(rotation[0])
    yC, yS = trig(rotation[1])
    zC, zS = trig(rotation[2])
    Rotate_X_matrix = np.array([[ 0, 0, 0],
                              [xC, -xS, 0],
                              [xS, xC, 0]])
    Rotate_Y_matrix = np.array([[yC, 0, yS],
                                [0, 1, 0 ],
                                [-yS, 0, yC]
                            ])
    Rotate_Z_matrix = np.array([[zC, -zS, 0],
                                [zS, zC, 0],
                                [0, 0, 1]
                                ])
    return np.dot(Rotate_Z_matrix,np.dot(Rotate_Y_matrix, Rotate_X_matrix))

def translation(translation_vector, v):
  dX = translation_vector[0]
  dY = translation_vector[1]
  dZ = translation_vector[2]
  Translate_matrix = np.array([[dX],
                               [dY],
                               [dZ],
                               ])
  return np.dot(Translate_matrix,v)

def talker():

    pub = rospy.Publisher('chatter', Output, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    output_vector = Output()
    input_vector = Input()

    print("Rotate and Translate a vector")

    input_vector.vector.linear.x = float(input("Input x (position):"))
    input_vector.vector.linear.y = float(input("Input y (position):"))
    input_vector.vector.linear.z = float(input("Input z (position):"))

    input_vector.vector.angular.x = float(input("Input teta (x-axis rotation):"))
    input_vector.vector.angular.y = float(input("Input teta (y-axis rotation):"))
    input_vector.vector.angular.z = float(input("Input teta (z-axis rotation):"))
  
    
    v = [input_vector.vector.linear.x, input_vector.vector.linear.y, input_vector.vector.linear.z]
    angles = [input_vector.vector.angular.x,input_vector.vector.angular.y,input_vector.vector.angular.z]
    
    r = rotate(angles)
    result = translation(r,v)

    output_vector.vector.x = result[0]
    output_vector.vector.y = result[1]
    output_vector.vector.z = result[2]

    while not rospy.is_shutdown():
        rospy.loginfo(output_vector)
        pub.publish(output_vector)
        rate.sleep()
        talker()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
