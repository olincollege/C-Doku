add_library(model model.c model.h)
add_library(view view.c view.h)
add_library(controller controller.c controller.h)

add_executable(run_sudoku main.c)
target_link_libraries(run_sudoku model view controller)
