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

#include "modules/canbus/vehicle/lincoln_vehicle_factory.h"

#include "modules/canbus/vehicle/lincoln/lincoln_controller.h"
#include "modules/canbus/vehicle/lincoln/lincoln_message_manager.h"
#include "modules/common/log.h"
#include "modules/common/util/util.h"

namespace apollo {
namespace canbus {

std::unique_ptr<VehicleController>
LincolnVehicleFactory::CreateVehicleController() {
  return std::unique_ptr<VehicleController>(new lincoln::LincolnController());
}

std::unique_ptr<MessageManager> LincolnVehicleFactory::CreateMessageManager() {
  return std::unique_ptr<MessageManager>(new lincoln::LincolnMessageManager());
}

}  // namespace canbus
}  // namespace apollo
