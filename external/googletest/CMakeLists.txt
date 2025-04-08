cmake_minimum_required(VERSION 3.20.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
    googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)
