
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_USE_RELATIVE_PATHS on)

SET(PROJECT_NAME nqueens)

SET(CXX_FLAGS
  -Wall
  -Wextra
  -std=c++11
  )
STRING(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/src")

SET(nqueens_SRCS
  ${PROJECT_SOURCE_DIR}/src/nqueens_solver.cpp
  ${PROJECT_SOURCE_DIR}/src/nqueens_mul_thrd.cpp
  )

ADD_EXECUTABLE(nqueens_mul_thrd ${nqueens_SRCS})

