#include <gazebo/gazebo.hh>                // for accessing all gazebo classes
#include <gazebo/common/common.hh>         // for common fn in gazebo like ModelPlugin, event
#include <gazebo/physics/physics.hh>       // for gazebo physics, to access -- ModelPtr
#include <ignition/math/Vector3.hh>        // to access Vector3d() from ignition math class

namespace gazebo {
    class lift_drag_plugin : public ModelPlugin {
    private:
        impl_->update_connection_ = gazebo::event::Events::ConnectWorldUpdateBegin(
        std::bind(&DronePluginPrivate::OnUpdate, impl_.get()));

        impl_->motor_speed_subscriber = impl_->ros_node_->create_subscription<drone_plugin::msg::MotorSpeed>(
        "/motor_speed", 10, 
        std::bind(&DronePluginPrivate::onMotorSpeedsMsg, impl_.get(), std::placeholders::_1));

        // ------------------------------------------------
        void DronePluginPrivate::onMotorSpeedsMsg(const drone_plugin::msg::MotorSpeed::SharedPtr msg)  {
            _motor_speed_msg = msg;
        }
    public:
        void DronePluginPrivate::OnUpdate(){   
            publishDronePose();
            updateThrust();

        }
        void DronePluginPrivate::updateThrust() {
        
        if(!_motor_speed_msg){
            
        }
        else{
        std::unique_lock<std::mutex> lock(mutex_);
        int n = _motor_speed_msg->name.size();
        double resulant_torque = 0.0;
        for (int i = 0; i < n; ++i) {
            // Calculate thrust and torque
            double thrust = calculateThrust(_motor_speed_msg->velocity[i]);
            double torque = calculateTorque(_motor_speed_msg->velocity[i]);

            // Add up the individual torques
            resulant_torque += torque;

            // Get the link from the model using the name
            gazebo::physics::LinkPtr link = _model->GetLink(_motor_speed_msg->name[i]);
            
            // Apply the thrust and torque to the link
            if (link != NULL) {
            link->AddLinkForce(ignition::math::Vector3d(0, thrust, 0));
            link->AddRelativeTorque(ignition::math::Vector3d(0, torque, 0));

            }
        }
        // Apply the resultant torque to the base link
        baseLink->AddRelativeTorque(ignition::math::Vector3d(0,0,resulant_torque));
        lock.unlock();
        }
        }
        void DronePluginPrivate::publishDronePose() {

            geometry_msgs::msg::PoseStamped odometryMessage;
            // Get the current pose of the base link.
            ignition::math::Pose3 baseLinkPose = baseLink->WorldPose();

            // Get the linear and angular velocities of the base link.
            ignition::math::Vector3d linearVelocity = baseLink->WorldLinearVel();
            ignition::math::Vector3d angularVelocity = baseLink->WorldAngularVel();

            // Extract position and orientation information
            odometryMessage.header.stamp = ros_node_->now();
            odometryMessage.header.frame_id = base_link_name;  
            odometryMessage.pose.position.x = baseLinkPose.Pos().X();
            odometryMessage.pose.position.y = baseLinkPose.Pos().Y();
            odometryMessage.pose.position.z = baseLinkPose.Pos().Z();
            odometryMessage.pose.orientation.x = baseLinkPose.Rot().X();
            odometryMessage.pose.orientation.y = baseLinkPose.Rot().Y();
            odometryMessage.pose.orientation.z = baseLinkPose.Rot().Z();
            odometryMessage.pose.orientation.w = baseLinkPose.Rot().W();

            // Create and set linear and angular velocities in the Twist message
            geometry_msgs::msg::Twist twist;

            twist.linear.x = linearVelocity.X();
            twist.linear.y = linearVelocity.Y();
            twist.linear.z = linearVelocity.Z();
            twist.angular.x = angularVelocity.X();
            twist.angular.y = angularVelocity.Y();
            twist.angular.z = angularVelocity.Z();

            

            velocityPublisher->publish(twist);

            droneOdomPublisher->publish(odometryMessage);
        
            if (_publish_tf) {
                geometry_msgs::msg::TransformStamped t;

                // Read message content and assign it to
                // corresponding tf variables
                t.header.stamp = ros_node_->now();
                t.header.frame_id = world_frame_name;
                t.child_frame_id = base_link_name;

                t.transform.translation.x = baseLinkPose.Pos().X();
                t.transform.translation.y = baseLinkPose.Pos().Y();
                t.transform.translation.z = baseLinkPose.Pos().Z();
                t.transform.rotation.x = baseLinkPose.Rot().X();
                t.transform.rotation.y = baseLinkPose.Rot().Y();
                t.transform.rotation.z = baseLinkPose.Rot().Z();
                t.transform.rotation.w = baseLinkPose.Rot().W();

                // Send the transformation
                tf_broadcaster_->sendTransform(t);
            }
}

}
}