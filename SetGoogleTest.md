# Setting Google Test
#### Manual for noobs

I hope it helps to everybody who wants to set and use Gtest in CLion, without any clue, like me. 

#### After those steps:

- you will have separate subprojects in your projects, one for the tests and one for your original project. 
- your original main.cpp will remain and conpletly usable. 
- you can use the built-in Google Test support provided by CLion. 

I followed the CLion recommendations everywhere I can. 

#### The resources I used: 
JetBrains video about CLion Google Test support: https://www.youtube.com/watch?v=8Up5eNZ0FLw

JetBrains video about CLion Google Test settings: https://www.youtube.com/watch?v=Rbb0fVCz41w 

JetBrains's blog post about Google Test support and settings: https://blog.jetbrains.com/clion/2015/10/new-clion-1-2-eap-build-brings-you-google-test/

### 1. Download Google Test

Download Google Test: https://code.google.com/p/googletest/

### 2. Set file structure

In CLion you need to separate your existing project from Google Test, so:
 - make a new directory under your project directory and remove here all of your .cpp, .hpp, .h files (mine become "dustbin")
 It is important to refactor/remove them (Shift/F6) to let the CLion set the includes automatic.
 - make another new directory and name it like your project + add a tests word to it: (mine become "dustbin_tests")
 - inside this "tests" directory, create another, named "lib" and copy (manually) the full downloaded Google Test here.
 - also make here a "tests" directory too.
 
 So your directory structure needs to look like this:
 
 - project 
    - project_files 
    - project_tests 
        - lib
            - gtest
        - tests
            
You should have the main.cpp and CMakeLists.txt files under your project root, as they were original.
   
### 3. Create and set CMakeLists files
   
   You need to have separate CMakeLists.txt files in almost all subdirectories, but at least one per project and one in the root.
   
#### project/CMakeLists.txt content:
   
      cmake_minimum_required(VERSION 3.8) 
      project(project_name) 
      set(CMAKE_CXX_STANDARD 11) 
      set(SOURCE_FILES main.cpp) 
      add_executable(project_name ${SOURCE_FILES}) 
      include_directories(project_files) 
      add_subdirectory(project_files) 
      add_subdirectory(project_tests) 
      target_link_libraries(project_name project_files) 
   
#### project/project_files/CMakeLists.txt content:
   
      project(project_name) 
      set(HEADER_FILES all of your project's .hpp and .h files listed here) 
      set(SOURCE_FILES all of your project's .cpp files listed here) 
      add_library(project_files STATIC ${SOURCE_FILES} ${HEADER_FILES}) 
  
#### project/project_tests/CMakeLists.txt content:
   
      project(project_tests) -> create here the second project 
      add_subdirectory(lib/gtest-1.7.0) -> here we linked to the gtest own CMake 
      add_subdirectory(tests) 
   
#### project_tests/tests/CMakeLists.txt content:
   
      include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}) 
      add_executable(project_tests here comes all your test .cpp files) 
      target_link_libraries(project_tests gtest gtest_main) 
      target_link_libraries(project_tests project_files) 
  
### 4. Create Gtest
  
  Creating Google Test is same like creating a class, 
  - you need to #include "gtest/gtest.h", and
  - inherit your class from ::testing::Test

If they are done, you can use Alt+Insert to generate Tests, and Ctrl+Shift+F10 to Run the test where the carret is placed.

### 5. Set tests in run/debug configuration

In the ideal case you can run from here the main.cpp, or the test files, separate or all of them.

In the run/debug configurations panel you can add/remove configuration, on the left side will be a Google Test.
There should be already here a configuration to run all your test, which you set earlier in the tests library CMake as executable.
You can specify a suite here by adding your class name inherited from Google's Test, in this case this config should run only those tests.

### 6. Enjoy

Thanks for reading it. 
