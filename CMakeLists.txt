
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_USE_RELATIVE_PATHS on)

SET(PROJECT_NAME nqueens)

SET(CXX_FLAGS
  -Wall
  -Wextra
  -pthread
  -O2
  -std=c++11
  )
STRING(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/src")

SET(nqueens_SRCS
  ${PROJECT_SOURCE_DIR}/src/nqueens_solver.cpp
  ${PROJECT_SOURCE_DIR}/src/work_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/nqueens_mul_thrd.cpp
  )

SET(master_SRCS
  ${PROJECT_SOURCE_DIR}/src/master.cpp
  ${PROJECT_SOURCE_DIR}/src/proto/nqueens.pb.cc
  ${PROJECT_SOURCE_DIR}/src/nqueens_solver.cpp
  ${PROJECT_SOURCE_DIR}/src/work_manager.cpp
  )

SET(slave_SRCS
  ${PROJECT_SOURCE_DIR}/src/slave.cpp
  ${PROJECT_SOURCE_DIR}/src/proto/nqueens.pb.cc
  ${PROJECT_SOURCE_DIR}/src/nqueens_solver.cpp
  ${PROJECT_SOURCE_DIR}/src/work_manager.cpp
  )

ADD_EXECUTABLE(nqueens_mul_thrd ${nqueens_SRCS})

ADD_EXECUTABLE(nqueens_master ${master_SRCS})

ADD_EXECUTABLE(nqueens_slave ${slave_SRCS})

TARGET_LINK_LIBRARIES(nqueens_master protobuf boost_system)

TARGET_LINK_LIBRARIES(nqueens_slave protobuf boost_system)

