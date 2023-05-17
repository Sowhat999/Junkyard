#pragma once

#include "Core/Base.h"
#include "Core/String.h"

struct SettingsGraphics
{
    bool enable = true;             // Enable graphics subsystem. (cmdline="enableGraphics")
    bool validate = false;          // Enable validation layers. (cmdline="validateGraphics")
    bool headless = false;          // Device is created, but with no views/swapchain/gfx-queue. only used for comput. (cmdline="headlessGraphics")
    bool surfaceSRGB = false;       // SRGB surface for Swap-chain
    bool listExtensions = false;    // Show device extensions upon initialization
    bool enableAdrenoDebug = false; // Tries to enable VK_LAYER_ADRENO_debug layer if available, validate should be enabled
    bool validateBestPractices = false;   // see VK_EXT_validation_features
    bool validateSynchronization = false;   // see VK_EXT_validation_features
    bool shaderDumpIntermediates = false;   // Dumps all shader intermediates (glsl/spv/asm) in the current working dir
    bool shaderDumpProperties = false;      // Dumps all internal shader properties, if device supports VK_KHR_pipeline_executable_properties
    bool shaderDebug = false;               // Adds debugging information to all shaders
    bool enableGpuProfile = false;          // Enables GPU Profiling with Tracy and other tools
    bool enableImGui = true;                // Enables ImGui GUI
    bool enableVsync = true;                // Enables Vsync. Some hardware doesn't support this feature
    bool trackResourceLeaks = false;        // Store buffers/image/etc. resource stacktraces and shows leakage information at exit
};

struct SettingsTooling
{
    bool enableServer = false;          // Starts server service (ShaderCompiler/Baking/etc.)
    uint16 serverPort = 6006;           // Local server port number       
};

struct SettingsApp
{
    bool launchMinimized = false;       // Launch application minimized (Desktop builds only)
};

struct SettingsEngine
{
    enum class LogLevel
    {
        Default = 0,
        Error,
        Warning,
        Info,
        Verbose,
        Debug,
        _Count
    };

    bool connectToServer = false;               // Connects to server
    String<256> remoteServicesUrl = "127.0.0.1:6006";   // Url to server. Divide port number with colon
#if !CONFIG_FINAL_BUILD
    LogLevel logLevel = LogLevel::Debug;        // Log filter. LogLevel below this value will not be shown
#else
    LogLevel logLevel = LogLevel::Info;        // Log filter. LogLevel below this value will not be shown
#endif
    uint32 jobsThreadCount = 0;                 // Number of threads to spawn for each job type (Long/Short)
    bool debugAllocations = false;              // Use heap allocator instead for major allocators, like temp/budget/etc.
    bool breakOnErrors = false;                 // Break when logError happens
    bool treatWarningsAsErrors = false;         // Break when logWarning happens
    bool enableMemPro = false;                  // Enables MemPro instrumentation (https://www.puredevsoftware.com/mempro/index.htm)
};

struct SettingsDebug
{
    bool captureStacktraceForFiberProtector = false;    // Capture stacktraces for Fiber protector (see Debug.cpp)
    bool captureStacktraceForTempAllocator = false;     // Capture stacktraces for Temp allocators (see Memory.cpp)
};

struct SettingsJunkyard
{
    SettingsApp app;
    SettingsEngine engine;
    SettingsGraphics graphics;
    SettingsTooling tooling;
    SettingsDebug debug;
};

API bool settingsIsInitializedJunkyard();
API void settingsInitializeJunkyard(const SettingsJunkyard& initSettings);
API const SettingsJunkyard& settingsGet();
