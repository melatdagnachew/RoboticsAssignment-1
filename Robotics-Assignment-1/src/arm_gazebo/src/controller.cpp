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
using namespace std;

namespace gazebo
{
	class ModelPush : public ModelPlugin
	{
		std::string chassis_arm1_joint_name = "chassis_arm1_joint";
		std::string arm1_arm2_joint_name = "arm1_arm2_joint";
		std::string  arm2_arm3_joint_name = "arm2_arm3_joint";
		std::string arm3_arm4_joint_name = "arm3_arm4_joint";
	public:
		void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
		{
			// Store the pointer to the model
			this->model = _parent;

			// // intiantiate the joint controller
			this->jointController = this->model->GetJointController();

			// // set your PID values
			this->pid = common::PID(30.1, 10.01, 10.03);           
			

			std::string chassis_arm1_joint = this->model->GetJoint(chassis_arm1_joint_name)->GetScopedName();
			std::string arm1_arm2_joint = this->model->GetJoint(arm1_arm2_joint_name)->GetScopedName();
			std::string arm2_arm3_joint = this->model->GetJoint(arm2_arm3_joint_name)->GetScopedName();
			std::string arm3_arm4_joint = this->model->GetJoint(arm3_arm4_joint_name)->GetScopedName();

			this->jointController->SetPositionPID(chassis_arm1_joint_name, pid);
			this->jointController->SetPositionPID(arm1_arm2_joint_name, pid);
			this->jointController->SetPositionPID(arm2_arm3_joint_name, pid);
			this->jointController->SetPositionPID(arm3_arm4_joint_name, pid);

			// Listen to the update event. This event is broadcast every
			// simulation iteration.
			this->updateConnection = event::Events::ConnectWorldUpdateBegin(
				std::bind(&ModelPush::OnUpdate, this));


			// Initialize ros, if it has not already bee initialized.
			if (!ros::isInitialized()){
				int argc = 0;
				char **argv = NULL;
				ros::init(argc, argv, "gazebo_client",
					ros::init_options::NoSigintHandler);
			}

			// Create our ROS node. This acts in a similar manner to
			// the Gazebo node
			this->rosNode.reset(new ros::NodeHandle("gazebo_client"));
			// Create a named topic, and subscribe to it.
			ros::SubscribeOptions so =	ros::SubscribeOptions::create<arm_gazebo::angles>(
				                            "/" + this->model->GetName() + "/vel_cmd",
				                            1,
											boost::bind(&ModelPush::OnRosMsg, this, _1),
											ros::VoidPtr(), 
											&this->rosQueue);
			this->rosSub = this->rosNode->subscribe(so);

			// Spin up the queue helper thread.
			this->rosQueueThread =
			std::thread(std::bind(&ModelPush::QueueThread, this));
		}
		public: void OnRosMsg(const arm_gazebo::angles::ConstPtr& msg){
				this->SetAngle(msg);
		}
		public: void SetAngle(const arm_gazebo::angles::ConstPtr& msg)
		{		
			std::string chassis_arm1_joint = this->model->GetJoint(chassis_arm1_joint_name)->GetScopedName();
			std::string arm1_arm2_joint = this->model->GetJoint(arm1_arm2_joint_name)->GetScopedName();
			std::string arm2_arm3_joint = this->model->GetJoint(arm2_arm3_joint_name)->GetScopedName();
			std::string arm3_arm4_joint = this->model->GetJoint(arm3_arm4_joint_name)->GetScopedName();
			this->jointController->SetPositionTarget(chassis_arm1_joint,  msg->chassis_arm1_joint);
			this->jointController->SetPositionTarget(arm1_arm2_joint,  msg->arm1_arm2_joint);
			this->jointController->SetPositionTarget(arm2_arm3_joint,  msg->arm2_arm3_joint);
			this->jointController->SetPositionTarget(arm3_arm4_joint,  msg->arm3_arm4_joint);
		}
		public: void SetVelocity(const double &_vel){
			// Set the joint's target velocity.
			std::string name = this->model->GetJoint("arm2_arm3_joint")->GetScopedName();
			this->jointController->SetVelocityTarget(name, 10.0);
		}
		
		/// brief ROS helper function that processes messages
		private: void QueueThread(){
			static const double timeout = 0.01;
			while (this->rosNode->ok())
			{
				this->rosQueue.callAvailable(ros::WallDuration(timeout));
			}
		}

		// Called by the world update start event
		public:	void OnUpdate(){
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
			std::cout << "Current chassis_arm1_joint_name values: " << j1 * 180.0 / M_PI << std::endl;
			std::cout << "Current arm1_arm2_joint values: " << j2 * 180.0 / M_PI << std::endl;
			std::cout << "Current arm2_arm3_joint values: " << j3 * 180.0 / M_PI << std::endl;
			std::cout << "Current rm3_arm4_joint values: " << j4 * 180.0 / M_PI << std::endl;
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


	};

	// Register this plugin with the simulator
	GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}
