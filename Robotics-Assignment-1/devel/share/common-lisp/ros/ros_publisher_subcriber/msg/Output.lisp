; Auto-generated. Do not edit!


(cl:in-package ros_publisher_subcriber-msg)


;//! \htmlinclude Output.msg.html

(cl:defclass <Output> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (distance
    :reader distance
    :initarg :distance
    :type cl:integer
    :initform 0)
   (vector
    :reader vector
    :initarg :vector
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass Output (<Output>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Output>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Output)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_publisher_subcriber-msg:<Output> is deprecated: use ros_publisher_subcriber-msg:Output instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Output>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_publisher_subcriber-msg:header-val is deprecated.  Use ros_publisher_subcriber-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <Output>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_publisher_subcriber-msg:distance-val is deprecated.  Use ros_publisher_subcriber-msg:distance instead.")
  (distance m))

(cl:ensure-generic-function 'vector-val :lambda-list '(m))
(cl:defmethod vector-val ((m <Output>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_publisher_subcriber-msg:vector-val is deprecated.  Use ros_publisher_subcriber-msg:vector instead.")
  (vector m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Output>) ostream)
  "Serializes a message object of type '<Output>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'distance)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vector) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Output>) istream)
  "Deserializes a message object of type '<Output>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'distance) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vector) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Output>)))
  "Returns string type for a message object of type '<Output>"
  "ros_publisher_subcriber/Output")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Output)))
  "Returns string type for a message object of type 'Output"
  "ros_publisher_subcriber/Output")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Output>)))
  "Returns md5sum for a message object of type '<Output>"
  "06fe441e0807b40f7f8bcc63548acb17")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Output)))
  "Returns md5sum for a message object of type 'Output"
  "06fe441e0807b40f7f8bcc63548acb17")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Output>)))
  "Returns full string definition for message of type '<Output>"
  (cl:format cl:nil "Header header~%int64 distance~%geometry_msgs/Point vector~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Output)))
  "Returns full string definition for message of type 'Output"
  (cl:format cl:nil "Header header~%int64 distance~%geometry_msgs/Point vector~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Output>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vector))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Output>))
  "Converts a ROS message object to a list"
  (cl:list 'Output
    (cl:cons ':header (header msg))
    (cl:cons ':distance (distance msg))
    (cl:cons ':vector (vector msg))
))
