;; Auto-generated. Do not edit!


(when (boundp 'plumbing_server_client::addint)
  (if (not (find-package "PLUMBING_SERVER_CLIENT"))
    (make-package "PLUMBING_SERVER_CLIENT"))
  (shadow 'addint (find-package "PLUMBING_SERVER_CLIENT")))
(unless (find-package "PLUMBING_SERVER_CLIENT::ADDINT")
  (make-package "PLUMBING_SERVER_CLIENT::ADDINT"))
(unless (find-package "PLUMBING_SERVER_CLIENT::ADDINTREQUEST")
  (make-package "PLUMBING_SERVER_CLIENT::ADDINTREQUEST"))
(unless (find-package "PLUMBING_SERVER_CLIENT::ADDINTRESPONSE")
  (make-package "PLUMBING_SERVER_CLIENT::ADDINTRESPONSE"))

(in-package "ROS")





(defclass plumbing_server_client::addintRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod plumbing_server_client::addintRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass plumbing_server_client::addintResponse
  :super ros::object
  :slots (_sum ))

(defmethod plumbing_server_client::addintResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass plumbing_server_client::addint
  :super ros::object
  :slots ())

(setf (get plumbing_server_client::addint :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plumbing_server_client::addint :datatype-) "plumbing_server_client/addint")
(setf (get plumbing_server_client::addint :request) plumbing_server_client::addintRequest)
(setf (get plumbing_server_client::addint :response) plumbing_server_client::addintResponse)

(defmethod plumbing_server_client::addintRequest
  (:response () (instance plumbing_server_client::addintResponse :init)))

(setf (get plumbing_server_client::addintRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plumbing_server_client::addintRequest :datatype-) "plumbing_server_client/addintRequest")
(setf (get plumbing_server_client::addintRequest :definition-)
      "int32 num1
int32 num2

---

int32 sum
")

(setf (get plumbing_server_client::addintResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get plumbing_server_client::addintResponse :datatype-) "plumbing_server_client/addintResponse")
(setf (get plumbing_server_client::addintResponse :definition-)
      "int32 num1
int32 num2

---

int32 sum
")



(provide :plumbing_server_client/addint "4781436a0c2affec8025955a6041e481")


