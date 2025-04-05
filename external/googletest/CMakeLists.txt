cmake_minimum_required(VERSION 3.20.0)

include(FetchContent)
FetchContent_Declare(
    googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)