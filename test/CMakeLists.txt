# Some compilers warn that the return value of cr_assert gets converted from an
# int to a unsigned char:1. To avoid this error in those compilers, turn off
# conversion warnings for test code.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-conversion")


add_executable(test_boards test_boards.c)
target_link_libraries(test_boards
  PRIVATE boards
  PUBLIC ${CRITERION}
)
add_test(
  NAME test_boards
  COMMAND test_boards ${CRITERION_FLAGS}
)

add_executable(test_model test_model.c)
target_link_libraries(test_model
  PRIVATE model
  PUBLIC ${CRITERION}
)
add_test(
  NAME test_model
  COMMAND test_model ${CRITERION_FLAGS}
)

add_executable(test_view test_view.c)
target_link_libraries(test_view
  PRIVATE view model
  PUBLIC ${CRITERION}
)
add_test(
  NAME test_view
  COMMAND test_view ${CRITERION_FLAGS}
)

add_executable(test_controller test_controller.c)
target_link_libraries(test_controller
  PRIVATE controller model
  PUBLIC ${CRITERION}
)
add_test(
  NAME test_controller
  COMMAND test_controller ${CRITERION_FLAGS}
)
