// This file is part of the "x0" project, http://github.com/christianparpart/libflow//
//   (c) 2009-2014 Christian Parpart <trapni@gmail.com>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#pragma once

#include <flow/Api.h>
#include <flow/ir/Constant.h>
#include <flow/vm/Signature.h>

#include <string>
#include <vector>
#include <list>

namespace flow {

class CORTEX_FLOW_API IRBuiltinHandler : public Constant {
 public:
  IRBuiltinHandler(const vm::Signature& sig)
      : Constant(FlowType::Boolean, sig.name()), signature_(sig) {}

  const vm::Signature& signature() const { return signature_; }
  const vm::Signature& get() const { return signature_; }

 private:
  vm::Signature signature_;
};

}  // namespace flow
