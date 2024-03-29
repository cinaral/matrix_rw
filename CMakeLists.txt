cmake_minimum_required(VERSION 3.13)

project(
	matrix_rw
	VERSION 1.2.1
	LANGUAGES CXX
)



if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	option(DEBUG_BUILD "Build everything in debug mode" ON)
	option(BUILD_TESTS "Build tests" ON)
	option(BUILD_EXAMPLES "Build examples" ON)
	option(SINGLE_PRECISION "Single precision" OFF)
	
	#* where to look for the project header and source files
	set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
	set(TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)
	set(EXAMPLE_DIR ${CMAKE_CURRENT_LIST_DIR}/examples)

	#* tests, examples, benchmarks to compile
	set(TEST_NAMES
		rw_test
	)
	set(EXAMPLE_NAMES
		read_example
		write_example
	)

	#* files to package
	set(PACKAGE_FILES 
		include/${PROJECT_NAME}/ 
		include/${PROJECT_NAME}.hpp 
		CMakeLists.txt 
		LICENSE
	)

	#* set up directories for binary, library, data and parameter files 
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
	file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/data)

	#* project compile options
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	set(CMAKE_CXX_EXTENSIONS OFF)

	add_compile_options(
		-fdiagnostics-color=always #* colored debug output
		-fmessage-length=0 #* disable line wrapping (default=72 char) 
		-Wall #* all warnings
		-Wextra #* more warnings
		-Wpedantic #* more warnings
	)
	
	if(DEBUG_BUILD)
		add_compile_options(
			-g #* debug symbols
			-O0 #* no optimization, -Og may work better with some debuggers
		)
	else()
		add_compile_options(
			-O3 #* release optimization
		)
	endif()
	
	if(SINGLE_PRECISION)
		add_compile_options(-DUSE_SINGLE_PRECISION) #* use single precision floats
	endif()

	#***********#
	#* Testing *#
	#***********#
	if(BUILD_TESTS)
		enable_testing()

		foreach(ELEMENT ${TEST_NAMES})
			add_executable(
				${ELEMENT} 
				${TEST_DIR}/${ELEMENT}.cpp						
			)
			target_include_directories(
				${ELEMENT} PRIVATE 
				${INCLUDE_DIR}
			)
			target_compile_options(
				${ELEMENT} PRIVATE
			)
			add_test(
				NAME ${ELEMENT} 
				COMMAND ${ELEMENT}
				WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
			)
		endforeach(ELEMENT ${TEST_NAMES})
	endif()

	#************#
	#* Examples *#
	#************#
	if(BUILD_EXAMPLES)
		foreach(ELEMENT ${EXAMPLE_NAMES})
			add_executable(
				${ELEMENT}
				${EXAMPLE_DIR}/${ELEMENT}.cpp						
			)
			target_include_directories(
				${ELEMENT} PRIVATE 
				${INCLUDE_DIR}
			)
			target_compile_options(
				${ELEMENT} PRIVATE
			)
		endforeach(ELEMENT ${EXAMPLE_NAMES})
	endif()

	#************************#
	#* Packaged source code *#
	#************************#
	add_custom_command(
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src.zip
		COMMAND ${CMAKE_COMMAND} -E tar c ${CMAKE_CURRENT_BINARY_DIR}/src.zip --format=zip -- ${PACKAGE_FILES}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		DEPENDS ${PACKAGE_FILES}
	) 
	add_custom_target(
		src_package 
		DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/src.zip
	)
endif()


