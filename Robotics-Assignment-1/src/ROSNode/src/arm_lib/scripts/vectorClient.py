#!/usr/bin/env python
from __future__ import print_function
from arm_lib.srv import *

import numpy as np
import sys
import rospy




def rotate_translate_client(a,b,c,d,e,f,g):
    rospy.wait_for_service('rotation_translation') # Wait until a service becomes available

    try:
        rotate_translate= rospy.ServiceProxy('rotation_translation', rotateAndTranslate)
        #service defintions are a container for the request and respone type. 1 2 3
        resp1 = rotate_translate(a,b,c,d,e,f,g)

        rotated = np.round(np.array([resp1.h, resp1.i, resp1.j],dtype='float32'),2)
        
        print("after rotation and translation")
        print(rotated)
    

    except rospy.ServiceException as e:
           print("Service call failed: %s"%e)
   
if __name__ == "__main__":
       if len(sys.argv) == 8:
           #vector inputs
           a, b, c= int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])
           #angle inputs
           d, e, f = int(sys.argv[4]), int(sys.argv[5]), int(sys.argv[6])
           #translation d input
           g = int(sys.argv[7])
       else:
           sys.exit(1)
       rotate_translate_client(a, b, c, d, e, f, g)
