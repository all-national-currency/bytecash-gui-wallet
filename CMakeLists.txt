cmake_minimum_required(VERSION 2.8)

include(BYTECashWallet.cmake)

project(${CN_PROJECT_NAME})

execute_process(COMMAND git log -1 --pretty=format:%h
WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
OUTPUT_VARIABLE GIT_REVISION)

set(CRYPTONOTE_LIB cryptonote)

include_directories(${CMAKE_BINARY_DIR}
    src
    bytecash/external
    bytecash/include
    bytecash/src)

find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
if(WIN32)
  set(Boost_USE_STATIC_RUNTIME OFF)
else(WIN32)
  set(Boost_USE_STATIC_RUNTIME ON)
endif(WIN32)

find_package(Boost 1.55 REQUIRED COMPONENTS date_time filesystem program_options regex serialization system thread chrono)
if ((${Boost_MAJOR_VERSION} EQUAL 1) AND (${Boost_MINOR_VERSION} EQUAL 54))
	message(SEND_ERROR "Boost version 1.54 is unsupported, more details are available here http://goo.gl/RrCFmA")
endif ()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set(VERSION "")
configure_file("bytecash/src/version.h.in" "version.h")
configure_file("src/BYTECashWalletConfig.h.in" "CryptoNoteWalletConfig.h")

