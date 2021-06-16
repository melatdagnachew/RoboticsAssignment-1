import rospy
from std_msgs.msg import String 
from math import cos, sin, radians
import numpy as np
import math
import tinyik as ik
from arm_lib.srv import Ik,IkResponse
def handle_ik(iksrvin):
    #link length
    arm=ik.Actuator([
        "z", [0, 0, 0.15],
        "x", [0, 0, 2.0],
        "x", [0, 0, 1.0],
        "x", [0, 0, .5],
        "z", [0, 0, 0.02],
        "x", [0, 0, 0.02]
    ])
    arm.angles=iksrvin.joint_positions
    arm.ee=iksrvin.actuator_pose
    return IkResponse(arm.angles)

def ik_server():
    rospy.init_node('ik_server')
    s=rospy.Service('ik',Ik,handle_ik)
    print("Ready to Ik")
    ros.spin()

if __name__ == '__main__':
    ik_server()
