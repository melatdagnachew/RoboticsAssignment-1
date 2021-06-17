// Generated by gencpp from file arm_gazebo/angles.msg
// DO NOT EDIT!


#ifndef ARM_GAZEBO_MESSAGE_ANGLES_H
#define ARM_GAZEBO_MESSAGE_ANGLES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace arm_gazebo
{
template <class ContainerAllocator>
struct angles_
{
  typedef angles_<ContainerAllocator> Type;

  angles_()
    : chassis_arm1_joint(0.0)
    , arm1_arm2_joint(0.0)
    , arm2_arm3_joint(0.0)
    , arm3_arm4_joint(0.0)  {
    }
  angles_(const ContainerAllocator& _alloc)
    : chassis_arm1_joint(0.0)
    , arm1_arm2_joint(0.0)
    , arm2_arm3_joint(0.0)
    , arm3_arm4_joint(0.0)  {
  (void)_alloc;
    }



   typedef float _chassis_arm1_joint_type;
  _chassis_arm1_joint_type chassis_arm1_joint;

   typedef float _arm1_arm2_joint_type;
  _arm1_arm2_joint_type arm1_arm2_joint;

   typedef float _arm2_arm3_joint_type;
  _arm2_arm3_joint_type arm2_arm3_joint;

   typedef float _arm3_arm4_joint_type;
  _arm3_arm4_joint_type arm3_arm4_joint;





  typedef boost::shared_ptr< ::arm_gazebo::angles_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::arm_gazebo::angles_<ContainerAllocator> const> ConstPtr;

}; // struct angles_

typedef ::arm_gazebo::angles_<std::allocator<void> > angles;

typedef boost::shared_ptr< ::arm_gazebo::angles > anglesPtr;
typedef boost::shared_ptr< ::arm_gazebo::angles const> anglesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::arm_gazebo::angles_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::arm_gazebo::angles_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::arm_gazebo::angles_<ContainerAllocator1> & lhs, const ::arm_gazebo::angles_<ContainerAllocator2> & rhs)
{
  return lhs.chassis_arm1_joint == rhs.chassis_arm1_joint &&
    lhs.arm1_arm2_joint == rhs.arm1_arm2_joint &&
    lhs.arm2_arm3_joint == rhs.arm2_arm3_joint &&
    lhs.arm3_arm4_joint == rhs.arm3_arm4_joint;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::arm_gazebo::angles_<ContainerAllocator1> & lhs, const ::arm_gazebo::angles_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace arm_gazebo

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::arm_gazebo::angles_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::arm_gazebo::angles_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm_gazebo::angles_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm_gazebo::angles_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm_gazebo::angles_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm_gazebo::angles_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::arm_gazebo::angles_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1806b3e2a144e1ddd7c5a2029efd77fc";
  }

  static const char* value(const ::arm_gazebo::angles_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1806b3e2a144e1ddULL;
  static const uint64_t static_value2 = 0xd7c5a2029efd77fcULL;
};

template<class ContainerAllocator>
struct DataType< ::arm_gazebo::angles_<ContainerAllocator> >
{
  static const char* value()
  {
    return "arm_gazebo/angles";
  }

  static const char* value(const ::arm_gazebo::angles_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::arm_gazebo::angles_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 chassis_arm1_joint\n"
"float32 arm1_arm2_joint\n"
"float32 arm2_arm3_joint \n"
"float32 arm3_arm4_joint\n"
;
  }

  static const char* value(const ::arm_gazebo::angles_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::arm_gazebo::angles_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.chassis_arm1_joint);
      stream.next(m.arm1_arm2_joint);
      stream.next(m.arm2_arm3_joint);
      stream.next(m.arm3_arm4_joint);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct angles_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::arm_gazebo::angles_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::arm_gazebo::angles_<ContainerAllocator>& v)
  {
    s << indent << "chassis_arm1_joint: ";
    Printer<float>::stream(s, indent + "  ", v.chassis_arm1_joint);
    s << indent << "arm1_arm2_joint: ";
    Printer<float>::stream(s, indent + "  ", v.arm1_arm2_joint);
    s << indent << "arm2_arm3_joint: ";
    Printer<float>::stream(s, indent + "  ", v.arm2_arm3_joint);
    s << indent << "arm3_arm4_joint: ";
    Printer<float>::stream(s, indent + "  ", v.arm3_arm4_joint);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARM_GAZEBO_MESSAGE_ANGLES_H