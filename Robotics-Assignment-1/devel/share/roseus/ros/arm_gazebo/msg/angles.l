;; Auto-generated. Do not edit!


(when (boundp 'arm_gazebo::angles)
  (if (not (find-package "ARM_GAZEBO"))
    (make-package "ARM_GAZEBO"))
  (shadow 'angles (find-package "ARM_GAZEBO")))
(unless (find-package "ARM_GAZEBO::ANGLES")
  (make-package "ARM_GAZEBO::ANGLES"))

(in-package "ROS")
;;//! \htmlinclude angles.msg.html


(defclass arm_gazebo::angles
  :super ros::object
  :slots (_chassis_arm1_joint _arm1_arm2_joint _arm2_arm3_joint _arm3_arm4_joint ))

(defmethod arm_gazebo::angles
  (:init
   (&key
    ((:chassis_arm1_joint __chassis_arm1_joint) 0.0)
    ((:arm1_arm2_joint __arm1_arm2_joint) 0.0)
    ((:arm2_arm3_joint __arm2_arm3_joint) 0.0)
    ((:arm3_arm4_joint __arm3_arm4_joint) 0.0)
    )
   (send-super :init)
   (setq _chassis_arm1_joint (float __chassis_arm1_joint))
   (setq _arm1_arm2_joint (float __arm1_arm2_joint))
   (setq _arm2_arm3_joint (float __arm2_arm3_joint))
   (setq _arm3_arm4_joint (float __arm3_arm4_joint))
   self)
  (:chassis_arm1_joint
   (&optional __chassis_arm1_joint)
   (if __chassis_arm1_joint (setq _chassis_arm1_joint __chassis_arm1_joint)) _chassis_arm1_joint)
  (:arm1_arm2_joint
   (&optional __arm1_arm2_joint)
   (if __arm1_arm2_joint (setq _arm1_arm2_joint __arm1_arm2_joint)) _arm1_arm2_joint)
  (:arm2_arm3_joint
   (&optional __arm2_arm3_joint)
   (if __arm2_arm3_joint (setq _arm2_arm3_joint __arm2_arm3_joint)) _arm2_arm3_joint)
  (:arm3_arm4_joint
   (&optional __arm3_arm4_joint)
   (if __arm3_arm4_joint (setq _arm3_arm4_joint __arm3_arm4_joint)) _arm3_arm4_joint)
  (:serialization-length
   ()
   (+
    ;; float32 _chassis_arm1_joint
    4
    ;; float32 _arm1_arm2_joint
    4
    ;; float32 _arm2_arm3_joint
    4
    ;; float32 _arm3_arm4_joint
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _chassis_arm1_joint
       (sys::poke _chassis_arm1_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arm1_arm2_joint
       (sys::poke _arm1_arm2_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arm2_arm3_joint
       (sys::poke _arm2_arm3_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _arm3_arm4_joint
       (sys::poke _arm3_arm4_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _chassis_arm1_joint
     (setq _chassis_arm1_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arm1_arm2_joint
     (setq _arm1_arm2_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arm2_arm3_joint
     (setq _arm2_arm3_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _arm3_arm4_joint
     (setq _arm3_arm4_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get arm_gazebo::angles :md5sum-) "1806b3e2a144e1ddd7c5a2029efd77fc")
(setf (get arm_gazebo::angles :datatype-) "arm_gazebo/angles")
(setf (get arm_gazebo::angles :definition-)
      "float32 chassis_arm1_joint
float32 arm1_arm2_joint
float32 arm2_arm3_joint 
float32 arm3_arm4_joint

")



(provide :arm_gazebo/angles "1806b3e2a144e1ddd7c5a2029efd77fc")


