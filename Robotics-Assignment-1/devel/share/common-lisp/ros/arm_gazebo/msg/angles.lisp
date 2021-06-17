; Auto-generated. Do not edit!


(cl:in-package arm_gazebo-msg)


;//! \htmlinclude angles.msg.html

(cl:defclass <angles> (roslisp-msg-protocol:ros-message)
  ((chassis_arm1_joint
    :reader chassis_arm1_joint
    :initarg :chassis_arm1_joint
    :type cl:float
    :initform 0.0)
   (arm1_arm2_joint
    :reader arm1_arm2_joint
    :initarg :arm1_arm2_joint
    :type cl:float
    :initform 0.0)
   (arm2_arm3_joint
    :reader arm2_arm3_joint
    :initarg :arm2_arm3_joint
    :type cl:float
    :initform 0.0)
   (arm3_arm4_joint
    :reader arm3_arm4_joint
    :initarg :arm3_arm4_joint
    :type cl:float
    :initform 0.0))
)

(cl:defclass angles (<angles>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <angles>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'angles)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name arm_gazebo-msg:<angles> is deprecated: use arm_gazebo-msg:angles instead.")))

(cl:ensure-generic-function 'chassis_arm1_joint-val :lambda-list '(m))
(cl:defmethod chassis_arm1_joint-val ((m <angles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm_gazebo-msg:chassis_arm1_joint-val is deprecated.  Use arm_gazebo-msg:chassis_arm1_joint instead.")
  (chassis_arm1_joint m))

(cl:ensure-generic-function 'arm1_arm2_joint-val :lambda-list '(m))
(cl:defmethod arm1_arm2_joint-val ((m <angles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm_gazebo-msg:arm1_arm2_joint-val is deprecated.  Use arm_gazebo-msg:arm1_arm2_joint instead.")
  (arm1_arm2_joint m))

(cl:ensure-generic-function 'arm2_arm3_joint-val :lambda-list '(m))
(cl:defmethod arm2_arm3_joint-val ((m <angles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm_gazebo-msg:arm2_arm3_joint-val is deprecated.  Use arm_gazebo-msg:arm2_arm3_joint instead.")
  (arm2_arm3_joint m))

(cl:ensure-generic-function 'arm3_arm4_joint-val :lambda-list '(m))
(cl:defmethod arm3_arm4_joint-val ((m <angles>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm_gazebo-msg:arm3_arm4_joint-val is deprecated.  Use arm_gazebo-msg:arm3_arm4_joint instead.")
  (arm3_arm4_joint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <angles>) ostream)
  "Serializes a message object of type '<angles>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'chassis_arm1_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'arm1_arm2_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'arm2_arm3_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'arm3_arm4_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <angles>) istream)
  "Deserializes a message object of type '<angles>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'chassis_arm1_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'arm1_arm2_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'arm2_arm3_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'arm3_arm4_joint) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<angles>)))
  "Returns string type for a message object of type '<angles>"
  "arm_gazebo/angles")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'angles)))
  "Returns string type for a message object of type 'angles"
  "arm_gazebo/angles")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<angles>)))
  "Returns md5sum for a message object of type '<angles>"
  "1806b3e2a144e1ddd7c5a2029efd77fc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'angles)))
  "Returns md5sum for a message object of type 'angles"
  "1806b3e2a144e1ddd7c5a2029efd77fc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<angles>)))
  "Returns full string definition for message of type '<angles>"
  (cl:format cl:nil "float32 chassis_arm1_joint~%float32 arm1_arm2_joint~%float32 arm2_arm3_joint ~%float32 arm3_arm4_joint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'angles)))
  "Returns full string definition for message of type 'angles"
  (cl:format cl:nil "float32 chassis_arm1_joint~%float32 arm1_arm2_joint~%float32 arm2_arm3_joint ~%float32 arm3_arm4_joint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <angles>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <angles>))
  "Converts a ROS message object to a list"
  (cl:list 'angles
    (cl:cons ':chassis_arm1_joint (chassis_arm1_joint msg))
    (cl:cons ':arm1_arm2_joint (arm1_arm2_joint msg))
    (cl:cons ':arm2_arm3_joint (arm2_arm3_joint msg))
    (cl:cons ':arm3_arm4_joint (arm3_arm4_joint msg))
))
