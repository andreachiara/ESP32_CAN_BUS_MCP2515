idf_component_register(SRC_DIRS "src/"
                    INCLUDE_DIRS "include/"
                    REQUIRES driver)

set_source_files_properties(load_logic.cpp
    PROPERTIES COMPILE_FLAGS
    -std=c++17
)
