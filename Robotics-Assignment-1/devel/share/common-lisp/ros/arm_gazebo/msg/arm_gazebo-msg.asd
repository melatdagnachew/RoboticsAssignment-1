
(cl:in-package :asdf)

(defsystem "arm_gazebo-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "angles" :depends-on ("_package_angles"))
    (:file "_package_angles" :depends-on ("_package"))
  ))