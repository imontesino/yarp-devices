# Authors: see AUTHORS.md at project root.
# CopyPolicy: released under the terms of the LGPLv2.1, see LICENSE at project root.
# URL: https://github.com/asrob-uc3m/yarp-devices

# Device interface target.
add_library(RobotInterfaces INTERFACE)

# Configure usage requirements.
target_include_directories(RobotInterfaces INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                                                     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Install interface headers.
install(FILES IRobotManager.hpp
              DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Register export set.
install(TARGETS RobotInterfaces
        EXPORT ASROB_YARP_DEVICES)

# YARP devices.
add_subdirectory(EcroPwmController)
add_subdirectory(EcroWheelController)
add_subdirectory(FakeMotorController)
add_subdirectory(LaserTowerOfDeathController)
add_subdirectory(RaspiOnePwmMotorController)
add_subdirectory(RaspiTwoPwmMotorController)
add_subdirectory(RobotClient)
add_subdirectory(RobotServer)
