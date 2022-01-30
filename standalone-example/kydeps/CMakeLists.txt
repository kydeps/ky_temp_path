# ==============================================================================
# ===== [BEGIN] KyDeps CMakeLists.txt preamble ===== !!! DO NOT EDIT !!! =======
#
cmake_minimum_required(VERSION 3.22)
project(kydeps_definitions)
include(FetchContent)
FetchContent_Declare(kydep_bootstrap
    GIT_REPOSITORY https://github.com/kydeps/bootstrap.git
    GIT_TAG v3.0
)
FetchContent_MakeAvailable(kydep_bootstrap)
#
# ===== [END] KyDeps CMakeLists.txt preamble ===================================
# ==============================================================================

KyDep(gflags
    GIT_REPOSITORY https://github.com/gflags/gflags.git
    GIT_TAG f8a0efe03aa69b3336d8e228b37d4ccb17324b88 # v2.2.0

    CMAKE_ARGS
    -DREGISTER_INSTALL_PREFIX=FALSE
    -DGFLAGS_BUILD_STATIC_LIBS=TRUE
    -DGFLAGS_BUILD_SHARED_LIBS=FALSE
    -DGFLAGS_BUILD_TESTING=${KYDEPS_BUILD_TESTS}    
)

KyDep(glog
    GIT_REPOSITORY https://github.com/google/glog.git
    GIT_TAG 96a2f23dca4cc7180821ca5f32e526314395d26a # v0.4.0

    CMAKE_ARGS
    -DBUILD_TESTING=${KYDEPS_BUILD_TESTS}

    ${gflags_DEPENDENCY}
)

KyDep(ky_temp_path
    GIT_REPOSITORY "file://${CMAKE_CURRENT_LIST_DIR}/../.."
    GIT_TAG main

    ${glog_DEPENDENCY}
)