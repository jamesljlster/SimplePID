cmake_minimum_required(VERSION 2.8)

# Set project
project(SPID_test)

# Set file list
set(SPID_TEST_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/test.c
	)

# Set depedences
set(SPID_TEST_DEPS
	SPID
	)

# Build test
add_executable(SPID_TEST_BIN ${SPID_TEST_SRCS})
set_target_properties(SPID_TEST_BIN
	PROPERTIES
	OUTPUT_NAME	"SPID_test"
	)
target_link_libraries(SPID_TEST_BIN SPID_TEST_DEPS)

# Installing
install(TARGETS SPID_TEST_BIN
	RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
	)
