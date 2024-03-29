// This file is part of the "x0" project, http://github.com/christianparpart/libflow//
//   (c) 2009-2014 Christian Parpart <trapni@gmail.com>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#pragma once

#include <flow/Api.h>
#include <flow/ir/Value.h>

namespace flow {

class CORTEX_FLOW_API Constant : public Value {
 public:
  Constant(FlowType ty, const std::string& name) : Value(ty, name) {}

  void dump() override;
};

}  // namespace flow
