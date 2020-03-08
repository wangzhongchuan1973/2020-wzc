/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 * @brief Defines the ControllerAgent class.
 */

#ifndef MODULES_CONTROL_CONTROLLER_CONTROLLER_AGENT_H_
#define MODULES_CONTROL_CONTROLLER_CONTROLLER_AGENT_H_

#include <cstdio>
#include <memory>
#include <vector>

#include "modules/common/util/factory.h"
#include "modules/control/controller/controller.h"
#include "modules/control/proto/control_cmd.pb.h"
#include "modules/control/proto/control_conf.pb.h"
#include "modules/planning/proto/planning.pb.h"
#include "third_party/ros/include/ros/ros.h"

/**
 * @namespace apollo::control
 * @brief apollo::control
 */
namespace apollo {
namespace control {

/**
 * @class ControllerAgent
 *
 * @brief manage all controllers declared in control config file.
 */
class ControllerAgent {
 public:
  /**
   * @brief initialize ControllerAgent
   * @param control_conf control configurations
   * @return Status initialization status
   */
  Status Init(const ControlConf *control_conf);

  /**
   * @brief compute control command based on current vehicle status
   *        and target trajectory
   * @param localization vehicle location
   * @param chassis vehicle status e.g., speed, acceleration
   * @param trajectory trajectory generated by planning
   * @param cmd control command
   * @return Status computation status
   */
  Status ComputeControlCommand(
      const ::apollo::localization::LocalizationEstimate *localization,
      const ::apollo::canbus::Chassis *chassis,
      const ::apollo::planning::ADCTrajectory *trajectory,
      ::apollo::control::ControlCommand *cmd);

  /**
   * @brief reset ControllerAgent
   * @return Status reset status
   */
  Status Reset();

 private:
  /**
   * @brief
   * Register new controllers. If you need to add a new type of controller,
   * You should first register your controller in this function.
   */
  void RegisterControllers();

  Status InitializeConf(const ControlConf *control_conf);

  const ControlConf *control_conf_ = nullptr;
  apollo::common::util::Factory<ControlConf::ControllerType, Controller>
      controller_factory_;
  std::vector<std::unique_ptr<Controller>> controller_list_;
};

}  // namespace control
}  // namespace apollo

#endif  // MODULES_CONTROL_CONTROLLER_CONTROLLER_AGENT_H_
