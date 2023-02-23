add_library(model model.c model.h)

add_library(view view.c view.h)

# add_library(boards boards.h)

target_link_libraries(model PRIVATE view)

add_executable(main main.c)
target_link_libraries(main PRIVATE model view)
