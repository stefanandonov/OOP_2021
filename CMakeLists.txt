cmake_minimum_required(VERSION 3.17)
project(OOP_MK)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_MK main.cpp)
add_executable(datum aud1/datum.c)
add_executable(vector ex1/vector.c)
add_executable(complex ex1/complex.c)
add_executable(students ex1/students.c)
add_executable(date ex1/date.c)

add_executable(countries ex1/countries.c)
add_executable(start aud2/start.cpp)
add_executable(vraboteni aud3/vraboteni.cpp)
add_executable(drzavi aud2/drzavi.cpp)
add_executable(refExample ex2/refExample.cpp)
add_executable(people ex2/people.cpp)
add_executable(skilift ex2/skilift.c)
add_executable(voved aud3/voved.cpp)
add_executable(triagolnik aud3/triagolnik.cpp)

add_executable(email aud3/email.cpp)