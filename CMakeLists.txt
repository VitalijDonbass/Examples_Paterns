cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(NAME_PROJECT Examples_Patterns)
project(${NAME_PROJECT} LANGUAGES CXX)

set_target_properties(
	PROPERTIES CXX_STANDARD 14
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
)

add_subdirectory(AbsractFactory/)
add_subdirectory(Adapter/)
add_subdirectory(Bridge/)
add_subdirectory(Builder/)
add_subdirectory(FactoryMethod/)
add_subdirectory(Prototype/)
add_subdirectory(Singleton/)