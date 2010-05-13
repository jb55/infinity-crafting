INCLUDE_DIRECTORIES(
    ../
)                    

ADD_EXECUTABLE(TestCraft
    TestCraft.cpp 
)

TARGET_LINK_LIBRARIES(TestCraft
    crafting
)

