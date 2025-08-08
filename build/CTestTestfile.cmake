# CMake generated Testfile for 
# Source directory: /home/user/progr/final
# Build directory: /home/user/progr/final/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[final.test]=] "/home/user/progr/final/build/Debug/final.test")
  set_tests_properties([=[final.test]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/user/progr/final/CMakeLists.txt;56;add_test;/home/user/progr/final/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[final.test]=] "/home/user/progr/final/build/Release/final.test")
  set_tests_properties([=[final.test]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/user/progr/final/CMakeLists.txt;56;add_test;/home/user/progr/final/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[final.test]=] "/home/user/progr/final/build/RelWithDebInfo/final.test")
  set_tests_properties([=[final.test]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/user/progr/final/CMakeLists.txt;56;add_test;/home/user/progr/final/CMakeLists.txt;0;")
else()
  add_test([=[final.test]=] NOT_AVAILABLE)
endif()
