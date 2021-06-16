#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <iostream>
#include <thread>
#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <ros/subscribe_options.h>
#include <std_msgs/Float32.h>
#include "arm_gazebo/angles.h"  
#include "arm_lib/ik_positions.h"
#include "arm_lib/FK.h"
#include "arm_lib/IK.h"
using namespace std;

namespace gazebo
{
	class ModelPush : public ModelPlugin
	{
		std::string chassis_arm1_joint_name = "chassis_arm1_joint";
		std::string arm1_arm2_joint_name = "arm1_arm2_joint";
		std::string arm2_arm3_joint_name = "arm2_arm3_joint";
		std::string arm3_arm4_joint_name = "arm3_arm4_joint";
		std::string arm4_arm5_joint_name = "arm4_arm5_joint";
		std::string arm5_palm_joint_name = "arm5_palm_joint";
		std::string palm_leftfinger_joint_name = "palm_leftfinger_joint";
		std::string palm_rightfinger_joint_name = "palm_rightfinger_joint";
	    
		public:void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
		{
			// Store the pointer to the model
			this->model = _parent;

			// // intiantiate the joint controller
			this->jointController = this->model->GetJointController(); 
			// // set your PID values	

			std::string chassis_arm1_joint = this->model->GetJoint(chassis_arm1_joint_name)->GetScopedName();
			std::string arm1_arm2_joint = this->model->GetJoint(arm1_arm2_joint_name)->GetScopedName();
			std::string arm2_arm3_joint = this->model->GetJoint(arm2_arm3_joint_name)->GetScopedName();
			std::string arm3_arm4_joint = this->model->GetJoint(arm3_arm4_joint_name)->GetScopedName();
            std::string arm4_arm5_joint = this->model->GetJoint(arm4_arm5_joint_name)->GetScopedName();
			std::string arm5_palm_joint = this->model->GetJoint(arm5_palm_joint_name)->GetScopedName();
			std::string palm_leftfinger_joint = this->model->GetJoint(palm_leftfinger_joint_name)->GetScopedName();
			std::string palm_rightfinger_joint = this->model->GetJoint(palm_rightfinger_joint_name)->GetScopedName();

			this->jointController->SetPositionPID(chassis_arm1_joint_name, pid);
			this->jointController->SetPositionPID(arm1_arm2_joint_name, pid);
			this->jointController->SetPositionPID(arm2_arm3_joint_name, pid);
			this->jointController->SetPositionPID(arm3_arm4_joint_name, pid);
            this->jointController->SetPositionPID(arm4_arm5_joint, pid);
			this->jointController->SetPositionPID(arm5_palm_joint, pid);
			this->jointController->SetPositionPID(palm_leftfinger_joint, pid);
			this->jointController->SetPositionPID(palm_rightfinger_joint, pid);
			// Listen to the update event. This event is broadcast every
			// simulation iteration.
			this->updateConnection = event::Events::ConnectWorldUpdateBegin(
				std::bind(&ModelPush::OnUpdate, this));            
			// Initialize ros, if it has not already bee initialized.
			if (!ros::isInitialized()){
			int argc = 0;
			char **argv = NULL;
			ros::init(argc, argv, "gazebo_client",ros::init_options::NoSigintHandler);}
            int argc = 0;
			char **argv = NULL;
			ros::init(argc, argv, "ros_control");
			//rostopic pub /ik_position_pubarm_lib/ik_positions "x: value y:val x:val

			ikPoseSub = n.subscribe("/ik_position_pub", 1000, &ModelPush::IKGetAngles, this);
			ros::ServiceClient FKclient = this->rosNode->serviceClient<arm_lib::FK>("fk");
            ros::ServiceClient IKclient = this->rosNode->serviceClient<arm_lib::IK>("ik");
			// Create our ROS node. This acts in a similar manner to
			// the Gazebo node
			this->rosNode.reset(new ros::NodeHandle("gazebo_client"));
            
			// Create a named topic, and subscribe to it.
			ros::SubscribeOptions so =
			ros::SubscribeOptions::create<arm_gazebo::angles>(
				"/" + this->model->GetName() + "/vel_cmd",
				1,
				boost::bind(&ModelPush::OnRosMsg, this, _1),
				ros::VoidPtr(), &this->rosQueue);
			this->rosSub = this->rosNode->subscribe(so);

			// Spin up the queue helper thread.
			this->rosQueueThread =
			std::thread(std::bind(&ModelPush::QueueThread, this));
			ros::spinOnce();
	    }
		// Called by the world update start event
	    public:void OnUpdate(){
			float angleDegree = -90;
			float j1_rot_angle = 0;
			float j2_rot_angle = 0;
			float j3_rot_angle = 0;
			float j4_rot_angle = 0;
			float rad = M_PI * angleDegree / 180;

			double j1 = physics::JointState(this->model->GetJoint(chassis_arm1_joint_name)).Position(0);
			double j2 = physics::JointState(this->model->GetJoint(arm1_arm2_joint_name)).Position(0);
			double j3 = physics::JointState(this->model->GetJoint(arm2_arm3_joint_name)).Position(0);
			double j4 = physics::JointState(this->model->GetJoint(arm3_arm4_joint_name)).Position(0);			
            double j5 = physics::JointState(this->model->GetJoint(arm4_arm5_joint_name)).Position(0);
			double j6 = physics::JointState(this->model->GetJoint(arm5_palm_joint_name)).Position(0);	
			double j7 = physics::JointState(this->model->GetJoint(palm_leftfinger_joint_name)).Position(0);			
			double j8 = physics::JointState(this->model->GetJoint(palm_rightfinger_joint_name)).Position(0);
			Fk(j1, j2, j3, j4, j5, j6);
			ros::spinOnce();
			/***std::cout << "Enter rotation angle for joint one value";
  			std::cin >> j1_rot_angle; 
			cout << "Enter rotation angle for joint two value";
  			cin >> j2_rot_angle;
			cout << "Enter rotation angle for joint three value";
  			cin >> j3_rot_angle;
			cout << "Enter rotation angle for joint four value";
  			cin >> j4_rot_angle;***/

			// this->jointController->SetPositionPID(name, pid);
			// this->jointController->SetPositionTarget(name, rad);
			// this->jointController->Update();

			// Get joint position by index. 
			// 0 returns rotation accross X axis
			// 1 returns rotation accross Y axis
			// 2 returns rotation accross Z axis
			// If the Joint has only Z axis for rotation, 0 returns that value and 1 and 2 return nan
			// double a2 = this->model->GetJoint("chasis_arm1_joint").Position(0);
			// double a3 = physics::JointState(this->model->GetJoint("chasis_arm1_joint")).Position(2);
			/*std::cout << "Current chassis_arm1_joint_name values: " << j1 * 180.0 / M_PI << std::endl;
			std::cout << "Current arm1_arm2_joint values: " << j2 * 180.0 / M_PI << std::endl;
			std::cout << "Current arm2_arm3_joint values: " << j3 * 180.0 / M_PI << std::endl;
			std::cout << "Current rm3_arm4_joint values: " << j4 * 180.0 / M_PI << std::endl;
		    */
		}
		void Fk(double j1, double j2, double j3, double j4, double j5, double j6)
		{
			arm_lib::FK fksrv;
			//Link length is from the model.sdf
			fksrv.request.link_lengths = {0.05, 2, 1, 0.5, 0.05, 0.04};
			fksrv.request.joint_positions = {j1, j2, j3, j4, j5, j6};
			if (FKClient.call(fksrv))
			{
				ROS_INFO("Result: [%f, %f, %f]", fksrv.response.actuator_pose[0], fksrv.response.actuator_pose[1], fksrv.response.actuator_pose[2]);
			}
			else
			{
				ROS_ERROR("No FK service ");
			}
		}
        void IKGetAngles(const arm_lib::ik_positions &msg)
		{
			ROS_INFO("Controller got x: %f, y: %f, z: %f", msg.x,msg.y,msg.z);
			arm_lib::IK iksrv;
			iksrv.request.link_lengths = {0.15, 2, 1, 0.5, 0.05, 0.04};
			iksrv.request.joint_positions = {0, 0, 0, 0, 0, 0};
			iksrv.request.actuator_pose = {msg.x, msg.y, msg.z};            
            iksrv.request.joint_positions[0] = physics::JointState(this->model->GetJoint(arm1_arm2_joint_name)).Position(0);
			iksrv.request.joint_positions[1] = physics::JointState(this->model->GetJoint(arm2_arm3_joint_name)).Position(0);
			iksrv.request.joint_positions[2] = physics::JointState(this->model->GetJoint(arm3_arm4_joint_name)).Position(0);
			iksrv.request.joint_positions[3] = physics::JointState(this->model->GetJoint(arm4_arm5_joint_name)).Position(0); 
			 
			if (IKClient.call(iksrv))
			{	              
				jointController->SetPositionTarget(arm1_arm2_joint_name, iksrv.response.result_pose[0]);
			    jointController->SetPositionTarget(arm2_arm3_joint_name, iksrv.response.result_pose[1]);
			    jointController->SetPositionTarget(arm3_arm4_joint_name, iksrv.response.result_pose[2]);
			    jointController->SetPositionTarget(arm4_arm5_joint_name, iksrv.response.result_pose[3]);
			}
			else
			{
				ROS_ERROR("No IK service ");
			}
		}
		public: void SetVelocity(const double &_vel){
				// Set the joint's target velocity.
				 std::string name = this->model->GetJoint("arm2_arm3_joint")->GetScopedName();
				this->jointController->SetVelocityTarget(name, 10.0);
				
		}
		public: void SetAngle(const arm_gazebo::angles::ConstPtr& msg){
					std::cout << "Message Recieved"<<std::endl;
					ROS_INFO("I heard: [%.2f]", msg->chassis_arm1_joint);

			
					std::string chassis_arm1_joint = this->model->GetJoint(chassis_arm1_joint_name)->GetScopedName();
					std::string arm1_arm2_joint = this->model->GetJoint(arm1_arm2_joint_name)->GetScopedName();
					std::string arm2_arm3_joint = this->model->GetJoint(arm2_arm3_joint_name)->GetScopedName();
					std::string arm3_arm4_joint = this->model->GetJoint(arm3_arm4_joint_name)->GetScopedName();

					this->jointController->SetPositionTarget(chassis_arm1_joint,  msg->chassis_arm1_joint);
					this->jointController->SetPositionTarget(arm1_arm2_joint,  msg->arm1_arm2_joint);
					this->jointController->SetPositionTarget(arm2_arm3_joint,  msg->arm2_arm3_joint);
					this->jointController->SetPositionTarget(arm3_arm4_joint,  msg->arm3_arm4_joint);

		}
		public: void OnRosMsg(const arm_gazebo::angles::ConstPtr& msg){
				this->SetAngle(msg);
		}
        /// \brief ROS helper function that processes messages
		private: void QueueThread(){
			static const double timeout = 0.01;
		    while (this->rosNode->ok())	{
				this->rosQueue.callAvailable(ros::WallDuration(timeout));
			}
        }
		

		// a pointer that points to a model object
	private:
		physics::ModelPtr model;

		// 	// A joint controller object
		// 	// Takes PID value and apply angular velocity
		// 	//  or sets position of the angles
	private:
		physics::JointControllerPtr jointController;

	private:
		event::ConnectionPtr updateConnection;

		// // 	// PID object
	private:
		common::PID pid;
	/// \brief A node use for ROS transport
	private: std::unique_ptr<ros::NodeHandle> rosNode;

	/// \brief A ROS subscriber
	private: ros::Subscriber rosSub;

	/// \brief A ROS callbackqueue that helps process messages
	private: ros::CallbackQueue rosQueue;

	/// \brief A thread the keeps running the rosQueue
	private: std::thread rosQueueThread;
    private:

		ros::NodeHandle n;

		ros::Subscriber ikPoseSub;

		ros::ServiceClient FKClient;

		ros::ServiceClient IKClient;

	};

	// Register this plugin with the simulator
	GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}

