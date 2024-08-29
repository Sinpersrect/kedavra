
cmake_minimum_required (VERSION 3.17.1)
project(g_xml)

if(DEFINED ENV{ANTLR_RUNTIME})
        set(ANTLR_RUNTIME  $ENV{ANTLR_RUNTIME})
else()
   message(FATAL_ERROR "Please set ANTLR_RUNTIME to the location of the antlr c++ runtime")
endif()

add_custom_command(OUTPUT g_xmlLexer.cpp g_xmlParser.cpp
        COMMAND antlr4 g_xml.g4 -Dlanguage=Cpp -no-listener -no-visitor
        DEPENDS g_xml.g4)

add_executable(file_parser file_parser.cpp g_xmlLexer.cpp g_xmlParser.cpp)
target_include_directories(file_parser PUBLIC ${ANTLR_RUNTIME}/runtime/src/)
target_link_libraries(file_parser ${ANTLR_RUNTIME}/dist/libantlr4-runtime.a)