add_definitions(-DGIT_REVISION=\"${GIT_REVISION}\")

set(CMAKE_AUTOMOC ON)

set(CRYPTONOTE_SOURCES
  bytecash/external/miniupnpc/connecthostport.c
  bytecash/external/miniupnpc/igd_desc_parse.c
  bytecash/external/miniupnpc/minisoap.c
  bytecash/external/miniupnpc/miniupnpc.c
  bytecash/external/miniupnpc/miniwget.c
  bytecash/external/miniupnpc/minixml.c
  bytecash/external/miniupnpc/portlistingparse.c
  bytecash/external/miniupnpc/receivedata.c
  bytecash/external/miniupnpc/upnpcommands.c
  bytecash/external/miniupnpc/upnpreplyparse.c
  bytecash/src/Common/Base58.cpp
  bytecash/src/Common/CommandLine.cpp
  bytecash/src/Common/Util.cpp
  bytecash/src/Common/StringTools.cpp
  bytecash/src/Common/JsonValue.cpp
  bytecash/src/Common/ConsoleTools.cpp
  bytecash/src/Common/MemoryInputStream.cpp
  bytecash/src/Common/PathTools.cpp
  bytecash/src/Common/StdInputStream.cpp
  bytecash/src/Common/StdOutputStream.cpp
  bytecash/src/Common/StreamTools.cpp
  bytecash/src/Common/StringOutputStream.cpp
  bytecash/src/Common/StringView.cpp
  bytecash/src/Common/VectorOutputStream.cpp
  bytecash/src/crypto/blake256.c
  bytecash/src/crypto/chacha8.c
  bytecash/src/crypto/crypto-ops-data.c
  bytecash/src/crypto/crypto-ops.c
  bytecash/src/crypto/crypto.cpp
  bytecash/src/crypto/groestl.c
  bytecash/src/crypto/hash-extra-blake.c
  bytecash/src/crypto/hash-extra-groestl.c
  bytecash/src/crypto/hash-extra-jh.c
  bytecash/src/crypto/hash-extra-skein.c
  bytecash/src/crypto/hash.c
  bytecash/src/crypto/jh.c
  bytecash/src/crypto/keccak.c
  bytecash/src/crypto/oaes_lib.c
  bytecash/src/crypto/random.c
  bytecash/src/crypto/skein.c
  bytecash/src/crypto/slow-hash.c
  bytecash/src/crypto/slow-hash.cpp
  bytecash/src/crypto/tree-hash.c
  bytecash/src/CryptoNoteCore/BlockchainIndices.cpp
  bytecash/src/CryptoNoteCore/BlockchainMessages.cpp
  bytecash/src/CryptoNoteCore/BlockIndex.cpp
  bytecash/src/CryptoNoteCore/CoreConfig.cpp
  bytecash/src/CryptoNoteCore/CryptoNoteBasic.cpp
  bytecash/src/CryptoNoteCore/CryptoNoteTools.cpp
  bytecash/src/CryptoNoteCore/Currency.cpp
  bytecash/src/CryptoNoteCore/MinerConfig.cpp
  bytecash/src/CryptoNoteCore/Transaction.cpp
  bytecash/src/CryptoNoteCore/Account.cpp
  bytecash/src/CryptoNoteCore/Blockchain.cpp
  bytecash/src/CryptoNoteCore/Checkpoints.cpp
  bytecash/src/CryptoNoteCore/CryptoNoteBasicImpl.cpp
  bytecash/src/CryptoNoteCore/Core.cpp
  bytecash/src/CryptoNoteCore/CryptoNoteFormatUtils.cpp
  bytecash/src/CryptoNoteCore/CryptoNoteSerialization.cpp
  bytecash/src/CryptoNoteCore/Difficulty.cpp
  bytecash/src/CryptoNoteCore/IBlock.cpp
  bytecash/src/CryptoNoteCore/Miner.cpp
  bytecash/src/CryptoNoteCore/TransactionExtra.cpp
  bytecash/src/CryptoNoteCore/TransactionPool.cpp
  bytecash/src/CryptoNoteCore/TransactionPrefixImpl.cpp
  bytecash/src/CryptoNoteCore/TransactionUtils.cpp
  bytecash/src/InProcessNode/InProcessNode.cpp
  bytecash/src/InProcessNode/InProcessNodeErrors.cpp
  bytecash/src/NodeRpcProxy/NodeErrors.cpp
  bytecash/src/NodeRpcProxy/NodeRpcProxy.cpp
  bytecash/src/P2p/NetNodeConfig.cpp
  bytecash/src/Serialization/BinaryInputStreamSerializer.cpp
  bytecash/src/Serialization/BinaryOutputStreamSerializer.cpp
  bytecash/src/Serialization/JsonInputValueSerializer.cpp
  bytecash/src/Serialization/JsonOutputStreamSerializer.cpp
  bytecash/src/Serialization/KVBinaryInputStreamSerializer.cpp
  bytecash/src/Serialization/KVBinaryOutputStreamSerializer.cpp
  bytecash/src/Serialization/SerializationOverloads.cpp
  bytecash/src/Transfers/BlockchainSynchronizer.cpp
  bytecash/src/Transfers/SynchronizationState.cpp
  bytecash/src/Transfers/TransfersConsumer.cpp
  bytecash/src/Transfers/TransfersContainer.cpp
  bytecash/src/Transfers/TransfersSubscription.cpp
  bytecash/src/Transfers/TransfersSynchronizer.cpp
  bytecash/src/Wallet/LegacyKeysImporter.cpp
  bytecash/src/Wallet/WalletAsyncContextCounter.cpp
  bytecash/src/Wallet/WalletErrors.cpp
  bytecash/src/WalletLegacy/KeysStorage.cpp
  bytecash/src/WalletLegacy/WalletLegacy.cpp
  bytecash/src/WalletLegacy/WalletHelper.cpp
  bytecash/src/WalletLegacy/WalletLegacySerializer.cpp
  bytecash/src/WalletLegacy/WalletLegacySerialization.cpp
  bytecash/src/WalletLegacy/WalletTransactionSender.cpp
  bytecash/src/WalletLegacy/WalletUnconfirmedTransactions.cpp
  bytecash/src/WalletLegacy/WalletUserTransactionsCache.cpp
  bytecash/src/System/ContextGroup.cpp
  bytecash/src/System/Event.cpp
  bytecash/src/System/EventLock.cpp
  bytecash/src/System/InterruptedException.cpp
  bytecash/src/System/Ipv4Address.cpp
  bytecash/src/System/TcpStream.cpp
  bytecash/src/HTTP/HttpRequest.cpp
  bytecash/src/HTTP/HttpParser.cpp
  bytecash/src/HTTP/HttpParserErrorCodes.cpp
  bytecash/src/HTTP/HttpResponse.cpp
  bytecash/src/Rpc/HttpClient.cpp
  bytecash/src/Rpc/JsonRpc.cpp
  bytecash/src/P2p/NetNode.cpp
  bytecash/src/P2p/LevinProtocol.cpp
  bytecash/src/P2p/NetNodeConfig.cpp
  bytecash/src/P2p/PeerListManager.cpp
  bytecash/src/CryptoNoteProtocol/CryptoNoteProtocolHandler.cpp
  bytecash/src/Logging/ILogger.cpp
  bytecash/src/Logging/LoggerGroup.cpp
  bytecash/src/Logging/CommonLogger.cpp
  bytecash/src/Logging/LoggerManager.cpp
  bytecash/src/Logging/FileLogger.cpp
  bytecash/src/Logging/StreamLogger.cpp
  bytecash/src/Logging/ConsoleLogger.cpp
  bytecash/src/Logging/LoggerMessage.cpp
  bytecash/src/Logging/LoggerRef.cpp
  bytecash/src/BlockchainExplorer/BlockchainExplorer.cpp
  bytecash/src/BlockchainExplorer/BlockchainExplorerDataBuilder.cpp
  bytecash/src/BlockchainExplorer/BlockchainExplorerErrors.cpp
)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE FORMS src/gui/ui/*.ui)

set(QRC src/resources.qrc)

qt5_wrap_ui(UIS ${FORMS})
qt5_add_resources(RCC ${QRC})


if (WIN32)
  if (NOT MSVC)
	message(FATAL_ERROR "Only MSVC is supported on this platform")
  endif ()
  add_definitions(/D_CRT_SECURE_NO_WARNINGS /D_WIN32_WINNT=0x0600 /DSTATICLIB)
  include_directories(bytecash/src/platform/msc)

  set(PLATFORM_DIR Windows)
  set(BUILD_PLATFORM WIN32)
  set(BUILD_RESOURCES src/bytecashwallet.rc)
  set(QTMAIN Qt5::WinMain)

elseif (UNIX)
  set(CRYPTONOTE_SOURCES ${CRYPTONOTE_SOURCES} bytecash/external/miniupnpc/minissdpc.c)
  if (APPLE)
    enable_language(ASM)
    file(GLOB_RECURSE OBJC_SOURCES src/*.mm)
    set(SOURCES ${SOURCES} ${OBJC_SOURCES})
    set(PLATFORM_DIR OSX)
    set(MACOSX_BUNDLE_INFO_STRING "BYTECash GUI wallet")
    set(MACOSX_BUNDLE_LONG_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_NAME BYTECashWallet)
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_VERSION "$${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")

    find_package(Qt5PrintSupport REQUIRED)

    include_directories(/usr/include/malloc)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11 -stdlib=libc++")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -maes -D_DARWIN_C_SOURCE")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework CoreFoundation -framework Carbon -framework IOKit -L/usr/lib")

    set(MACOSX_BUNDLE_ICON_FILE cryptonote.icns)
    set(APPLICATION_ICON src/images/cryptonote.icns)
    set_source_files_properties(${APPLICATION_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    set(BUILD_PLATFORM MACOSX_BUNDLE)
    set(BUILD_RESOURCES ${APPLICATION_ICON})
	
    GET_TARGET_PROPERTY(QT_LIB_DIR "${Qt5Widgets_LIBRARIES}" LOCATION)
    GET_FILENAME_COMPONENT(QT_LIB_DIR "${QT_LIB_DIR}" PATH)
  else(APPLE)
    set(PLATFORM_DIR Linux)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -maes -std=c11")
  endif (APPLE)
endif ()

include_directories(bytecash/src/Platform/${PLATFORM_DIR})
file(GLOB PLATFORM_SOURCES bytecash/src/Platform/${PLATFORM_DIR}/System/*)
set(CRYPTONOTE_SOURCES ${CRYPTONOTE_SOURCES} ${PLATFORM_SOURCES})

add_library(${CRYPTONOTE_LIB} STATIC ${CRYPTONOTE_SOURCES})
set_target_properties(${CRYPTONOTE_LIB} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE)
target_link_libraries(${CRYPTONOTE_LIB} ${Boost_LIBRARIES})

add_executable(${PROJECT_NAME} ${BUILD_PLATFORM} ${BUILD_RESOURCES} ${SOURCES} ${HEADERS} ${UIS} ${RCC})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${QTMAIN} ${CRYPTONOTE_LIB})

if (APPLE)
  qt5_use_modules(${PROJECT_NAME} PrintSupport)
elseif (UNIX)
  target_link_libraries(${PROJECT_NAME} -lpthread)
elseif (WIN32)
  target_link_libraries(${PROJECT_NAME} Imm32 Iphlpapi Winmm)
endif (APPLE)

qt5_use_modules(${PROJECT_NAME} Widgets Gui)
