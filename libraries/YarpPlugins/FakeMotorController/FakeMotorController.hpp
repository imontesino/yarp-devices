// Authors: see AUTHORS.md at project root.
// CopyPolicy: released under the terms of the LGPLv2.1, see LICENSE at project root.
// URL: https://github.com/asrob-uc3m/yarp-devices

#ifndef __FAKE_MOTOR_CONTROLLER__
#define __FAKE_MOTOR_CONTROLLER__

#include <yarp/os/all.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/dev/Drivers.h>
#include <yarp/dev/PolyDriver.h>

#include <vector>

#include "ColorDebug.h"

#include "IRobotManager.hpp"

namespace asrob
{

/**
 * @ingroup YarpPlugins
 * @brief FakeMotorController
 */
class FakeMotorController : public yarp::dev::DeviceDriver, public IRobotManager {

public:

    FakeMotorController() {}

    // -------- RobotManager declarations. Implementation in FakeMotorController.cpp --------

    /// @brief Robot: Move forward (use negative value for move backward). position mode [m]. Velocity mode [m/s].
    virtual bool moveForward(double value);

    /// @brief Robot: Turn left (use negative value for turn left). position mode [deg]. Velocity mode [deg/s].
    virtual bool turnLeft(double value);

    /// @brief Robot: Stop movement.
    virtual bool stopMovement();

    /// @brief Robot camera: Tilt down (use negative value for tilt up). position mode [deg]. Velocity mode [deg/s].
    virtual bool tiltDown(double value);

    /// @brief Robot camera: Pan left (use negative value for pan right). position mode [deg]. Velocity mode [deg/s].
    virtual bool panLeft(double value);

    /// @brief Robot camera: Stop movement.
    virtual bool stopCameraMovement();

    // -------- DeviceDriver declarations. Implementation in DeviceDriverImpl.cpp --------

    /**
    * Open the DeviceDriver.
    * @param config is a list of parameters for the device.
    * Which parameters are effective for your device can vary.
    * See \ref dev_examples "device invocation examples".
    * If there is no example for your device,
    * you can run the "yarpdev" program with the verbose flag
    * set to probe what parameters the device is checking.
    * If that fails too,
    * you'll need to read the source code (please nag one of the
    * yarp developers to add documentation for your device).
    * @return true/false upon success/failure
    */
    virtual bool open(yarp::os::Searchable& config);

    /**
    * Close the DeviceDriver.
    * @return true/false on success/failure.
    */
    virtual bool close();

};

}  // namespace asrob

#endif  // __FAKE_MOTOR_CONTROLLER__
