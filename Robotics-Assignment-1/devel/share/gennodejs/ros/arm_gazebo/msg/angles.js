// Auto-generated. Do not edit!

// (in-package arm_gazebo.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class angles {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.chassis_arm1_joint = null;
      this.arm1_arm2_joint = null;
      this.arm2_arm3_joint = null;
      this.arm3_arm4_joint = null;
    }
    else {
      if (initObj.hasOwnProperty('chassis_arm1_joint')) {
        this.chassis_arm1_joint = initObj.chassis_arm1_joint
      }
      else {
        this.chassis_arm1_joint = 0.0;
      }
      if (initObj.hasOwnProperty('arm1_arm2_joint')) {
        this.arm1_arm2_joint = initObj.arm1_arm2_joint
      }
      else {
        this.arm1_arm2_joint = 0.0;
      }
      if (initObj.hasOwnProperty('arm2_arm3_joint')) {
        this.arm2_arm3_joint = initObj.arm2_arm3_joint
      }
      else {
        this.arm2_arm3_joint = 0.0;
      }
      if (initObj.hasOwnProperty('arm3_arm4_joint')) {
        this.arm3_arm4_joint = initObj.arm3_arm4_joint
      }
      else {
        this.arm3_arm4_joint = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type angles
    // Serialize message field [chassis_arm1_joint]
    bufferOffset = _serializer.float32(obj.chassis_arm1_joint, buffer, bufferOffset);
    // Serialize message field [arm1_arm2_joint]
    bufferOffset = _serializer.float32(obj.arm1_arm2_joint, buffer, bufferOffset);
    // Serialize message field [arm2_arm3_joint]
    bufferOffset = _serializer.float32(obj.arm2_arm3_joint, buffer, bufferOffset);
    // Serialize message field [arm3_arm4_joint]
    bufferOffset = _serializer.float32(obj.arm3_arm4_joint, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type angles
    let len;
    let data = new angles(null);
    // Deserialize message field [chassis_arm1_joint]
    data.chassis_arm1_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arm1_arm2_joint]
    data.arm1_arm2_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arm2_arm3_joint]
    data.arm2_arm3_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [arm3_arm4_joint]
    data.arm3_arm4_joint = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'arm_gazebo/angles';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1806b3e2a144e1ddd7c5a2029efd77fc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 chassis_arm1_joint
    float32 arm1_arm2_joint
    float32 arm2_arm3_joint 
    float32 arm3_arm4_joint
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new angles(null);
    if (msg.chassis_arm1_joint !== undefined) {
      resolved.chassis_arm1_joint = msg.chassis_arm1_joint;
    }
    else {
      resolved.chassis_arm1_joint = 0.0
    }

    if (msg.arm1_arm2_joint !== undefined) {
      resolved.arm1_arm2_joint = msg.arm1_arm2_joint;
    }
    else {
      resolved.arm1_arm2_joint = 0.0
    }

    if (msg.arm2_arm3_joint !== undefined) {
      resolved.arm2_arm3_joint = msg.arm2_arm3_joint;
    }
    else {
      resolved.arm2_arm3_joint = 0.0
    }

    if (msg.arm3_arm4_joint !== undefined) {
      resolved.arm3_arm4_joint = msg.arm3_arm4_joint;
    }
    else {
      resolved.arm3_arm4_joint = 0.0
    }

    return resolved;
    }
};

module.exports = angles;
