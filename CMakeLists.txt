cmake_minimum_required(VERSION 3.27)
project(SENG1210_Prison_Database)

set(CMAKE_CXX_STANDARD 14)

include_directories(V1)
include_directories(V4)

add_executable(SENG1210_Prison_Database
        V4/Customize.h
        V4/EntryException.h
        V4/FileProcessor.h
        V4/IndexRange.cpp
        V4/PasswordException.h
        V4/RangeException.h
        V4/Schedule.cpp
        V4/V4_Inmate.cpp
        V4/V4_Inmate.h
        V4/V4_InmateDatabaseFunctions.h
        V4/V4_Staff.cpp
        V4/V4_Staff.h
        V4/V4_StaffDatabaseFunctions.h
        V4/V4_Test.cpp
        V4/V4_User.cpp
        V4/V4_User.h
        V4/V4_UserDatabaseFunctions.h
        V4/WelcomePageWithSchedule.cpp)
