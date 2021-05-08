cmake_minimum_required(VERSION 3.17.5)
project(Adatstr_project_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Adatstr_project_2 main.c UI/UI.c UI/UI.h BST/bst.c BST/bst.h Reservation/reservation.c Reservation/reservation.h AdminList/admin.h AdminList/admin.c)