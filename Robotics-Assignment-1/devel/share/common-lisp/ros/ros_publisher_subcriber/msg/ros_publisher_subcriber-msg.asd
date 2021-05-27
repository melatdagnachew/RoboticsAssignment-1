
(cl:in-package :asdf)

(defsystem "ros_publisher_subcriber-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Input" :depends-on ("_package_Input"))
    (:file "_package_Input" :depends-on ("_package"))
    (:file "Num" :depends-on ("_package_Num"))
    (:file "_package_Num" :depends-on ("_package"))
    (:file "Output" :depends-on ("_package_Output"))
    (:file "_package_Output" :depends-on ("_package"))
  ))