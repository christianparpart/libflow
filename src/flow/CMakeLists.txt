cmake_minimum_required(VERSION 2.8)

project(libflow CXX)
set(CORTEX_FLOW_VERSION "0.3.0")

include(TrapniCommon)

option(ENABLE_FLOW_DIRECT_THREADED_VM "Flow VM using direct threaded mode [default: off]" OFF)

set(libflow_SRC
  AST.cc
  ASTPrinter.cc
  CMakeLists.txt
  FlowCallVisitor.cc
  FlowLexer.cc
  FlowLocation.cc
  FlowParser.cc
  FlowToken.cc
  FlowType.cc
  IRGenerator.cc
  TargetCodeGenerator.cc

  ir/BasicBlock.cc
  ir/Constant.cc
  ir/ConstantArray.cc
  ir/ConstantValue.cc
  ir/Instr.cc
  ir/Instructions.cc
  ir/InstructionVisitor.cc
  ir/IRBuilder.cc
  ir/IRHandler.cc
  ir/IRProgram.cc
  ir/PassManager.cc
  ir/Value.cc

  transform/EmptyBlockElimination.cc
  transform/InstructionElimination.cc
  transform/UnusedBlockPass.cc

  vm/ConstantPool.cc
  vm/Handler.cc
  vm/Instruction.cc
  vm/Match.cc
  vm/MatchClass.cc
  vm/NativeCallback.cc
  vm/Program.cc
  vm/Runner.cc
  vm/Runtime.cc
  vm/Signature.cc
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/..)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/sysconfig.h.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/sysconfig.h)

# libflow.a
add_library(flow STATIC ${libflow_SRC})
#set_target_properties(flow PROPERTIES COMPILE_FLAGS "-fvisibility=hidden -fvisibility-inlines-hidden -DBUILD_CORTEX_FLOW=1")
target_link_libraries(flow pthread dl stx)
install(TARGETS flow DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

# headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        FILES_MATCHING PATTERN "*.h"
                       PATTERN "CMakeFiles" EXCLUDE)

# test-flow
file(GLOB_RECURSE flow_test_SRC "*-test.cc")
add_executable(test-flow ${flow_test_SRC})
target_link_libraries(test-flow flow stx/ gtest gtest_main)

# pkg-config target
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/libflow.pc.cmake
               ${CMAKE_CURRENT_BINARY_DIR}/libflow.pc)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libflow.pc 
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
