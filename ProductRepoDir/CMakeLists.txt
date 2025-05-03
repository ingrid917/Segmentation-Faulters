add_library(ProductRepoLib
        Product.cpp
        ProductRepo.cpp
        Validator.cpp
)

target_include_directories(ProductRepoLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})