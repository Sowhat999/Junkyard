#ifdef BUILD_UNITY
    // Core library
    #include "Core/Base.cpp"
    #include "Core/Allocators.cpp"
    #include "Core/Buffers.cpp"
    #include "Core/System.cpp"
    #include "Core/StringUtil.cpp"
    #include "Core/Log.cpp"
    #include "Core/Hash.cpp"
    #include "Core/Debug.cpp"
    #include "Core/Jobs.cpp"
    #include "Core/JsonParser.cpp"
    #include "Core/Settings.cpp"
    #include "Core/MathAll.cpp"
    #include "Core/IniParser.cpp"
    
    // General
    #include "JunkyardSettings.cpp"
    #include "Application.cpp"
    #include "Engine.cpp"
    #include "VirtualFS.cpp"
    #include "AssetManager.cpp"
    #include "RemoteServices.cpp"
    #include "Camera.cpp"

    // Tool (General)
    #include "Tool/ShaderCompiler.cpp"
    #include "Tool/ImGuiTools.cpp"
    #include "Tool/ImageEncoder.cpp"
    #include "Tool/MeshOptimizer.cpp"
    #include "Tool/Console.cpp"

    // Graphics
    #include "Graphics/Graphics.cpp"
    #include "Graphics/ImGuiWrapper.cpp"
    #include "Graphics/Shader.cpp"
    #include "Graphics/Model.cpp"
    #include "Graphics/DebugDraw.cpp"

    // Graphics/ImGui
    #include "External/imgui/imgui.cpp"
    #include "External/imgui/imgui_draw.cpp"
    #include "External/imgui/imgui_tables.cpp"
    #include "External/imgui/imgui_widgets.cpp"
    #include "External/ImGuizmo/ImGuizmo.cpp"

    // Core/Tracy
    #include "Core/TracyHelper.cpp"

#endif
