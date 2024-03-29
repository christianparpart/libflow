// This file is part of the "x0" project, http://github.com/christianparpart/libflow//
//   (c) 2009-2014 Christian Parpart <trapni@gmail.com>
//
// Licensed under the MIT License (the "License"); you may not use this
// file except in compliance with the License. You may obtain a copy of
// the License at: http://opensource.org/licenses/MIT

#include <flow/ir/PassManager.h>
#include <flow/ir/HandlerPass.h>
#include <flow/ir/IRProgram.h>

namespace flow {

PassManager::PassManager() {
}

PassManager::~PassManager() {
}

void PassManager::registerPass(std::unique_ptr<HandlerPass>&& handlerPass) {
  handlerPasses_.push_back(std::move(handlerPass));
}

void PassManager::run(IRProgram* program) {
  for (IRHandler* handler : program->handlers()) {
    run(handler);
  }
}

void PassManager::run(IRHandler* handler) {
again:
  for (auto& pass : handlerPasses_) {
    // printf("Running pass: %s\n", pass->name());
    if (pass->run(handler)) {
      goto again;
    }
  }
}

}  // namespace flow
